#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

using namespace std;
#pragma warning(disable:4996)



struct NODE {
	int data;
	struct NODE* next;
};

void addFirst(struct NODE* target, int data) {

	struct NODE* newnode = (struct NODE*)malloc(sizeof(struct NODE));
	newnode->next = target->next;
	newnode->data = data;
	target->next = newnode;
}


int main() {

	struct NODE* head=(struct NODE*)malloc(sizeof(struct NODE));
	
	head->next = NULL;

	addFirst(head, 10);
	addFirst(head, 20);
	addFirst(head, 30);


	struct NODE* curr = head->next;
	
	while (curr != NULL){

		printf("%d\n", curr->data);
		curr = curr->next;
	};

	curr = head->next;
	while (curr != NULL) {
		struct NODE* next = curr->next;
		free(curr);
		curr = next;
	}
	free(head);
	/* 구조체 포인터
	struct NODE a = { 1 };
	struct NODE* a2;
	a2 = &a;
	printf("%d", a2->data);
	*/
}

