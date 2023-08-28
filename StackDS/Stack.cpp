#include "Stack.h"

//Constructor
template<typename T>
Stack<T>::Stack(double capacity)
{
	//If no capacity is specified we initialize thestack with the default capacity
	if (capacity == 0)
	{
		top = -1;
		StackCapacity = DEFAULT_STACK_LIMIT;
		items = new T[DEFAULT_STACK_LIMIT];
		count = 0;
	}
	else 
	{
		StackCapacity = capacity;
		top = -1;
		items = new T[StackCapacity];
		count = 0;
	}
}


template<typename T>
void Stack<T>::push(T newItem)
{
	if (!isFull())
	{
		//Placing the newest item on the top
		++count;
		++top;
		items[top] = newItem;
	}
	else std::cout << "STACK OVERFLOW: MAX STACK CAPACITY EXCEEDED";
}

template<typename T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		T temp;
		temp = items[top];
		--top;
		--count;
		return temp;
	}
	else
	{
		std::cout << "STACK UNDERFLOW: NO ITEMS FOUND IN STACK TO POP";
		return NULL;
	}
}

template<typename T>
void Stack<T>::peek()
{
	if (!isEmpty())
	{
		std::cout<< items[top];
	}

	else 
	{
		std::cout << "\nSTACK EMPTY";
	}
}

template<typename T>
int Stack<T>::isEmpty()
{
	return top == -1;
}

template<typename T>
int Stack<T>::isFull()
{
	return top >= DEFAULT_STACK_LIMIT;
}

template<typename T>
double Stack<T>::NoOfItems()
{
	return count;
}

template<typename T>
double Stack<T>::TotalCapacity()
{
	return StackCapacity;
}



template<typename T>
Stack<T>::~Stack()
{
	delete[] items;
}