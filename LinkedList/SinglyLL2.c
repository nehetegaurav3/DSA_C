#include <stdio.h>
#include <stdlib.h>

typedef struct Student {

	int id;
	float ht;
	struct Student *next;
}stud;

stud* addNode(stud *head) {			//return type changed from void to stud*

	stud *newNode = (stud *)malloc(sizeof(stud));
	
	newNode->id = 1;
	newNode->ht = 5.5;
	newNode->next = NULL;

	head = newNode;

	return head;				//Added later
}

void printLL(stud *head) {

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
	head = addNode(head);		//Changed Later (head =) added to catch return type.
	printLL(head);
}

