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

  struct dirent *cur;
  DIR *dir = opendir(PATH);

  while (cur = readdir(dir)) {
    puts(cur->d_name);
  }

  closedir(dir);
  return 0;
}
