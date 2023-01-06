#include <stdio.h>

void fun(int *a) {

	*a = *a + 10;
	printf("%d\n", *a);	//20
}

void main() {

	int x = 10;
	fun(&x);
	printf("%d\n", x);	//20
}

