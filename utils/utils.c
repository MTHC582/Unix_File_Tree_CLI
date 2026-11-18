#include <stdio.h>
#include <unistd.h>

#include "utils.h"

int32_t getpwd(char *path) {
    // returns path into cur path
  char *buf = getcwd(path, MAX_LEN);
  if (buf == NULL) {
    perror("Failed Loading path var");
    return -1;
  }
  return 0;
}
