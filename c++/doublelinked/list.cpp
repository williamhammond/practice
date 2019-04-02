#include <stddef.h>
#include <iostream>
#include <string.h>
#include "list.h"

using namespace std;

struct rec *head = NULL;
struct rec *tail = NULL;

bool checkDup(rec *n, rec* curr) {
	if (curr == NULL) {
		return false;
	}
	if (strcmp(n->id, curr->id) == 0) {
		cout << "Duplicate ID found!" << endl;
		return true;
	}
	checkDup(n, curr->next);
}

int AddItem(rec r) {
	struct rec* n = new rec;
	n->id = new char[sizeof(r.id)];
	strcpy(n->id, r.id);
	strcpy(n->firstname, r.firstname);
	strcpy(n->lastname, r.lastname);

	if (head == NULL) {
		head = n;
		tail = n;
		return 1;
	}
	if (checkDup(n, head)) {
		return 0;
	}
	if (strcmp(head->lastname, n->lastname) > 0) { // element goes in the head
		n->next = head;
		head->prev = n;
		head = n;
		return 1;
	}

	rec* curr = head;
	while(curr->next != NULL && strcmp(curr->next->lastname, n->lastname) < 0) { // curr goes before n
		curr = curr->next;
	}
	n->next = curr->next;
	if (n->next == NULL) {
		tail = n;
	}
	n->prev = curr;
	curr->next = n;
	return 1;
}

int DeleteItem(char* delid) {
	rec* curr = head;
	rec* prev = NULL;
	while (curr != NULL && strcmp(curr->id, delid) != 0) {
		curr = curr->next;
	}
	if (curr == NULL) {
		return 0;
	}
	if (curr->next==NULL) {
		tail = curr->prev;
		delete curr;
		return 1;
	}
	if (curr->prev==NULL) {
		head = curr-> next;
		delete curr;
		return 1;
	}
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	delete curr;
	return 1;
}

void PrintNode(rec* n) {
	cout << n->id << " ";
	cout << n->firstname << " ";
	cout << n->lastname << " ";
	cout << n << " ";
	cout << n->prev << " " ;
	cout << n->next<< " " << endl;
}

void PrintList(int order) {
	rec *curr = new rec;
	if (order == 0)
	{
		curr = head;
		while (curr != NULL)
		{
			PrintNode(curr);
			curr = curr->next;
		}
	}
	else if (order == 1)
	{
		curr = tail;
		while (curr != NULL)
		{
			PrintNode(curr);
			curr = curr->prev;
		}
	}
}

int ReadData(char* keyFile, char* answerFile) {
	return 0;
}

int WriteData(char* keyFile, char* answerFile) {
	return 0;
}