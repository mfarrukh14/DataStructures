#include<iostream>
#include<chrono>
#include<thread>
#include<stdlib.h>
#include"Stack.h"
#include"Stack.cpp"

using namespace std;

int main()
{
	//Example Stack usage using integer as the template
	//any data type can be used
	Stack<int> myStack;

	int option = -1;

	//Run the loop infinitely unless user chooses to exit
	while (1)
	{
		cout << "\033[2J\033[1;1H";  //Clear screen command
		cout << "\nBASIC STACK DATA STRUCTURE IMPLEMENTATION\n";
		cout << "\nPress 1 to push item";
		cout << "\nPress 2 to pop item";
		cout << "\nPress 3 to peek the top element";
		cout << "\nPress 4 to check if stack is empty";
		cout << "\nPress 5 to check if stack is full";
		cout << "\nPress 6 to retrieve the number of items in stack";
		cout << "\nPress 7 to check the max capacity of stack";
		cout << "\nPress 0 to exit";
		cout << "\nOption: ";
		cin >> option;

		switch (option)
		{
		case 0:
			exit(1);
			break;
		case 1:
			int val;
			cout << "\033[2J\033[1;1H";  //Clear screen command
			cout << "\nEnter the value to be pushed: ";
			cin >> val;
			myStack.push(val);
			cout << "\033[2J\033[1;1H";  //Clear screen command
			cout << "\n\t\t\t\tValue Pushed !";
			std::this_thread::sleep_for(std::chrono::milliseconds(1500)); //Sleep for 1.5 seconds
			break;

		case 2:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			if (!myStack.isEmpty())
			{
				cout << "\nValue popped: " << myStack.pop();
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			else cout << "\nSTACK UNDERFLOW: NO ITEMS TO DISPLAY";
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;

		case 3:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			cout << "\nItem at the top of the stack: ";
			myStack.peek();
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;

		case 4:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			if (myStack.isEmpty())
			{
				cout << "\nThe Stack is empty !";
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			else
			{
				cout << "\nThe Stack is not empty !";
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			break;

		case 5:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			if (myStack.isFull())
			{
				cout << "\nThe Stack is Full !";
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			else
			{
				cout << "\nThe Stack is not Full !";
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			break;

		case 6:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			cout << "\nNo of items in the stack: " << myStack.NoOfItems();
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;

		case 7:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			cout << "Max Capcity of the stack is: " << myStack.TotalCapacity();
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;
		}

	}
	return 0;
}