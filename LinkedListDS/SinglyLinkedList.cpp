#include<iostream>

using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node* next;

	Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class LinkedList
{
private:
	Node<T>* head;

public:

	LinkedList() : head(nullptr) {}
	void AddItemEnd(T data);
	void AddItemStart(T data);
	void delItem(T data);
	void clear();
	void PrintQueue();
	~LinkedList()
	{
		clear();
	}

};

template<typename T>
void LinkedList<T>::AddItemEnd(T data)
{
	Node<T>* myNode = new Node<T>(data);

	if (head == nullptr)
	{
		head = myNode;
	}

	else
	{
		Node<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = myNode;

	}
}

template<typename T>
void LinkedList<T>::AddItemStart(T data)
{
	Node<T>* newNode = new Node<T>(data);
	newNode->next = head;
	head = newNode;

}


template<typename T>
void LinkedList<T>::delItem(T data)
{
	if (head == nullptr)
	{
		return;
	}

	if (head->data == data)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		return;
	}

	Node<T>* current = head;

	while (current->next != nullptr && current->next->data != data)
	{
		current = current->next;
	}

	if (current->next == nullptr) {
		return;
	}

	Node<T>* temp = current->next;
	current->next = current->next->next;
	delete temp;
}

template<typename T>
void LinkedList<T>::PrintQueue()
{
	Node<T>* temp = head;

	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

}

template<typename T>
void LinkedList<T>::clear()
{
	while (head != nullptr)
	{
		Node<T>* current = head;
		head = head->next;
		delete current;
	}
}


int main()
{
	LinkedList<int> l1;
	l1.AddItemEnd(1);
	l1.AddItemEnd(12);
	l1.AddItemEnd(123);
	l1.AddItemEnd(1234);
	l1.AddItemEnd(12345);
	l1.AddItemEnd(0);

	l1.PrintQueue();
	l1.AddItemStart(6);

	l1.PrintQueue();
	l1.delItem(123);
	l1.delItem(6);

	l1.PrintQueue();


	return 0;

}
