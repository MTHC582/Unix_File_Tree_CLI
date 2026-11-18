#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#define MAX_LEN 4096

// Define color macros
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define WHITE "\033[38;5;253m"

// Change DIRECTORY & FILE Color from Here...
// Default felt better for files :(
#define CUSTOM_DIR_COLOR YELLOW
#define CUSTOM_FILE_COLOR WHITE

/**
 * stores path of compiled/exe fil into arg provided.
 * param: char array with size adjusted, eg: char PATH(40XX)
 * returns errno
 * */
int32_t getpwd(char *);

#endif
