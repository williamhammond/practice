#include <stddef.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "list.h"


using namespace std;

const int INT_MAX = 10;

struct rec *head = NULL;	//	base of the node
struct rec *tail = NULL;	//	tail that connects to next node

bool checkDup(rec *n, rec* curr) {
	if (curr == NULL) {	//	node is empty?
		return false;
	}
	//cout << curr->id; 
	if (strcmp(n->id, curr->id) == 0) {	//	if node id's are the same
		cout << "Duplicate ID found!" << endl;
		return true;
	}
	checkDup(n, curr->next);	//	check next node
}

int AddItem(rec r) {
	struct rec* n = new rec;
	n->id = new char[sizeof(r.id)];
	strcpy(n->id, r.id);
	strcpy(n->firstname, r.firstname);
	strcpy(n->lastname, r.lastname);
	for(int j = 0; j < 10; j++) {
		n->answers[j] = r.answers[j];
	}

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
	while (curr->next != NULL && strcmp(curr->next->lastname, n->lastname) < 0) { // curr goes before n
		curr = curr->next;
	}
	n->next = curr->next;
	n->prev = curr;
	if (n->next == NULL) {
		tail = n;
	}
	else {
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
	if (curr->prev == NULL) {
		head = curr->next;
		head->prev = NULL;
		delete curr;
		return 1;
	}
	// We're at the end of the list
	if (curr->next == NULL) {
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
	for (int i=0; i < 10; i++) {
		cout << n->answers[i] << " ";
	}
	cout << " ";
	cout << n << " ";
	cout << n->prev << " ";
	cout << n->next << " " << endl;
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
	char ansBuffer[24] = { '\0' };
	char fName[MAXCHARS];
	char lName[MAXCHARS];
	int countCheck = 0;
	int count = 0;
	int v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;

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
		while (answerFileStream >> answerId >> ws >> v1 >> ws >> v2 >> ws >> v3 >> ws >> v4 >> ws >> v5 >> ws >> v6 >> ws >> v7 >> ws >> v8 >> ws >> v9 >> ws >> v10)
		{
			if (strcmp(keyId, answerId) == 0)
			{
				answerFileStream.getline(ansBuffer, 30);
				rec newRec = {};
				newRec.id = keyId;
				strcpy(newRec.firstname, fName);
				strcpy(newRec.lastname, lName);
				newRec.answers[0] = v1;
				newRec.answers[1] = v2;
				newRec.answers[2] = v3;
				newRec.answers[3] = v4;
				newRec.answers[4] = v5;
				newRec.answers[5] = v6;
				newRec.answers[6] = v7;
				newRec.answers[7] = v8;
				newRec.answers[8] = v9;
				newRec.answers[9] = v10;
				AddItem(newRec);
				break;
			}
			answerFileStream.ignore(INT_MAX, '\n');
		}
		answerFileStream.clear();	//	reset
		answerFileStream.seekg(0, answerFileStream.beg);	//	reset
	}
	return 1;
}

int WriteData(char *keyFile, char *answersFile) {
	rec *curr = head;
	ofstream outFile;
	outFile.open(keyFile, ios::in);

	ofstream outFile2;
	outFile2.open(answersFile, ios::in);

	if (outFile.fail())
	{
		cout << "Could not open file!" << endl;
		return 0;
	}
	else if (outFile2.fail())
	{
		cout << "Could not open file!" << endl;
		return 0;
	}
	else
	{
		while (curr != NULL)	//	key & answers files
		{
			outFile << curr->id << " " << curr->firstname << " " << curr->lastname << endl;
			outFile2 << curr->id << " " << curr->answers << endl;	//	fix answers (a)
			curr = curr->next;
		}
		outFile.close();
		outFile2.close();
	}
	return 0;
}

