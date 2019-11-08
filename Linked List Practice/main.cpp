//Ryan Mauricio
//EPP Practice
//10/17/19

#include <iostream>
#include "sll.cpp"
#include "dll.cpp"
using namespace std;

int main() {
	{
		SLL<int> list;
		list.addFront(10);
		list.addFront(20);
		list.print();

		list.addFront(40);
		list.print();

		list.insertAt(30, 3);
		list.print();

		list.removeFront();
		list.print();

		list.removeAt(2);
		list.print();
		
		cout << "Size of list: " << list.size() << endl;

		cout << "Clearing list. " << endl;
		list.clear();
		
		list.print();
	}

	{
		DLL<char> dlist;
		dlist.addFront('A');
		dlist.addFront('B');
		dlist.print();
		
		dlist.addFront('C');
		dlist.print();

		dlist.addBack('D');
		dlist.print();

		dlist.insertAt('E', 3);
		dlist.print();

		dlist.removeFront();
		dlist.print();

		dlist.removeBack();
		dlist.print();

		dlist.removeAt(2);
		dlist.print();

		cout << "Size of list: " << dlist.size() << endl;

		cout << "Clearing list. " << endl;
		dlist.clear();

		dlist.print();
	}
	return 0;
}
