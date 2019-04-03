#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "simple-mod.h"
#include "simple.h"

#define SIMPLE_COLOR_RED     "\x1b[31m"
#define SIMPLE_COLOR_GREEN   "\x1b[32m"
#define SIMPLE_COLOR_RESET   "\x1b[0m"


static int simple_fd;


// ---------------------------------------------------------------------------
int simplelib_init() 
{
  simple_fd = open(SIMPLEMOD_DEVICE_PATH, O_RDONLY);
  if (simple_fd < 0) 
  {
    fprintf(stderr, SIMPLE_COLOR_RED "[-]" SIMPLE_COLOR_RESET 
            "Error: Could not open simplemod device: %s\n", 
            SIMPLEMOD_DEVICE_PATH);
    return -1;
  }
  return 0;
}


// ---------------------------------------------------------------------------
void simplelib_cleanup() 
{
  if(simple_fd >= 0) 
    close(simple_fd);
}


// ---------------------------------------------------------------------------
int simplelib_hello() 
{
  return (int)ioctl(simple_fd, SIMPLEMOD_IOCTL_HELLO, 0);
}

