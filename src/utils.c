#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "utils.h"

char * my_strsep(char **stringp, const char *delim) {
  char *s;
  const char *spanp;
  int c, sc;
  char *tok;

  if ((s = *stringp) == NULL)
    return NULL;

  for (tok = s;;) {
    c = *s++;
    spanp = delim;
    do {
      if ((sc = *spanp++) == c) {
        if (c == 0) {
          *stringp = NULL;
          return tok;
        }
        s[-1] = '\0';
        *stringp = s;
        return tok;
      }
    } while (sc != 0);
  }
}

char * separa_string(char **stringp, const char *delim) {
  char * s = my_strsep(stringp, delim);
  return (!s || (s[0] == '\0')) ? NULL : s;
}

void tolower_string(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = tolower(str[i]);
  }
}

int max(int a, int b) {

	return a > b ? a : b;
}