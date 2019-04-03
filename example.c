#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RESET   "\x1b[0m"

#define TAG_OK COLOR_GREEN "[+]" COLOR_RESET " "
#define TAG_FAIL COLOR_RED "[-]" COLOR_RESET " "
#define TAG_PROGRESS COLOR_YELLOW "[~]" COLOR_RESET " "

#include "lib/simplelib.h"

int main(int argc, char *argv[]) 
{
  char mystr[10];
  memset(mystr, 0, 10);
  
  (void)argc;
  (void)argv;

  if(simplelib_init()) 
  {
    printf(TAG_FAIL "Could not initialize simplemod "
                    "(did you load the kernel module?)\n");
    return 1;
  }
  
  int res = simplelib_hello();
  if(res == -1)
  {
    printf(TAG_FAIL "simplelib_hello returned -1\n");
    goto cleanup;
  }
  
  *(int*)mystr = res;
  
  printf(TAG_OK "mystr is %s\n", mystr);
  
cleanup:
  simplelib_cleanup();

  return 0;
}
