#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#define U_MAX_BYTES 4

void usage(char *prog)
{
  fprintf(stderr, "usage: %s \t\tRemove byte order mark at the *BEGINNING* of the UTF-8 input.\n", prog);
  fprintf(stderr, "   or: %s -a\tRemove *ALL* byte order mark of the UTF-8 input.\n", prog);
  exit(1);
}

unsigned short u_getc(FILE *stream, char *bytes) {
  /* mask values for bit pattern of first byte in multi-byte
     UTF-8 sequences:
     192 - 110xxxxx - for U+0080 to U+07FF
     224 - 1110xxxx - for U+0800 to U+FFFF
     240 - 11110xxx - for U+010000 to U+1FFFFF */
  static unsigned short mask[] = {192, 224, 240};

  unsigned short i, j;

  /* initialize buffer */
  memset(bytes, 0, U_MAX_BYTES + 1);

  /* read first byte into buffer */
  bytes[0] = getc(stream);
  if (bytes[0] == EOF) {
    return 0;
  }

  /* check how many more bytes need to be read for
     character */
  i = 0;
  if ((bytes[0] & mask[0]) == mask[0]) i++;
  if ((bytes[0] & mask[1]) == mask[1]) i++;
  if ((bytes[0] & mask[2]) == mask[2]) i++;

  /* read subsequent character bytes */
  j = 0;
  while (j < i) {
    j++;
    bytes[j] = getc(stream);
  }

  /* return number of bytes read into buffer */
  return i + 1;
}

int main(int argc, char *argv[]) {
  int ch;
  int n = 0;
  char *utf8bom = "\xef\xbb\xbf";
  int REMOVE_ALL = 0;

  /* Arguments handling */
  while ((ch = getopt(argc, argv, "a")) != -1)
    switch (ch)
    {
      case 'a':
        REMOVE_ALL = 1;
        break;
      default:
        usage(argv[0]);
    }

  /* allocating +1 for null gives ability to print character
     as string */
  char *bytes = (char*)calloc(U_MAX_BYTES + 1, sizeof(char));

  /* read and print until end of file */
  while (u_getc(stdin, bytes)) {
    if ((REMOVE_ALL == 1) && (strcmp(bytes, utf8bom) == 0))
    {
      continue;
    }
    else if ((n == 0) && (strcmp(bytes, utf8bom) == 0))
    {
      continue;
    }
    else
      printf("%s", bytes);
    /* If we are at the head of the file */
    if (n < 1)
      n++;
  }

  return 0;
}
