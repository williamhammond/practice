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
	rec* tmp = head;
	rec* prev = NULL;
	rec* nxt = NULL;

	while (tmp != NULL && strcmp(tmp->id, delid) != 0) {
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		return 0;
	}
	else if (prev == NULL) {
		nxt = tmp->next;
		head = nxt;
		delete tmp;
		return 1;
	}
	else {
		nxt = tmp->next;
		prev->next = nxt;
		delete tmp;
		return 1;
	}
	return 0;
}

void reverseList(rec *head)
{
	if (head == NULL) {
		return;
	}
	reverseList(head->next);
	cout << head->id << " ";
	cout << head->firstname << " ";
	cout << head->lastname << " ";
	cout << head << " ";
	cout << head->prev << " " ;
	cout << head->next<< " " << endl;

}

void PrintList(int order) {
	rec *curr = new rec;
	curr = head;
	if (order == 0)
	{
		while (curr != NULL)
		{
			cout << curr->id << " ";
			cout << curr->firstname << " ";
			cout << curr->lastname << " ";
			cout << curr << " ";
			cout << curr->prev << " " ;
			cout << curr->next<< " " << endl;
			curr = curr->next;
		}
	}
	else if (order == 1)
	{
		reverseList(curr);
	}
}

int ReadData(char* keyFile, char* answerFile) {
	return 0;
}

int WriteData(char* keyFile, char* answerFile) {
	return 0;
}