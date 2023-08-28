#include "Queue.h"

template<typename T>
Queue<T>::Queue()
{
	QueueItems = new T[DEFAULT_QUEUE_CAPACITY];
	front = -1; //Initially we don't have a front or rear so they are set to -1
	rear = -1;
	count = 0;
}

template<typename T>
void Queue<T>::AddItem(T item)
{
	if (!isFull())
	{
		++rear;
		//Placing the new item at the rear of the queue
		QueueItems[rear] = item;
		//front is only incremented once when a new item is pushed for the first time
		if (front == -1)
		{
			++front;
		}
		++count;
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
		--count;
		++front;
		return tempItem;
	}
	else cout<<"\nALERT: QUEUE IS EMPTY";
	return NULL;
}

template<typename T>
int Queue<T>::isFull()
{
	return rear >= DEFAULT_QUEUE_CAPACITY;
}


template<typename T>
int Queue<T>::isEmpty()
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