#pragma once
#include<iostream>

#define DEFAULT_STACK_LIMIT 200

//Using template to define the stack class 
template<typename T>
class Stack
{
private:
	int top;  //index used to keep track of item lacing in stack
	T* items; //Storage for items
	double count; //Keep track of the number of items stored in the stack
	double StackCapacity;  //Defines the capacity of the stack

public:
	//A constructor that acts as a default if capacity is not passed and parameterized if capacity is passed
	Stack(double capacity = 0);
	//Function to push the object into the stack
	void push(T newItem);
	//Function to pop the top most element from the stack and return it
	T pop();
	//Function to peek at the top most element in the stack without removing it
	void peek();
	//Function to check if the stack is empty or not
	int isEmpty();
	//Function to check if the stack is full or not
	int isFull();
	//Function that returns the number of items currently present in the stack
	double NoOfItems();
	//Function that returns the capacity of the stack
	double TotalCapacity();
	~Stack();
};

