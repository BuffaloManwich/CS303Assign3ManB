#include "function.h"

int main() {
    // Print the introduction
    intro();
    // Print the main menu
    mainMenu();
    // Declare the main menu choice variable
    size_t userChoice;
    // Get user choice
    cout << "What is your choice?" << endl;
    userChoice = boundTest(1, 3, getInput());
    while (userChoice != 3) {
        // If user chooses 1, enter the queue menu
        if (userChoice == 1) {
            queueMenu();
            cout << "What is your choice?" << endl;
            userChoice = boundTest(1, 3, getInput());
            while (userChoice != 3) {
                if (userChoice == 1) {
                    // Build a queue of 10 random integers
                    Queue<int> queue = createQueueWithRandomIntegers();
                    cout << "Queue populated with 10 random integers." << endl;
                    pressEnterToContinue();
                    manipQueues(queue);
                }
                else if (userChoice == 2) {
                    // Build your own queue
                    cout << "How will you initialize your Queue?" << endl;
                    cout << "1. Strings" << endl;
                    cout << "2. Integers" << endl;
                    cout << "Enter your choice." << endl;
                    userChoice = boundTest(1, 2, getInput());
                    if (userChoice == 1) {
                        Queue<string> queue = createQueueWithStrings();
                            manipQueues(queue);
                    }
                    else {
                        Queue<int> queue = createQueueWithIntegers();
                            manipQueues(queue);
                    }
                }
                pressEnterToContinue();
                queueMenu();
                cout << "What is your choice?" << endl;
                userChoice = boundTest(1, 3, getInput());
            }
            cout << "Exiting the Queue menu." << endl << endl;
        }
        // If user chooses 2, enter the vector menu
        else {
            vectorMenu();
            cout << "What is your choice?" << endl;
            userChoice = boundTest(1, 3, getInput());
            vector<int> userVec;
            while (userChoice != 3) {
                if (userChoice == 1) {
                    // Build your own integer vector
                    userVec = createVectorWithIntegers();
                }
                else {
                    if (userVec.size() == 0) { break; }
                    // Search for a value in the vector
                    cout << "What is the value you want to find?" << endl;
                    int userKey = getInput();
                    Queue<int> matched = findMatchingIndices(userVec, userKey);
                    if (matched.empty()) {
                        cout << "No matches found." << endl;
                    }
                    else {
                        cout << "Matches found at index: " << matched.front() << endl;
                    }
                }
                pressEnterToContinue();
                vectorMenu();
                cout << "What is your choice?" << endl;
                userChoice = boundTest(1, 3, getInput());
            }
            cout << "Exiting to Main Menu." << endl << endl;
        }
        pressEnterToContinue();
        mainMenu();
        cout << "What is your choice?" << endl;
        userChoice = boundTest(1, 3, getInput());
    }
    // User has chosen to exit the program
    exitScreen();

    return 0;
}
