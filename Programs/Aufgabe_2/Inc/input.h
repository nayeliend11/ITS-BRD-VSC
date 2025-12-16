#ifndef INPUT_H
#define INPUT_H
#include "stdbool.h"

/*typedef enum {
    // Kanal A low, Kanal B low 
    PHASE_A = 0x00,
    // Kanal A high, Kanal B low 
    PHASE_B = 0x02,
    // Kanal A high, Kanal B high 
    PHASE_C = 0x03,
    // Kanal A low, Kanal B high 
    PHASE_D = 0x01
}phase_t;
#endif

bool input_A();
bool input_B();

void pins_aktualisieren();*/

#include "stdbool.h"

/**
 * Phase enumeration
 * 
 * IMPORTANT: The phases are based on (B << 1) | A pattern:
 * 
 * | Channel A | Channel B | Binary (BA) | Phase |
 * |-----------|-----------|-------------|-------|
 * |     0     |     0     |     00      |   A   |
 * |     1     |     0     |     01      |   B   |
 * |     0     |     1     |     10      |   D   |
 * |     1     |     1     |     11      |   C   |
 */
typedef enum {
    PHASE_A = 0x00,    /* A=0, B=0 → Binary: 00 */
    PHASE_B = 0x01,    /* A=1, B=0 → Binary: 01 */
    PHASE_D = 0x02,    /* A=0, B=1 → Binary: 10 */
    PHASE_C = 0x03     /* A=1, B=1 → Binary: 11 */
} phase_t;

/**
 * @brief Read Channel A value
 * @return true if HIGH, false if LOW
 */
bool input_A(void);

/**
 * @brief Read Channel B value
 * @return true if HIGH, false if LOW
 */
bool input_B(void);

/**
 * @brief Update pin readings
 */
void pins_aktualisieren(void);

/**
 * @brief Initialize input module
 * @return EOK on success
 */
int input_init(void);

/**
 * @brief Read current phase from encoder
 * @return Current phase (PHASE_A, PHASE_B, PHASE_C, or PHASE_D)
 */
phase_t input_read_phase(void);

#endif /* INPUT_H */
