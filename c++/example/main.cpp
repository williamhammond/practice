#include <iostream>
#include<string.h>
#include "list.h"

using namespace std;

int main() {
	int input;
	cout << "What would you like to do? 1 Add Item 2 Delete Item 3 Print List 4 Read From File 5 Write to File 0 Quit" << endl;
	while (true)
	{
		cin >> input;
		if (input == 1)    //    Add Item
		{
			rec r = {};

			char id[2048];
			cout << "Input ID: " << endl;
			cin >> id;

			char first[15];
			cout << "Input first name: " << endl;
			cin >> first;

			char last[15];
			cout << "Input last name: " << endl;
			cin >> last;

			int answers[10];
			cout << "Enter 10 answers" << endl;
			int i = 0;
			while (i < 10) {
				int id;
				cin >> id;
				answers[i] = id;
				i++;
			}

			for(int j = 0; j < 10; j++) {
				r.answers[j] = answers[j];
			}
			r.id = id;
			strcpy(r.firstname, first);
			strcpy(r.lastname, last);

			AddItem(r);
			cout << "Item created" << endl;
		}
		else if (input == 2)    //    Delete Item
		{
			char id[2048];
			cout << "Input ID: " << endl;
			cin >> id;

			DeleteItem(id);
		}
		else if (input == 3)    //    Print List
		{
			cout << "Sort order: " << endl;
			cin >> input;
			PrintList(input);
		}
		else if (input == 4)    //    Read From File
		{
			cout << "Read from File" << endl;
			char keyFile[256];
			cout << "Input Key File Location: " << endl;
			cin >> keyFile;
			char answerFile[256];
			cout << "Input Answer File Location: " << endl;
			cin >> answerFile;
			ReadData(keyFile, answerFile);
		}
		else if (input == 5)    //    Wite to File
		{
			cout << "Write to File" << endl;
		}
		else if (input == 0)
		{
			break;
		}
	}
}



