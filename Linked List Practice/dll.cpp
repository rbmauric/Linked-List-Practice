#include "dll.h"

template <typename T>
DLL<T>::DLL() { //Default constructor for DLL, set both pointers to null.
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void DLL<T>::addFront(T elem) { //Add to the front of the DLL.
	if (head == nullptr) { //If empty, newNode is both head and tail.
		DNode<T>* newNode = new DNode<T>(elem);
		head = newNode;
		tail = newNode;
	}
	else { //If not empty, set pointers to correct nodes and set the new tail.
		DNode<T>* newNode = new DNode<T>(elem);
		DNode<T>* temp = head;
		head = newNode;
		newNode->next = temp;
		temp->prev = newNode;
		newNode->prev = nullptr;

		while (temp->next != nullptr) 
			temp = temp->next;
		
		tail = temp;
	}
}

template <typename T>
void DLL<T>::addBack(T elem) { //Add to the back of the DLL.
	if (head == nullptr) { //If the list is empty, same as addFront().
		DNode<T>* newNode = new DNode<T>(elem);
		head = newNode;
		tail = newNode;
	}
	else { //Add newNode to the back, adjust pointers.
		DNode<T>* newNode = new DNode<T>(elem);
		DNode<T>* temp = tail;
		
		temp->next = newNode;
		newNode->prev = temp;
		tail = newNode;
	}
}

template <typename T>
void DLL<T>::insertAt(T elem, int n) { //Insert a node at a given index.
	if (n == 1) //If 1st index, same as addFront().
		addFront(elem);
	else if (n == size()) //If last index, same as addBack();
		addBack(elem);
	else { //Increment to the right index, then adjust pointers.
		DNode<T>* temp = head;
		DNode<T>* temp2 = head;
		DNode<T>* newNode = new DNode<T>(elem);

		for (int i = 1; i < n; i++) {
			temp2 = temp;
			temp = temp->next;
		}

		temp->prev = newNode;
		newNode->next = temp;
		newNode->prev = temp2;
		temp2->next = newNode;
	}
}

template <typename T>
void DLL<T>::removeFront() { //Remove the front of the DLL.
	DNode<T>* temp = head;

	head = temp->next;
	delete temp;
}

template <typename T>
void DLL<T>::removeBack() { //Remove the back of the DLL.
	DNode<T>* temp = tail;

	tail = temp->prev;
	delete temp;
	tail->next = nullptr;
}

template <typename T>
void DLL<T>::removeAt(int n) { //Remove at a certain index (similar to insertAt()).
	if (n == 1)
		removeFront();
	else if (n == size())
		removeBack();
	else { //Similar to insertAt(), but need a new pointer pointing to temp's next.
		DNode<T>* temp = head;
		DNode<T>* temp2 = head;
		DNode<T>* temp3 = temp->next;

		for (int i = 1; i < n; i++) {
			temp2 = temp;
			temp3 = temp->next;
			temp = temp->next;
		}

		temp2->next = temp->next;
		temp->next = temp2;
		temp3->prev = temp2;
		delete temp;
	}
}


template <typename T>
void DLL<T>::clear() { //Erase all elements in the DLL.
	DNode<T>* temp;
	while (head != nullptr) {
		temp = head->next;
		delete head;
		head = temp;
	}
	tail = nullptr;
}

template <typename T>
DNode<T>* DLL<T>::at(int n) { //Return the node at an index
	DNode<T>* temp = head;
	for (int i = 0; i < n - 1; i++)
		temp = temp->next;

	return temp;
}

template <typename T>
DNode<T>* DLL<T>::front() { //Return the front of the DLL.
	return head;
}

template <typename T>
DNode<T>* DLL<T>::back() { //Return the back of the DLL.
	return tail;
}

template <typename T>
int DLL<T>::size() { //Return the size of the DLL.
	DNode<T>* temp = head;
	int size = 0;
	while (temp != nullptr) {
		size = size + 1;
		temp = temp->next;
	}

	return size;
}

template <typename T>
void DLL<T>::print() { //Print all contents of the DLL.
	DNode<T>* temp = head;
	if (head == nullptr)
		cout << "List is empty. \n";

	while (temp != nullptr) {
		cout << temp->elem << " ";
		temp = temp->next;
	}

	cout << endl;
}
