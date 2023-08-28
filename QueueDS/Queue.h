#pragma once
#include <iostream>

using namespace std;

//Default Queue Capacity set to 200
#define DEFAULT_QUEUE_CAPACITY 200

//Dynamic Queue that can handle multiple data types
template<typename T>
class Queue
{
private:
	T* QueueItems; //Storage for the items in queue
	int front; //To keep track of the front most element in the queue
	int rear; //To keep adding new elements at the rear of the queue
	int count; //Keeps track of the number of elements currently in the queue

public:
	//Default Constructor
	Queue();
	//Function to add a new item at the rear of the queue
	void AddItem(T item);
	//Function to remove item/element from the front of the queue
	T RemoveItem();
	//Function to see what is present at the front of the queue
	T PeekFront();
	//Function to check if the queue is full or not
	int isFull();
	//Function to check if the queue is empty or not
	int isEmpty();
	//Function to check the total number of items in the queue
	int TotalItemsInQueue();
	//Default destructor destroys the queue array at the end of program
	~Queue();
};

