/*
 * listing directory using C
 * DATE : 17/11/2026
 * */

#include <dirent.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

// #define int int32_t
#define MAX_LEN 4096

char PATH[MAX_LEN];
char *buf;

int32_t main(int32_t argc, char **argv) {
  buf = getcwd(PATH, MAX_LEN);
  if (buf == NULL) {
    return -1;
  }

  struct dirent *cur;
  DIR *dir = opendir(PATH);

  while (cur = readdir(dir)) {
    puts(cur->d_name);
  }

  closedir(dir);
  return 0;
}
