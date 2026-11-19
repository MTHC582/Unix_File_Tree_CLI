#include <dirent.h>
#include <stdbool.h>
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

void traverse(char *path, _Bool ShowHiddenFiles, uint8_t space) {
  struct dirent *current_dir;
  DIR *dir = opendir(path);

  while (current_dir = readdir(dir)) {
    const char *file_name = current_dir->d_name;
    uint8_t type = current_dir->d_type;

    if (ShowHiddenFiles == false && file_name[0] == '.')
      continue;

    char *spacing = malloc(space + 1);
    memset(spacing, ' ', space), spacing[space] = '\0';

    char new_path[MAX_LEN], suffix[50] = "/";

    if (type == 4) // Points to a Directory
    {
      if (strcmp(file_name, ".") == 0 || strcmp(file_name, "..") == 0)
        continue;

      printf("%s", spacing);
      if (space)
        printf("┗┄");
      printf(CUSTOM_DIR_COLOR "%s" RESET "\n", file_name);

      strcpy(new_path, path);
      strcat(suffix, file_name);
      strcat(new_path, suffix);

      traverse(new_path, ShowHiddenFiles, space + 2);

    } else if (type == 8) // Points to a File
    {
      printf("%s┗┄", spacing);
      printf(CUSTOM_FILE_COLOR "%s" RESET "\n", file_name);
    }

    free(spacing);
  }

  closedir(dir);
};
