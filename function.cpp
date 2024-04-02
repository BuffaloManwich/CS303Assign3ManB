#include "function.h"

template <typename T>
void printQue(Queue<T>& que) {
    Queue<T> tempQue; // Temporary queue to hold elements
    T tempVal;
    while (!que.empty()) {
        tempVal = que.front(); // Get the value from the front
        cout << tempVal << " "; // Print the value
        que.pop(); // Remove the value from the original queue
        tempQue.push(tempVal); // Add it to the temporary queue
    }
    cout << endl;

    // Now, restore the original queue from tempQue
    que = tempQue;

    return;
}
// Explicit instantiation for the common types.
template void printQue<int>(Queue<int>& que);
template void printQue<string>(Queue<string>& que);
template void printQue<char>(Queue<char>& que);
template void printQue<size_t>(Queue<size_t>& que);

// Wrapper function for the recursive search.
void findMatchingIndicesRecursive(const vector<int>& vec, const int& target, Queue<int>& matchQue, int index) {
    if (index < 0) { // Base case: processed the end of the vector, index 0.
        return;
    }
    if (vec[index] == target) { // Check if the current element matches the target
        matchQue.push(index); // Push the index of the matching entry at the front
    }

    // Recursive call to check the next element (moving towards the beginning)
    findMatchingIndicesRecursive(vec, target, matchQue, index - 1);    
}

Queue<int> findMatchingIndices(const vector<int>& vec, const int& target) {
    Queue<int> matchQue; // Queue to hold the indices of matching entries
    findMatchingIndicesRecursive(vec, target, matchQue, vec.size() - 1); // Start recursion from the end of the vector
    return matchQue;
}

Queue<int> createQueueWithRandomIntegers() {
    Queue<int> queue; // Create an empty Queue of integers
    const size_t count = 10; // Number of random integers to add
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator

    for (size_t i = 0; i < count; ++i) {
        int randomInt = rand() % 100; // Generate a random integer between 0 and 99
        queue.push(randomInt); // Push it onto the queue
    }

    return queue; // Return the populated queue
}

template <typename T>
void sortQueue(Queue<T>& queue) {
    vector<T> sortedVec;

    while (!queue.empty()) {
        T current = queue.front();
        queue.pop(); // Remove the front entry

        // Manually find the correct position for insertion
        size_t iter = 0;
        // Iterate until end is reached or an entry larger is found in the vector.
        while (iter < sortedVec.size() && sortedVec.at(iter) < current) { ++iter; }
        // No larger entry is found, push_back value.
        if (iter == sortedVec.size()) { sortedVec.push_back(current); }
        // Insert before the larger number.
        else { sortedVec.insert(sortedVec.begin() + iter, current); }
    }
    // Clear the original queue in case it's not empty, should not happen.
    while (!queue.empty()) {
        queue.pop();
    }

    // Enqueue the sorted elements back into the queue
    for (size_t i = 0; i < sortedVec.size(); ++i) {
        queue.push(sortedVec.at(i));
    }
    // Queue is now in sorted order.
}
template void sortQueue(Queue<int>& queue);
template void sortQueue(Queue<string>& queue);
template void sortQueue(Queue<char>& queue);
template void sortQueue(Queue<size_t>& queue);

void pressEnterToContinue() {
    cout << "Press Enter to continue . . ." << endl;
    string temp;
    getline(cin, temp); // Wait for user to press Enter
    cout << endl;
}

// This function removes alphabetical chars and symbols from a string
string cleanInput(string in) {
    string out = "";
    size_t negCount = 0;
    size_t i;
    // Iterate over each char over the length of string
    for (i = 0; i < in.size(); ++i) {
        // This line adds chars to str out if a neg sign or int.
        if ((in.at(i) == '-' && negCount == 0) || isdigit(in.at(i))) {
            out += in.at(i);
            // This ensures only one neg sign is added to the out string
            if (in.at(i) == '-') { negCount = 1; }
        }
    }
    // "Out" string is finished, verify string not empty, and not solely a neg sign.
    if ((out.size() == 1 && out.at(0) == '-') || out.empty()) {
        out = "ERROR";
    }
    // Function will return either a convertable numeric string or the word "ERROR"
    return out;
}

