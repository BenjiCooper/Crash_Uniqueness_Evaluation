/* Two essentially identical crashes, called under identical control flows.
   Will AFL-CMIN distinguish them?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void crash1() {
	printf("%d\n", *((volatile int *)0));
}

void crash2() {
	printf("%d\n", *((volatile char *) 0));
}

int foo(int x) {
	return x+5;
}

int bar(int x) {
	return 2*x;
}

int main(int argc, char **argv) {
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
  		crash1();
  	} else if (n%3 == 1) {
  		printf("2\n");
  		crash2();
  	} else {
  		printf("success!\n");
  	}
  	return 0;
}


