#include "dll.h"

template <typename T>
DLL<T>::DLL() {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void DLL<T>::addFront(T elem) {
	if (head == nullptr) {
		DNode<T>* newNode = new DNode<T>(elem);
		head = newNode;
		tail = newNode;
	}
	else {
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
void DLL<T>::addBack(T elem) {
	if (head == nullptr) {
		DNode<T>* newNode = new DNode<T>(elem);
		head = newNode;
		tail = newNode;
	}
	else {
		DNode<T>* newNode = new DNode<T>(elem);
		DNode<T>* temp = tail;
		
		temp->next = newNode;
		newNode->prev = temp;
		tail = newNode;
	}
}

template <typename T>
void DLL<T>::insertAt(T elem, int n) {
	if (n == 1)
		addFront(elem);
	else if (n == size())
		addBack(elem);
	else {
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
void DLL<T>::removeFront() {
	DNode<T>* temp = head;

	head = temp->next;
	delete temp;
}

template <typename T>
void DLL<T>::removeBack() {
	DNode<T>* temp = tail;

	tail = temp->prev;
	delete temp;
	tail->next = nullptr;
}

template <typename T>
void DLL<T>::removeAt(int n) {
	if (n == 1)
		removeFront();
	else if (n == size())
		removeBack();
	else {
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
void DLL<T>::clear() {
	DNode<T>* temp;
	while (head != nullptr) {
		temp = head->next;
		delete head;
		head = temp;
	}
	tail = nullptr;
}

template <typename T>
DNode<T> DLL<T>::front() {
	return head;
}

template <typename T>
DNode<T> DLL<T>::back() {
	return tail;
}

template <typename T>
int DLL<T>::size() {
	DNode<T>* temp = head;
	int size = 0;
	while (temp != nullptr) {
		size = size + 1;
		temp = temp->next;
	}

	return size;
}

template <typename T>
void DLL<T>::print() {
	DNode<T>* temp = head;
	if (head == nullptr)
		cout << "List is empty. \n";

	while (temp != nullptr) {
		cout << temp->elem << " ";
		temp = temp->next;
	}

	cout << endl;
}
