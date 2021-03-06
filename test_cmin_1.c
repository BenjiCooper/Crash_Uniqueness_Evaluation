/* Simple code designed to trip up AFL-CMIN.
   Fails when first character of input is anything with ascii value
   greater than 4. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Use after free. Should segfault */
void crash() {
  printf("%d\n", *((volatile int *)0));
}

int foo(int a) {
  if (a > 5) {
    return (a%5);
  } else {
    return 5*a;
  }
}

int bar(int a) {
  if (a <= 0) {
    return a*a;
  }
  else if (a > 0 && a <= 5) {
    return 3*a;
  } else {
    return 2*a;
  }
}


/* Run some stuff, and then crash regardless of calls to foo and bar */
int main(int argc, char **argv) {
  char c;
  int n, x;

  if (argc != 2) {
    printf("insufficient arguments\n");
    return 1;
  }

  int fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    return 1;

  int r = read(fd, &c, 1);
  close(fd);

  if (r != 1)
    return 1;

  n = c - '0';

  x = foo(n);
  x = bar(x);

  if (n > 4) {
    crash();
  }
  printf("success!\n");

  return 0;
}
