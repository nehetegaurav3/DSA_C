#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Company {
	
	char cName[20];
	int empCount;
	float revenue;
};

void main(void) {

	struct Company *cptr = (struct Company *) malloc(sizeof(struct Company));

	strcpy(cptr->cName, "Veritas");
	cptr->empCount = 700;
	(*cptr).revenue = 150.50;

	printf("Company Name = %s\n", cptr->cName);
	printf("Employee Count = %d\n", cptr->empCount);
	printf("Company Revenue = %f\n", cptr->revenue);
}

