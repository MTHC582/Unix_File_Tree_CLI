#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#define MAX_LEN 4096

/**
 * stores path of compiled/exe file into arg provided.
 * param: char array with size adjusted, eg: char PATH(40XX)
 * returns errno
 * */
int32_t getpwd(char *);

#endif
