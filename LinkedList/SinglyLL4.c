#include <stdio.h>
#include <stdlib.h>

typedef struct Movie {

	char mName[20];
	float imdb;
	struct Movie *next;
}Mov;

Mov *head = NULL;					//global head

void addNode() {

	Mov *newNode = (Mov *)malloc(sizeof(Mov));
	
	printf("Enter movie name:\n");
	fgets(newNode->mName, 15, stdin);

	printf("Enter IMDB rating:\n");
	scanf("%f", &newNode->imdb);
	getchar();					//To eat up \n in buffer for fgets given by scanf function
	
	newNode->next = NULL;

	if(head == NULL) {

		head = newNode;
	} else {
	
		Mov *temp = head;
		while(temp->next != NULL) {
		
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void printLL() {

	//Printing Data
	Mov *temp = head;
	
	while(temp != NULL) {
	
		printf("|MovieName = %s\tIMDB Rating = %.2f|", temp->mName, temp->imdb);
		temp = temp->next;
	}
}

void main(void) {

	addNode();
	addNode();
	addNode();
	addNode();
	printLL();
}