size_t boundTest(int min, int max, int in) {
    // This will ensure the now confirmed input integer is within the bounds
    while (in < min || in > max) {
        cout << "ERROR: Entry out of bounds." << endl;
        cout << "Please enter a valid selection, values " << min << " - " << max << "." << endl;
        in = getInput();
    }
    return in;
}

int getInput() {
    // This is a function that will have a verification loop for numeric user inputs.
    int out;
    string userIn;
    string userNo;

    getline(cin, userIn);
    userNo = cleanInput(userIn);
    // If userNo is "ERROR", enter while loop until valid choice is input.
    if (userNo == "ERROR") {
        while (userNo == "ERROR") {
            cout << userNo << ": Invalid entry! Please enter a valid selection." << endl;
            getline(cin, userIn);
            userNo = cleanInput(userIn);
        }
    }
    try {
        out = stoi(userNo);
        return out;
    }
    catch (const invalid_argument&) {
        cout << "ERROR: Invalid entry!" << endl;
        return getInput();
    }
}

string getValue() {
    // This function be for adding a string value to a Queue<string>
    string userIn;
    getline(cin, userIn);
    cout << endl;
    return userIn;
}

Queue<string> createQueueWithStrings() {
    // This function will create a Queue<string> with user inputs
    Queue<string> queue;
    string userIn;
    cout << "How many entries are in your queue? (max 100)" << endl;
    size_t count = boundTest(1, 100, getInput());
    cout << "Please enter your entries:" << endl;
    for (size_t i = 0; i < count; ++i) {
        userIn = getValue();
        queue.push(userIn);
    }
    return queue;
}

Queue<int> createQueueWithIntegers() {
    // This function will create a Queue<int> with user inputs
    Queue<int> queue;
    int userIn;
    cout << "How many entries are in your queue? (max 100)" << endl;
    size_t count = boundTest(1, 100, getInput());
    cout << "Please enter your entries:" << endl;
    for (size_t i = 0; i < count; ++i) {
        userIn = getInput();
        queue.push(userIn);
        cout << endl;
    }
    return queue;
}

template <typename T>
void manipQueues(Queue<T>& que) {
    // This function will allow the user to manipulate a queue and navigate the manip menu
    // Regardless of Queue type
    T entry;
    size_t userChoice;
    manipQueueMenu();
    cout << "What is your choice?" << endl;
    userChoice = boundTest(1, 6, getInput());
    while (userChoice != 6) {
        if (userChoice == 1) {
            // Add an entry to the queue
            cout << "Please enter your value:" << endl;
            cin >> entry;
            que.push(entry);
            cout << endl;
            cout << "Value " << entry << " pushed to the queue." << endl;
            cout << endl << endl;
        }
        else if (userChoice == 2) {
            // Remove an entry from the queue
            entry = que.front();
            que.pop();
            cout << "Value " << entry << " removed from the queue." << endl;
        }
        else if (userChoice == 3) {
            // Move the front entry to the rear of the queue
            entry = que.front();
            que.move_to_rear();
            cout << "Value " << entry << " moved to the rear of the queue." << endl;
        }
        else if (userChoice == 4) {
            // Sort the queues contents
            sortQueue(que);
            cout << "Queue sorted." << endl;
        }
        else if (userChoice == 5) {
            // Print the queue
            printQue(que);
        }
        pressEnterToContinue();
        manipQueueMenu();
        cout << "What is your choice?" << endl;
        userChoice = boundTest(1, 6, getInput());
    }
    cout << "Exiting Queue Manipulation Menu." << endl;
}

// Explicit instantiation of the manipQueues() template function
template void manipQueues(Queue<int>& que);
template void manipQueues(Queue<string>& que);
template void manipQueues(Queue<char>& que);
template void manipQueues(Queue<size_t>& que);

vector<int> createVectorWithIntegers() {
    // This function will create a vector with user inputs
    vector<int> vec;
    size_t count, i;
    int userIn;
    cout << "How many entries are in your vector? (max 100)" << endl;
    count = boundTest(1, 100, getInput());
    cout << "Please enter your entries:" << endl;
    for (i = 0; i < count; ++i) {
        userIn = getInput();
        vec.push_back(userIn);
    }
    cout << "Vector created." << endl;
    return vec;
}