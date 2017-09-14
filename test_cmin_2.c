#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crash() {
	int *x = NULL;
	printf("%d\n", *x);
}

int main() {
	crash();
	return 0;
}