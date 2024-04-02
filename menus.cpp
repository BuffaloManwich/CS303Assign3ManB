#include "menus.h"

void intro() {
	cout << "Welcome to QueueTime" << endl;
	cout << setw(2) << "a Manuel Buffa program" << endl;
	cout << setw(4) << "CS303 Assignment 3" << endl;
	cout << endl << endl;
	return;
}

void mainMenu() {
	cout << setw(4) << "Main Menu" << endl;
	cout << "Please choose from the following options:" << endl << endl;
	cout << "1. Build and Modify a Queue" << endl;
	cout << "2. Build a vector (uses Queue for search)" << endl;
	cout << "3. Exit the program" << endl << endl;
	return;
}

void queueMenu() {
	cout << setw(4) << "New Queue Menu" << endl;
	cout << "Please choose from the following options:" << endl << endl;
	cout << "1. Build a Queue of 10 random integers" << endl;
	cout << "2. Build Your Own Queue!!! (user chooses type, size, and values)" << endl;
	cout << "3. Return to Main Menu" << endl << endl;
	return;
}

void manipQueueMenu() {
	cout << "What would you like to do with your Queue?" << endl << endl;
	cout << "1. Add an entry to the Queue (adds to tail)" << endl;
	cout << "2. Remove an entry from the Queue (removes from head)" << endl;
	cout << "3. Move the front entry to the rear" << endl;
	cout << "4. Sort the Queues contents" << endl;
	cout << "5. Print the Queue" << endl;
	cout << "6. Return to Queue Menu" << endl << endl;
}

void vectorMenu() {
	cout << setw(4) << "Vector Menu" << endl;
	cout << "Please choose from the following options:" << endl << endl;
	cout << "1. Build a new integer Vector" << endl;
	cout << "2. Search for a value in the Vector (returns an index for last entry if more than one exist)" << endl;
	cout << "3. Return to Main Menu" << endl << endl;
}

void exitScreen() {
	cout << endl << endl;
	cout << "Thank you for using QueueTime" << endl;
	cout << "a program by Manuel Buffa" << endl << endl;
	cout << "Have a nice day!" << endl;
}