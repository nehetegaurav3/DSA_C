#include <stdio.h>
#include <stdlib.h>

typedef struct Student {

	int id;
	float ht;
	struct Student *next;
}stud;

stud *head = NULL;				//global head

void addNode() {

	stud *newNode = (stud *)malloc(sizeof(stud));
	
	newNode->id = 1;
	newNode->ht = 5.5;
	newNode->next = NULL;

	head = newNode;
}

void printLL() {

	//Printing Data
	stud *temp = head;
	
	while(temp != NULL) {
	
		printf("ID = %d\tHeight = %.2f\n", temp->id, temp->ht);
		temp = temp->next;
	}
}

void main(void) {

	//1st Node
	stud *head = NULL;
	addNode();
	printLL();
}

