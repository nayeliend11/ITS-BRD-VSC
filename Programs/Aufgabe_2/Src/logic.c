#include "logic.h"


#define NULL 0

/**
 * @file logic.c
 * @brief Logic Module - Phase detection and calculations
 * 
 * ============================================================
 * THE TRANSITION TABLE
 * ============================================================
 * 
 * Phases on a circle:
 *            A (0)
 *           /     \
 *      D (2)       B (1)
 *           \     /
 *            C (3)
 * 
 * FORWARD:  A → B → C → D → A
 * BACKWARD: A → D → C → B → A
 * 
 * ============================================================
 */


#include "input.h"
#include "errors.h"
#include "stm32f429xx.h"
#include <stdbool.h>

/*
 * TIMER CONFIGURATION
 * 
 * From assignment: 90 ticks = 1 microsecond
 * ITS Board uses TIM2 as free-running counter
 */
#define TICKS_PER_MICROSECOND   90UL
#define TICKS_PER_MILLISECOND   (TICKS_PER_MICROSECOND * 1000UL)
#define TICKS_PER_SECOND        (TICKS_PER_MICROSECOND * 1000000UL)

#define MIN_UPDATE_TICKS        (250UL * TICKS_PER_MILLISECOND)
#define MAX_UPDATE_TICKS        (500UL * TICKS_PER_MILLISECOND)


/*
 * TRANSITION TABLE
 * 
 * Maps [old_phase][new_phase] to transition result
 * 
 * Phase values from input.h:
 *   PHASE_A = 0x00 = 0
 *   PHASE_B = 0x01 = 1
 *   PHASE_D = 0x02 = 2
 *   PHASE_C = 0x03 = 3
 * 
 * Forward sequence:  A(0) → B(1) → C(3) → D(2) → A(0)
 * Backward sequence: A(0) → D(2) → C(3) → B(1) → A(0)
 */
static const TransitionResult_t transition_table[4][4] = {
    /*               NEW:  A(0)           B(1)            D(2)            C(3)        */
    /* OLD = A(0) */ { RESULT_NO_CHANGE, RESULT_FORWARD,  RESULT_BACKWARD, RESULT_ERROR    },
    /* OLD = B(1) */ { RESULT_BACKWARD,  RESULT_NO_CHANGE, RESULT_ERROR,    RESULT_FORWARD  },
    /* OLD = D(2) */ { RESULT_FORWARD,   RESULT_ERROR,    RESULT_NO_CHANGE, RESULT_BACKWARD },
    /* OLD = C(3) */ { RESULT_ERROR,     RESULT_BACKWARD, RESULT_FORWARD,  RESULT_NO_CHANGE }
};


/*
 * MODULE STATE
 */
static phase_t previous_phase;
static int32_t step_count;
static Direction_t last_direction;
static uint32_t window_start_time;
static int32_t window_start_steps;
static double angular_velocity;
static bool phase_changed_in_window;


/*
 * TIMER FUNCTIONS
 */

/**
 * @brief Get current timer value from TIM2
 */
static uint32_t get_timer(void)
{
    return TIM2->CNT;
}

/**
 * @brief Calculate elapsed ticks (handles overflow)
 */
static uint32_t elapsed_since(uint32_t start_time)
{
    return get_timer() - start_time;
}


/*
 * PUBLIC FUNCTIONS
 */

/**
 * @brief Initialize logic module
 */
int logic_init(void)
{
    /* Read initial phase */
    previous_phase = input_read_phase();
    
    /* Reset state */
    step_count = 0;
    last_direction = DIR_NONE;
    angular_velocity = 0.0;
    
    /* Start timing window */
    window_start_time = get_timer();
    window_start_steps = 0;
    phase_changed_in_window = false;
    
    return EOK;
}


/**
 * @brief Process one encoder reading
 */
int logic_process(TransitionResult_t *result)
{
    phase_t current_phase;
    TransitionResult_t transition;
    
    /* Read current phase */
    current_phase = input_read_phase();
    
    /* Look up transition in table */
    transition = transition_table[previous_phase][current_phase];
    
    /* Update state based on result */
    switch (transition) {
        case RESULT_FORWARD:
            step_count++;
            last_direction = DIR_FORWARD;
            phase_changed_in_window = true;
            break;
            
        case RESULT_BACKWARD:
            step_count--;
            last_direction = DIR_BACKWARD;
            phase_changed_in_window = true;
            break;
            
        case RESULT_ERROR:
            error_set(ERROR_PHASE_SKIP);
            break;
            
        case RESULT_NO_CHANGE:
        default:
            break;
    }
    
    /* Remember phase for next time */
    previous_phase = current_phase;
    
    if (result != NULL) {
        *result = transition;
    }
    
    return EOK;
}


/**
 * @brief Get step count as 8-bit for LEDs
 */
uint8_t logic_get_step_count_8bit(void)
{
    int32_t abs_count = (step_count >= 0) ? step_count : -step_count;
    return (uint8_t)(abs_count & 0xFF);
}


/**
 * @brief Get full step count
 */
int32_t logic_get_step_count(void)
{
    return step_count;
}


/**
 * @brief Get angle in degrees
 */
double logic_get_angle(void)
{
    return (double)step_count * DEGREES_PER_PHASE;
}


/**
 * @brief Get angular velocity
 */
double logic_get_angular_velocity(void)
{
    return angular_velocity;
}


/**
 * @brief Get last direction
 */
Direction_t logic_get_direction(void)
{
    return last_direction;
}


/**
 * @brief Check if display should update
 */
bool logic_should_update_display(void)
{
    uint32_t elapsed;
    double elapsed_seconds;
    int32_t steps_in_window;
    
    elapsed = elapsed_since(window_start_time);
    
    /* Check if 500ms passed (maximum wait) */
    if (elapsed >= MAX_UPDATE_TICKS) {
        goto do_update;
    }
    
    /* Check if 250ms passed AND phase changed */
    if (elapsed >= MIN_UPDATE_TICKS && phase_changed_in_window) {
        goto do_update;
    }
    
    return false;
    
do_update:
    /* Calculate velocity */
    elapsed_seconds = (double)elapsed / (double)TICKS_PER_SECOND;
    steps_in_window = step_count - window_start_steps;
    
    if (elapsed_seconds > 0.0001) {
        angular_velocity = (double)steps_in_window * DEGREES_PER_PHASE / elapsed_seconds;
    } else {
        angular_velocity = 0.0;
    }
    
    /* Start new window */
    window_start_time = get_timer();
    window_start_steps = step_count;
    phase_changed_in_window = false;
    
    return true;
}


/**
 * @brief Get complete status structure
 */
Status logic_get_status(void)
{
    Status status;
    
    status.vorwaerts = (last_direction == DIR_FORWARD);
    status.anzahl_phasenwechsel = (short)(step_count & 0xFFFF);
    status.drehgeschwindigkeit = angular_velocity;
    status.winkel = logic_get_angle();
    
    return status;
}
