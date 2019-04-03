/* See LICENSE file for license and copyright information */

#ifndef SIMPLEMOD_MODULE_H
#define SIMPLEMOD_MODULE_H

#include <stddef.h>

#define SIMPLEMOD_DEVICE_NAME "simplemod"
#define SIMPLEMOD_DEVICE_PATH "/dev/" SIMPLEMOD_DEVICE_NAME

#define SIMPLEMOD_IOCTL_MAGIC_NUMBER (long)0x4242

#define SIMPLEMOD_IOCTL_HELLO \
  _IOR(SIMPLEMOD_IOCTL_MAGIC_NUMBER, 1, size_t)
  
#endif // SIMPLEMOD_MODULE_H
