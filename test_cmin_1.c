/* Simple code designed to trip up AFL-CMIN. 
   Fails when first character of input is anything with ascii value
   greater than 4. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Use after free. Should segfault */
int crash() {
	char *str1 = malloc(6*sizeof(char));
	char *str2;
	strcpy(str1, "hello");
	free(str1);
	strcpy(str2, str1);
	printf("%s\n", str2);
	return 0;
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

int main(int argc, char **argv) {
	char c;
	int n, x;

	if (argc != 2) {
		printf("insufficient arguments\n");
		return -1;
	}

	c = argv[1][0];
	n = c - '0';

	x = foo(n);
	x = bar(x);
	printf("%d\n", x);

	if (n > 4) {
		crash();
	}
	printf("success!\n");

	return 0;
}