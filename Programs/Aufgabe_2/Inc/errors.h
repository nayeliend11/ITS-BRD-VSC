#ifndef ERRORS_H
#define ERRORS_H


/*#define EOK 0

int error_handler(int errorCode);


#endif*/

#include <stdbool.h>

/*
 * ERROR CODES
 */
#define EOK                 0    /* No error */
#define ERROR_PHASE_SKIP    1    /* Encoder phase skipped */
#define ERROR_GPIO          2    /* GPIO error */
#define PIN_OUT_OF_RANGE    3

/**
 * @brief Initialize error module
 * @return EOK on success
 */
int error_init(void);

/**
 * @brief Set an error (turns on LED D21)
 * @param errorCode The error code
 */
void error_set(int errorCode);

/**
 * @brief Clear the error (turns off LED D21)
 */
void error_clear(void);

/**
 * @brief Check if error is active
 * @return true if error, false if OK
 */
bool error_is_active(void);

/**
 * @brief Update error state - check button S6
 * Call this every loop iteration!
 * @return EOK on success
 */
int error_update(void);

/**
 * @brief Legacy error handler
 */
int error_handler(int errorCode);

#endif /* ERRORS_H */

