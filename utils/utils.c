#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void traverse(char *path, uint8_t space) {
  struct dirent *current_dir;
  DIR *dir = opendir(path);

  while (current_dir = readdir(dir)) {
    const char *file_name;

    file_name = current_dir->d_name;
    int type = current_dir->d_type;

    char *spacing = malloc(space + 1);
    memset(spacing, ' ', space), spacing[space] = '\0';

    if (type == 4) // Points to a Director
    {
      printf(spacing, "--" CUSTOM_DIR_COLOR "%s" RESET "\n", file_name);
      traverse(path, space + 1);
    } else if (type == 8) // Points to a File
    {
      printf("--" CUSTOM_FILE_COLOR "%s" RESET "\n", file_name);
    }

    current_dir = readdir(dir);
  }

  closedir(dir);
};
