#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	struct Node *prev;
	int data;
	struct Node *next;
}Node;

Node *head = NULL;

Node* createNode() {

	Node *newNode = (Node*) malloc(sizeof(Node));
	
	newNode->prev = NULL;

	printf("Enter Data: ");
	scanf("%d", &newNode->data);
		
	newNode->next = NULL;

	return newNode;
}

void addNode() {

	Node *newNode = createNode();
		
	if(head == NULL) {
		
		head = newNode;
	} else {
		
		Node *temp = head;
			
		while(temp->next != NULL) {
			
			temp = temp->next;
		}	
		temp->next = newNode;
		newNode->prev = temp;
	}
}

void addFirst() {

	Node *newNode = createNode();

	if(head == NULL) {
		
		head = newNode;
	} else {
		
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

int countNode() {

	Node *temp = head;
	int count = 0;
		
	while(temp != NULL) {
		
		temp = temp->next;
		count++;
	}

	return count;
}

int addAtPos(int pos) {

	int count = countNode();
		
	if(pos <= 0 || pos >= count+2) {

		printf("Invalid Node Position..!!\n");

		return -1;
	} else {

		if(pos == count+1) {

			addNode();
		} else if(pos == 1) {

			addFirst();
		} else {

			Node *newNode = createNode();

			Node *temp = head;

			while(pos-2) {

				temp = temp->next;
				pos--;
			}

			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next->prev = newNode;
			temp->next = newNode;
		}

		return 0;
	}
}

int deleteFirst() {

	int count = countNode();

	if(head == NULL) {
		
		printf("Nothing to Delete :)\n");
		return -1;
	} else if(count == 1){

		free(head);
		head = NULL;
	} else {
			
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
}

int deleteLast() {

	int count = countNode();

	if(head == NULL) {

		printf("Nothing to Delete :)\n");
		return -1;
	} else{

		if(count == 1) {

			free(head);
			head = NULL;
		} else {
		
			Node *temp = head;
			while(temp->next->next != NULL) {
			
				free(temp->next);
				temp->next = NULL;
			}
		}

		return 0;
	}
}

void deleteAtPos() {


}

int printDLL() {

	if(head == NULL) {
	
		printf("Empty Linked List..!! :)\n");
		return -1;
	} else {

		Node *temp = head;

		while(temp->next != NULL) {
	
			printf("|%d|", temp->data);
			temp = temp->next;
		}
		printf("\n");

		return 0;
	}
}

void main(void) {

	char ch;
	int choice;

	do {
	
		printf("1. addNode\n");
		printf("2. printDLL\n");
		printf("3. addFirst\n");
		printf("4. addAtPos\n");
		printf("5. deleteFirst\n");
		printf("6. deleteLast\n");
		printf("7. deleteAtPos\n");
		printf("Enter Choice: ");
		scanf("%d",&choice);

		switch(choice) {
		
			case 1:
				{
				int countNode;

				printf("Enter Node Count: ");
				scanf("%d", &countNode);

				for(int i = 0; i < countNode; i++) {
	
					addNode();
				}
				}
				break;
			case 2:
				printDLL();
				break;
			case 3:
				addFirst();
				break;
			case 4:
				{
				int pos;
				printf("Enter Node Position: ");
				scanf("%d", &pos);
				addAtPos(pos);
				}
				break;
			case 5:
				deleteFirst();
				break;
			case 6:
				deleteLast();
				break;
			case 7:
				{
				int pos;
				printf("Enter Node Position: ");
				scanf("%d", &pos);
				deleteAtPos(pos);
				}
				break;
			default:
				printf("Wrong Choice..!!");
		}

		getchar();
		printf("Do you want to continue('Y' or 'N'): ");
		scanf("%c", &ch);
	}while(ch == 'Y' || ch == 'y');
	
	exit(0);
}

