#include <stdio.h>
#include <stdlib.h>

typedef struct Student {

	int id;
	float ht;
	struct Student *next;
}stud;

void main(void) {

	//1st Node
	stud *head = NULL;
	stud *newNode = (stud *)malloc(sizeof(stud));
	
	newNode->id = 1;
	newNode->ht = 5.5;
	newNode->next = NULL;

	head = newNode;

	//2nd Node
	newNode = (stud *)malloc(sizeof(stud));
	newNode->id = 2;
	newNode->ht = 6.0;
	newNode->next = NULL;
	
	head->next = newNode;

	//3rd Node
	newNode = (stud *)malloc(sizeof(stud));
	newNode->id = 3;
	newNode->ht = 6.5;
	newNode->next = NULL;

	head->next->next = newNode;

	//Printing Data
	stud *temp = head;
	
	while(temp != NULL) {
	
		printf("ID = %d\tHeight = %.2f\n", temp->id, temp->ht);
		temp = temp->next;
	}
}

