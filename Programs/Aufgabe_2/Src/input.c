/**
 * @file input.c
 * @brief Input Module - Reads encoder signals from IN0 (PF0) and IN1 (PF1)
 * 
 * ============================================================
 * HARDWARE CONNECTIONS:
 * ============================================================
 * IN0 (PF0) = Channel A
 * IN1 (PF1) = Channel B
 * 
 * PHASE TABLE:
 * | Channel A | Channel B | Phase |
 * |-----------|-----------|-------|
 * |     0     |     0     |   A   |
 * |     1     |     0     |   B   |
 * |     1     |     1     |   C   |
 * |     0     |     1     |   D   |
 * 
 * ============================================================
 */

#include "input.h"
#include "gpio.h"
#include "errors.h"
#include "stm32f429xx.h"

/*
 * PIN DEFINITIONS
 */
#define CHANNEL_A_PIN   0    /* IN0 = PF0 */
#define CHANNEL_B_PIN   1    /* IN1 = PF1 */
#define ENCODER_PORT    GPIOF

/*
 * MODULE STATE
 */
static bool current_A = false;
static bool current_B = false;

/*
 * PHASE LOOKUP TABLE
 * 
 * Index = (B << 1) | A
 * 
 * Index 0 (B=0, A=0) → PHASE_A
 * Index 1 (B=0, A=1) → PHASE_B
 * Index 2 (B=1, A=0) → PHASE_D
 * Index 3 (B=1, A=1) → PHASE_C
 */
static const phase_t phase_lookup[4] = {
    PHASE_A,    /* Index 0: A=0, B=0 */
    PHASE_B,    /* Index 1: A=1, B=0 */
    PHASE_D,    /* Index 2: A=0, B=1 */
    PHASE_C     /* Index 3: A=1, B=1 */
};


/**
 * @brief Initialize input module
 */
int input_init(void)
{
    /* GPIO should be configured by initITSboard() */
    current_A = false;
    current_B = false;
    return EOK;
}


/**
 * @brief Update pin readings from hardware
 * 
 * NOTE: Your gpio.c has inverted logic!
 * readGpioPin returns 1 when pin is LOW, 0 when HIGH.
 * We invert here to get correct values.
 */
void pins_aktualisieren(void)
{
    int raw_a, raw_b;
    
    readGpioPin(ENCODER_PORT, CHANNEL_A_PIN, &raw_a);
    readGpioPin(ENCODER_PORT, CHANNEL_B_PIN, &raw_b);
    
    /* Invert because gpio.c has != instead of == */
    current_A = (raw_a == 0);
    current_B = (raw_b == 0);
}


/**
 * @brief Read Channel A
 */
bool input_A(void)
{
    return current_A;
}


/**
 * @brief Read Channel B
 */
bool input_B(void)
{
    return current_B;
}


/**
 * @brief Read current phase from encoder
 */
phase_t input_read_phase(void)
{
    int index;
    
    /* First update the pin values */
    pins_aktualisieren();
    
    /* Calculate index: (B << 1) | A */
    index = (current_B ? 2 : 0) | (current_A ? 1 : 0);
    
    return phase_lookup[index];
}
