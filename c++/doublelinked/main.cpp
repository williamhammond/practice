
#include <iostream>
#include <string.h>
#include "list.h"

using namespace std;


int main() {
	int input;
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

			r.id = id;
			strcpy(r.firstname, first);
			strcpy(r.lastname, last);

			AddItem(r);
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
		else if (input == 0)
		{
			break;
		}
	}
}