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
  struct dirent *current_dir = readdir(dir);

  while (current_dir != NULL) {
    const char *file_name;

    file_name = current_dir->d_name;
    int type = current_dir->d_type;

    if (type == 4) // Points to a Directory
      printf(CUSTOM_DIR_COLOR "%s" RESET "\n", file_name);
    else if (type == 8) // Points to a File
      printf(CUSTOM_FILE_COLOR "%s" RESET "\n", file_name);

    current_dir = readdir(dir);
  }

  closedir(dir);
  return 0;
}
