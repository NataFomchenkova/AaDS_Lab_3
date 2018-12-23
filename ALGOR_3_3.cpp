// ALGOR_3_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "heap.h"
using namespace std;

int main()
{
	Heap heap;
	int choice;
	int b;
	do
	{
		cout << "enter action" << endl;
		cout << "1 - add element" << endl;
		cout << "2 - remove element" << endl;
		cout << "3 - print" << endl;

		cout << "0 - exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "enter element" << endl;
			cin >> b;
			heap.insert(b);
			break;
		case 2:
			cout << "enter element" << endl;
			cin >> b;
			heap.remove(b);
			break;

		case 3: 
			heap.print_complete();
			cout << endl << endl << endl;
			break;
		
		case 4:
			heap.printf();
			cout << endl << endl << endl;
			break;
		}
		
	} while (choice != 0);
		_getch();

    return 0;
}

