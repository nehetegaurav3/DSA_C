#include <stdio.h>
#include <stdlib.h>

struct Demo {

	int data;
	struct Demo *next;
};

struct Demo *head = NULL;

struct Demo* createNode() {

	struct Demo* newNode = (struct Demo*) malloc(sizeof(struct Demo));
	printf("Enter Data: ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;

	return newNode;
}

void addNode() {

	struct Demo *newNode = createNode();

	if(head == NULL) {
	
		head = newNode;
	} else {
	
		struct Demo *temp = head;

		while(temp->next != NULL) {
		
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void addFirst() {

	struct Demo *newNode = createNode();

	if(head == NULL) {
	
		head = newNode;
	} else {
	
		newNode->next = head;
		head = newNode;
	}
}

void addAtPos(int pos) {

	struct Demo *newNode = createNode();

	struct Demo *temp = head;

	while(pos-2) {
	
		temp = temp->next;
		pos--;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

void printLL() {

	struct Demo *temp = head;

	while(temp != NULL) {
	
		printf("|%d|", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void main(void) {

	int countNode;

	printf("Enter no. of node to add: ");
	scanf("%d",&countNode);

	for(int i = 1; i <= countNode; i++) {

		addNode();
	}

	printLL();

	addFirst();

	printLL();

	int pos;
	printf("Enter position to add Node: ");
	scanf("%d",&pos);
	addAtPos(pos);

	printLL();
}

