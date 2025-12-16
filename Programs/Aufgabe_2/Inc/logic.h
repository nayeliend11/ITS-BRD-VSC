#ifndef LOGIC_H
#define LOGIC_H

/*#include "stdbool.h"

typedef struct Status Status;
struct Status{
    bool vorwärts;
    short anzahl_phasenwechsel;
    double drehgeschwindigkeit;
    double winkel;
};

#endif
//eof*/

#include "stdbool.h"
#include "input.h"
#include <stdint.h>

/*
 * CONSTANTS
 * 300 slots × 4 phases = 1200 phases per revolution
 * 360° / 1200 = 0.3° per phase
 */
#define ENCODER_SLOTS           300
#define PHASES_PER_SLOT         4
#define PHASES_PER_REVOLUTION   1200
#define DEGREES_PER_PHASE       0.3

/**
 * Status structure (as defined by partner)
 */
typedef struct Status Status;
struct Status {
    bool vorwaerts;              /* true = forward, false = backward */
    short anzahl_phasenwechsel;  /* Number of phase changes */
    double drehgeschwindigkeit;  /* Angular velocity (deg/sec) */
    double winkel;               /* Angle in degrees */
};

/**
 * Direction enumeration
 */
typedef enum {
    DIR_NONE = 0,
    DIR_FORWARD = 1,
    DIR_BACKWARD = -1
} Direction_t;

/**
 * Transition result
 */
typedef enum {
    RESULT_NO_CHANGE,
    RESULT_FORWARD,
    RESULT_BACKWARD,
    RESULT_ERROR
} TransitionResult_t;

/**
 * @brief Initialize logic module
 * @return EOK on success
 */
int logic_init(void);

/**
 * @brief Process one encoder reading
 * @param result Pointer to store transition result
 * @return EOK on success
 */
int logic_process(TransitionResult_t *result);

/**
 * @brief Get step count (8-bit for LEDs D8-D15)
 * @return Lower 8 bits of step count
 */
uint8_t logic_get_step_count_8bit(void);

/**
 * @brief Get full step count
 * @return Signed step count
 */
int32_t logic_get_step_count(void);

/**
 * @brief Get angle in degrees
 * @return Angle as double
 */
double logic_get_angle(void);

/**
 * @brief Get angular velocity in degrees/second
 * @return Velocity as double
 */
double logic_get_angular_velocity(void);

/**
 * @brief Get last direction
 * @return DIR_FORWARD, DIR_BACKWARD, or DIR_NONE
 */
Direction_t logic_get_direction(void);

/**
 * @brief Check if display should update (every 250-500ms)
 * @return true if should update
 */
bool logic_should_update_display(void);

/**
 * @brief Get complete status structure
 * @return Status struct with all values
 */
Status logic_get_status(void);

#endif /* LOGIC_H */
