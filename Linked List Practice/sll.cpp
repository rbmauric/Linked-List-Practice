#include "sll.h"

template <typename T>
SLL<T>::SLL() { 
	head = nullptr;
}

template <typename T>
void SLL<T>::addFront(T elem) {
	if (head == nullptr) {
		Node<T>* newNode = new Node<T>(elem);
		head = newNode;
		newNode->next = nullptr;
	}
	else {
		Node<T>* temp = head;
		Node<T>* newNode = new Node<T>(elem);
		head = newNode;
		newNode->next = temp;
	}
}

template <typename T>
void SLL<T>::insertAt(T elem, int n) {
	if (n == 1)
		addFront(elem);
	else {
		Node<T>* temp = head;
		Node<T>* prev = head;
		Node<T>* newNode = new Node<T>(elem);

		for (int i = 0; i < n - 1; i++) {
			if (temp == nullptr) {
				
				prev->next = newNode;
				newNode->next = nullptr;
			}
			prev = temp;
			temp = temp->next;
		}
		
		prev->next = newNode;
		newNode->next = temp;
	}
}

template <typename T>
void SLL<T>::removeFront() {
	Node<T>* temp = head;
	head = head->next;
	delete temp;
}

template <typename T>
void SLL<T>::removeAt(int n) {
	if (n == 1)
		removeFront();
	else {
		Node<T>* temp = head;
		Node<T>* prev = head;

		for (int i = 0; i < n - 1; i++) {
			prev = temp;
			temp = temp->next;
		}

		prev->next = temp->next;
		delete temp;
	}
}

template <typename T>
void SLL<T>::clear() {
	Node<T>* temp;
	while (head != nullptr) {
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <typename T>
Node<T> SLL<T>::front() {
	return head;
}

template <typename T>
int SLL<T>::size() {
	Node<T>* temp = head;
	int size = 0;

	while (temp != nullptr) {
		size = size + 1;
		temp = temp->next;
	}
	return size;
}

template <typename T>
void SLL<T>::print() {
	Node<T>* temp = head;

	if (head == nullptr)
		cout << "List is empty. \n";
	else {
		while (temp != nullptr) {
			cout << temp->elem << " ";
			temp = temp->next;
		}

		cout << endl;
	}
}
