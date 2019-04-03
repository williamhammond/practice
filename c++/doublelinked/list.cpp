#include <stddef.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "list.h"

using namespace std;

const int INT_MAX=2147483647;

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
	n->prev = curr;
	if (n->next == NULL) {
		tail = n;
	} else {
		curr->next->prev = n;
	}
	curr->next = n;
	return 1;
}

int DeleteItem(char* delid) {
	rec* curr = head;
	rec* prev = NULL;
	// Step over list until we find matching ID or run out
	while (curr != NULL && strcmp(curr->id, delid) != 0) {
		curr = curr->next;
	}
	// No node found with matching ID
	if (curr == NULL) {
		return 0;
	}
	// We're at the head of the list
	if (curr->prev==NULL) {
		head = curr-> next;
		head->prev = NULL;
		delete curr;
		return 1;
	}
	// We're at the end of the list
	if (curr->next==NULL) {
		tail = curr->prev;
		tail->next = NULL;
		delete curr;
		return 1;
	}
	// General case, we point the previous to the next, and the next 
	// to the previous
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

void DeleteAll() {
	if (head == NULL) {
		return;	
	}
	rec* tmp = head;
	head = tmp->next;
	delete tmp;
	DeleteAll();

	head = NULL;
	tail = NULL;
}

int ReadData(char *keyFile, char *answersFile) {
	const int MAXCHARS = 31;
	char keyId[MAXCHARS];
	char answerId[MAXCHARS];
	char ansBuffer[2048] = { '\0' };
	char answers[10] = {'\0'};	//	should be int
	char fName[MAXCHARS];
	char lName[MAXCHARS];
	int countCheck = 0;
	int count = 0;

	DeleteAll();

	ifstream keyFileStream;
	keyFileStream.open(keyFile, ios::in);

	if (keyFileStream.fail())
	{
		cout << "Could not open file!" << endl;
		return 0;
	}

	ifstream answerFileStream;
	answerFileStream.open(answersFile, ios::in);

	if (answerFileStream.fail())
	{
		cout << "Could not open file!" << endl;
		return 0;
	}

	while (keyFileStream >> keyId >> fName >> lName)
	{
			while (answerFileStream >> answerId >> ws )
			{
				cout << "ID1 value: " << keyId << endl;
				cout << "ID2 value: " << answerId << endl;
				if (strcmp(keyId, answerId) == 0)
				{
					answerFileStream.getline(ansBuffer, 30);
					
					for (int i = 0; i < 40; i++)
					{
						cout << ansBuffer[i];
					}
					
					rec newRec = {};
					newRec.id = keyId;
					strcpy(newRec.firstname, fName);
					strcpy(newRec.lastname, lName);
					cout << "success" << endl;
					AddItem(newRec);
					
					break;

				}
				else
				{
					cout << "fail" << endl;
					answerFileStream.ignore(INT_MAX, '\n');
				}

			}
			answerFileStream.clear();	//	reset
			answerFileStream.seekg(0, answerFileStream.beg);	//	reset
	}
	return 1;
}


int WriteData(char* keyFile, char* answerFile) {
	return 0;
}
