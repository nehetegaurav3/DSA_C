#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {

	char name[20];
	int id;
	struct Employee *next;
}Emp;

Emp *head = NULL;

void addNode() {

	Emp *newNode = (Emp *) malloc(sizeof(Emp));

	getchar();
	printf("Enter Employee Name: ");
	//fgets(newNode->name, 20, stdin);	//Takes \n as input as well
	//gets(newNode->name);			//Works well but is a dangerous function that extends buffer limit.
	
	char ch;
	int i = 0;

	while((ch = getchar()) != '\n') {
	
		(*newNode).name[i] = ch;		// -> works internally as (* ).
		i++;
	}

	printf("Enter ID: ");
	scanf("%d", &newNode->id);

	newNode->next = NULL;

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

	while(temp!=NULL) {
	
		printf("|%s->", temp->name);
		printf("%d", temp->id);
	
		temp = temp->next;
	}

	printf("|\n");
}

void main() {

	int nodeCount;

	printf("Enter Node Count: ");
	scanf("%d", &nodeCount);

	for(int i = 1; i <= nodeCount; i++) {
	
		addNode();
	}

	printLL();
}

