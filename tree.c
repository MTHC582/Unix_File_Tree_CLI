/*
 * Listing whole directory tree
 * DATE: 18/11/2026
 * */

#include <stdint.h>

#include "utils/utils.h"

static char PATH[MAX_LEN];

int32_t main(int32_t argc, char **argv) {
  getpwd(PATH);
  traverse(PATH, true, 0);
  return 0;
}
