#ifndef SLL_H
#define SLL_H

template<typename T>
class Node {
public:
	Node() {
		elem = 0;
		next = nullptr;
	}

	Node(T elem_) {
		elem = elem_;
		next = nullptr;
	}

	T elem;
	Node<T>* next;
};

template <typename T>
class SLL {
public:
	SLL();

	void addFront(T elem);
	void insertAt(T elem, int n);
	void removeFront();
	void removeAt(int n);
	void clear();
	Node<T> front();
	int size();
	void print();

private:
	Node<T>* head;
};
#endif SLL_H
