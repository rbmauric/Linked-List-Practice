//Ryan Mauricio
//Linked List Implementation
//10/17/19

#include <iostream>
#include "sll.cpp"
#include "dll.cpp"

int main() {
	{ //Testing SLL functions.
		SLL<int> list;
		std::cout << "TESTING SINGLY LINKED LIST FUNCTIONS: \n\n";
		
		std::cout << "Inserting elements... \n";  
		list.addFront(10);
		list.addFront(30);
		list.print();
		list.addFront(40);
		list.print();
		list.insertAt(20, 3);
		list.print();

		std::cout << "Node at position 3: " << list.at(3)->elem << std::endl;
		std::cout << "Node at front: " << list.front()->elem << std::endl;
		std::cout << "Node after node at position 3: " << list.at(3)->next->elem << std::endl;
		
		std::cout << "Removing elements... \n";
		list.removeFront();
		list.print();
		list.removeAt(2);
		list.print();
		
		std::cout << "Size of list: " << list.size() << std::endl;

		std::cout << "Clearing list. " << std::endl;
		list.clear();
		list.print();
		std::cout << std::endl;
	}

	{ //Testing DLL functions.
		DLL<char> dlist;
		std::cout << "TESTING DOUBLY LINKED LIST FUNCTIONS: \n\n";
		
		std::cout << "Inserting elements... \n";
		dlist.addFront('D');
		dlist.addFront('B');
		dlist.print();
		dlist.addFront('A');
		dlist.print();
		dlist.addBack('E');
		dlist.print();
		dlist.insertAt('C', 3);
		dlist.print();

		std::cout << "Node at position 3: " << dlist.at(3)->elem << std::endl;
		std::cout << "Node at front: " << dlist.front()->elem << std::endl;
		std::cout << "Node at back: " << dlist.back()->elem << std::endl;
		std::cout << "Node after node at position 3: " << dlist.at(3)->next->elem << std::endl;
		std::cout << "Node before node at position 3: " << dlist.at(3)->prev->elem << std::endl;

		std::cout << "Removing elements... \n";
		dlist.removeFront();
		dlist.print();
		dlist.removeBack();
		dlist.print();
		dlist.removeAt(2);
		dlist.print();

		std::cout << "Size of list: " << dlist.size() << std::endl;

		std::cout << "Clearing list. " << std::endl;
		dlist.clear();
		dlist.print();
		std::cout << std::endl;
	}

	return 0;
}
