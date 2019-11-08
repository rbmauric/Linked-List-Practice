#ifndef DLL_H
#define DLL_H

template<class T>
class DNode {
public:
	DNode() {
		elem = 0;
		next = nullptr;
		prev = nullptr;
	}

	DNode(T elem_) {
		elem = elem_;
		next = nullptr;
		prev = nullptr;
	}

	T elem;
	DNode<T>* next;
	DNode<T>* prev;
};

template <class T>
class DLL {
public:
	DLL();

	void addFront(T elem);
	void addBack(T elem);
	void insertAt(T elem, int n);
	void removeFront();
	void removeBack();
	void removeAt(int n);

	void clear();
	DNode<T> front();
	DNode<T> back();
	int size(); 
	void print();

private:
	DNode<T>* head;
	DNode<T>* tail;
};
 
#endif DLL_H

