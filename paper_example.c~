#include <stdio.h>

void crash()
{
  printf("%d\n", *((volatile int *)0));
}

int main(int argc, char **args)
{
  char c;
  int n, x;

  if (argc != 2) {
    printf("incorrect number of arguments!\n");
    return 1;
  }
  
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    return 1;

  int r = read(fd, &c, 1);
  close(fd);

  if (r!=1)
    return 1;

  n = c-'0';
  n = foo(n);
  n = bar(n);
  if (n%3 == 0) {
    printf("1\n");
    crash();
  } else if (n%3 == 1) {
    printf("2\n");
    crash();
  } else {
    printf("success!\n");
  }
  return 0;

}
