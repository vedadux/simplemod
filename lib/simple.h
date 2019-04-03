#ifndef _SIMPLELIB_H_
#define _SIMPLELIB_H_

#include "simple-mod.h"
#include <sys/types.h>

/**
 * Initializes (and acquires) simplemod kernel module
 *
 * @return 0  Initialization was successful
 * @return -1 Initialization failed
 */
int simplelib_init();

/**
 * Releases simplemod kernel module
 *
 */
void simplelib_cleanup();

/**
 * Releases PTEditor kernel module
 * @return 'oleh' on success
 * @return -1     on failure
 */
int simplelib_hello();

#endif

