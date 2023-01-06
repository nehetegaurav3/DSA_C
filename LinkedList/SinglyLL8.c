#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {

	char name[20];
	int id;
	struct Employee *next;
}Emp;

Emp *head = NULL;

Emp* createNode() {

	Emp *newNode = (Emp *) malloc(sizeof(Emp));

	getchar();
	printf("Enter Employee Name: ");
	char ch;
	int i = 0;

	while((ch = getchar()) != '\n') {
	
		(*newNode).name[i] = ch;
		i++;
	}

	printf("Enter ID: ");
	scanf("%d", &newNode->id);

	newNode->next = NULL;

	return newNode;
}

void addNode() {

	Emp* newNode = createNode();
	if(head == NULL) {
	
		head = newNode;
	} else {
	
		Emp *temp = head;

		while(temp->next != NULL) {
		
			temp = temp->next;
		}

		temp->next = newNode;
	}
}

void printLL() {

	Emp *temp = head;

	while(temp != NULL) {
	
		printf("|%s->", temp->name);
		printf("%d", temp->id);
	
		temp = temp->next;
	}

	printf("|\n");
}

void countNode() {

	Emp *temp = head;
	int count = 0;

	while(temp != NULL) {
	
		count++;
		temp = temp->next;
	}

	printf("Count = %d\n", count);
}

void addFirst() {

	Emp* newNode = createNode();
	if(head == NULL) {
	
		head = newNode;
	} else {
		
		newNode->next = head;
		head = newNode;
	}
}

void addPosition() {

	int pos;
	printf("Enter Position: ");
	scanf("%d",&pos);
	
	Emp* newNode = createNode();
	Emp* temp = head;

	while(pos - 2) {
		
		temp = temp->next;
		pos--;
	}

	newNode->next = temp->next;
	temp->next = newNode;
}

void main() {

	int nodeCount;

	printf("Enter Node Count: ");
	scanf("%d", &nodeCount);

	for(int i = 1; i <= nodeCount; i++) {
	
		addNode();
	}

	printLL();
	countNode();

	addPosition();
	printLL();
	countNode();
}

