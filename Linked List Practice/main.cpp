//Ryan Mauricio
//EPP Practice
//10/17/19

#include <iostream>
#include "sll.cpp"
#include "dll.cpp"
using namespace std;

int main() {
	{ //Testing SLL functions.
		SLL<int> list;
		cout << "TESTING SINGLY LINKED LIST FUNCTIONS: \n\n";
		
		cout << "Inserting elements... \n";  
		list.addFront(10);
		list.addFront(30);
		list.print();
		list.addFront(40);
		list.print();
		list.insertAt(20, 3);
		list.print();

		cout << "Node at position 3: " << list.at(3)->elem << endl;
		cout << "Node at front: " << list.front()->elem << endl;
		cout << "Node after node at position 3: " << list.at(3)->next->elem << endl;
		
		cout << "Removing elements... \n";
		list.removeFront();
		list.print();
		list.removeAt(2);
		list.print();
		
		cout << "Size of list: " << list.size() << endl;

		cout << "Clearing list. " << endl;
		list.clear();
		list.print();
		cout << endl;
	}

	{ //Testing DLL functions.
		DLL<char> dlist;
		cout << "TESTING DOUBLY LINKED LIST FUNCTIONS: \n\n";
		
		cout << "Inserting elements... \n";
		dlist.addFront('D');
		dlist.addFront('B');
		dlist.print();
		dlist.addFront('A');
		dlist.print();
		dlist.addBack('E');
		dlist.print();
		dlist.insertAt('C', 3);
		dlist.print();

		cout << "Node at position 3: " << dlist.at(3)->elem << endl;
		cout << "Node at front: " << dlist.front()->elem << endl;
		cout << "Node at back: " << dlist.back()->elem << endl;
		cout << "Node after node at position 3: " << dlist.at(3)->next->elem << endl;
		cout << "Node before node at position 3: " << dlist.at(3)->prev->elem << endl;

		cout << "Removing elements... \n";
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
		cout << endl;
	}

	return 0;
}
