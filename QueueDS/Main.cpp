#include<iostream>
#include<chrono>
#include<thread>
#include<stdlib.h>
#include"Queue.h"
#include"Queue.cpp"

using namespace std;

int main()
{
	//Example Stack usage using integer as the template
	//any data type can be used
	Queue<int> q1;

	int option = -1;

	//Run the loop infinitely unless user chooses to exit
	while (1)
	{
		cout << "\033[2J\033[1;1H";  //Clear screen command
		cout << "\nBASIC STACK DATA STRUCTURE IMPLEMENTATION\n";
		cout << "\nPress 1 to push item";
		cout << "\nPress 2 to remove item";
		cout << "\nPress 3 to peek the front element";
		cout << "\nPress 4 to check if queue is empty";
		cout << "\nPress 5 to check if queue is full";
		cout << "\nPress 6 to retrieve the number of items in queue";
		cout << "\nPress 7 to check the max capacity of queue";
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
			if (!q1.isFull())
			{
				cout << "\nEnter the value to be pushed: ";
				cin >> val;
				q1.AddItem(val);
				cout << "\033[2J\033[1;1H";  //Clear screen command
				cout << "\n\t\t\t\tValue Pushed !";
				std::this_thread::sleep_for(std::chrono::milliseconds(1500)); //Sleep for 1.5 seconds
			}
			else cout << "\nERROR: QUEUE FULL! FAILED TO PUSH ITEM";
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;

		case 2:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			if (!q1.isEmpty())
			{
				cout << "\nValue removed from front: " << q1.RemoveItem();
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			else cout << "\nERROR: QUEUE EMPTY! NO ITEMS TO DISPLAY";
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;

		case 3:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			cout << "\nItem at the front of the queue: ";
			q1.PeekFront();
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;

		case 4:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			if (q1.isEmpty())
			{
				cout << "\nThe queue is empty !";
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			else
			{
				cout << "\nThe queue is not empty !";
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			break;

		case 5:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			if (q1.isFull())
			{
				cout << "\nThe queue is Full !";
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			else
			{
				cout << "\nThe queue is not Full !";
				std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			}
			break;

		case 6:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			cout << "\nNo of items in the queue: " << q1.TotalItemsInQueue();
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;

		case 7:
			cout << "\033[2J\033[1;1H";  //Clear screen command
			cout << "Max Capcity of the queue is: " << DEFAULT_QUEUE_CAPACITY;
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;
		}

	}
	return 0;
}