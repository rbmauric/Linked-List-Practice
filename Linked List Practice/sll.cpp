#include "sll.h"

template <typename T>
SLL<T>::SLL() { //Default constructor for SLL, set head to null.
	head = nullptr;
}

template <typename T>
void SLL<T>::addFront(T elem) { //Add to the front of the SLL.
	if (head == nullptr) { //If empty, set as new head.
		Node<T>* newNode = new Node<T>(elem);
		head = newNode;
		newNode->next = nullptr;
	}
	else { //If not, set newNode to the front and its next node to the previous head.
		Node<T>* temp = head;
		Node<T>* newNode = new Node<T>(elem);
		head = newNode;
		newNode->next = temp;
	}
}

template <typename T>
void SLL<T>::insertAt(T elem, int n) { //Insert a node at a given index.
	if (n == 1) //If first index, same as addFront().
		addFront(elem);
	else { //Use pointers to increment to correct index, with prev being the previous node.
		Node<T>* temp = head;
		Node<T>* prev = head;
		Node<T>* newNode = new Node<T>(elem);

		for (int i = 0; i < n - 1; i++) {
			if (temp == nullptr) { //Insert at the back.
				
				prev->next = newNode;
				newNode->next = nullptr;
			}
			prev = temp; 
			temp = temp->next;
		}
		
		prev->next = newNode; //Previous node's next node is newNode.
		newNode->next = temp; //newNode's next node is the original node at the index.
	}
}

template <typename T>
void SLL<T>::removeFront() { //Remove the front of the SLL.
	Node<T>* temp = head;
	head = head->next;
	delete temp;
}

template <typename T>
void SLL<T>::removeAt(int n) { //Remove a node at an index (similar to insertAt).
	if (n == 1) //If first index, same as removeFront().
		removeFront();
	else { //Similar to insertAt.
		Node<T>* temp = head;
		Node<T>* prev = head;

		for (int i = 0; i < n - 1; i++) {
			prev = temp;
			temp = temp->next;
		}

		prev->next = temp->next; //Set previous node's next node to the next node of the index.
		delete temp; //Delete node.
	}
}

template <typename T>
void SLL<T>::clear() { //Erase all elements in the SLL.
	Node<T>* temp;
	while (head != nullptr) {
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <typename T>
Node<T> SLL<T>::front() { //Return the front of the SLL.
	return head;
}

template <typename T>
int SLL<T>::size() { //Return the size of the SLL.
	Node<T>* temp = head;
	int size = 0;

	while (temp != nullptr) {
		size = size + 1;
		temp = temp->next;
	}
	return size;
}

template <typename T>
void SLL<T>::print() { //Print all elements of the SLL.
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
