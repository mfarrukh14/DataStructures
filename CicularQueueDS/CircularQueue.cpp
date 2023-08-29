#include "CircularQueue.h"

template<typename T>
Queue<T>::Queue()
{
	QueueItems = new T[DEFAULT_QUEUE_CAPACITY];
	front = 0; //Initially we don't have a front or rear so they are set to -1
	rear = 0;
	count = 0;
}

template<typename T>
void Queue<T>::AddItem(T item)
{

	if (!isFull())
	{
		++count;
		//Placing the new item at the rear of the queue
		QueueItems[rear] = item;
		//Making the queue to be circular i.e, The error caused by the front and rear pointer would be resolved now
		rear = (rear + 1) % DEFAULT_QUEUE_CAPACITY;
	
	}

	else cout<<"\nALERT: QUEUE IS FULL";
}


template<typename T>
T Queue<T>::RemoveItem()
{
	if (!isEmpty())
	{
		T tempItem;

		//remove the front most item and decrement it
		tempItem = QueueItems[front];
		//Making the queue to be circular i.e, The error caused by the front and rear pointer would be resolved now
		front = (front + 1) % DEFAULT_QUEUE_CAPACITY;
		--count;
		
		return tempItem;
	}
	else cout<<"\nALERT: QUEUE IS EMPTY";
	return NULL;
}

template<typename T>
bool Queue<T>::isFull()
{
	return count == DEFAULT_QUEUE_CAPACITY;
}


template<typename T>
bool Queue<T>::isEmpty()
{
	return count == 0;
}

template<typename T>
T Queue<T>::PeekFront()
{
	if (!isEmpty())
	{
		return QueueItems[front];
	}
	else cout << "\nALERT: QUEUE IS EMPTY";
	return NULL;
}

template<typename T>
int Queue<T>::TotalItemsInQueue()
{
	return count;
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] QueueItems;
}