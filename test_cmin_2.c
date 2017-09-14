/* Two essentially identical crashes, called under identical control flows.
   Will AFL-CMIN distinguish them?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crash1() {
	int *x = NULL;
	printf("%d\n", *x);
}

void crash2() {
	char *c = NULL;
	printf("%c\n", *c);
}

int foo(int x) {
	return x+5;
}

int bar(int x) {
	return 2*x;
}

int main(int argc, char **argv) {
	int n;

	if (argc != 2) {
		printf("insufficient arguments\n");
		return -1;
	}

	n = argv[1][0] + '0';
	n = foo(n);
	n = bar(n);

	if (n%3 == 0) {
		printf("%d\n", 1);
		crash1();
	} else if (n%3 == 1) {
		printf("%d\n", 2);
		crash2();
	} else {
		printf("success!\n");
	}

	return 0;
}