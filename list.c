/*
 * listing directory using C
 * DATE : 17/11/2026
 * */

#include <dirent.h>
#include <stdint.h>
#include <stdio.h>

#include "utils/utils.h"

static char PATH[MAX_LEN];

int32_t main(int32_t argc, char **argv) {
  getpwd(PATH);

  DIR *dir = opendir(PATH);
  struct dirent *cur = readdir(dir);

  while (cur) {
    puts(cur->d_name);
    cur = readdir(dir);
  }

  closedir(dir);
  return 0;
}
