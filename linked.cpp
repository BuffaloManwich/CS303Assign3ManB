#include "linked.h"

template<typename T>
Linked<T>::Linked() : headPtr(nullptr), tailPtr(nullptr), count(0) {}


template<typename T>
Linked<T>::Linked(const Linked<T>& other) : headPtr(nullptr), tailPtr(nullptr), count(0) {
    Node<T>* current = other.headPtr;
    while (current != nullptr) {
        addNode(current->data); // Reuse addNode to copy elements
        current = current->nextPtr;
    }
}

template<typename T>
Linked<T>& Linked<T>::operator=(const Linked<T>& other) {
    if (this != &other) { // Protect against self-assignment
        // Clear current list
        while (headPtr != nullptr) {
            delNode(headPtr->data); // Assuming delNode updates headPtr and count appropriately
        }

        // Copy elements from other to this list
        Node<T>* current = other.headPtr;
        while (current != nullptr) {
            addNode(current->data);
            current = current->nextPtr;
        }
    }
    return *this;
}

template<typename T>
Linked<T>::~Linked() {
    Node<T>* current = headPtr;
    while (current != nullptr) {
        Node<T>* next = current->nextPtr;
        delete current;
        current = next;
    }
    headPtr = tailPtr = nullptr;
}

template<typename T>
void Linked<T>::addNode(T d) { // List adds to the tail
    Node<T>* newNode = new Node<T>{ d, nullptr };
    if (headPtr == nullptr) {
        headPtr = tailPtr = newNode;
    }
    else {
        tailPtr->nextPtr = newNode;
        tailPtr = newNode;
    }
    count++;
}

template<typename T>
void Linked<T>::delNode(T key) {
    Node<T>* tempPtr = headPtr;
    Node<T>* delPtr = nullptr;
    if (count == 0) {
        cout << "The list is empty." << endl;
        return; 
    }
    else if (tempPtr != nullptr && tempPtr->data == key) { // The key value is at the headPtr
        delPtr = tempPtr;
        headPtr = tempPtr->nextPtr;  // Set head pointer to second entry
        delete delPtr; // Delete the node at delPtr
        delPtr = nullptr; // Set delPtr to nullptr
        count--; // Decrement count when a node is deleted
        if (count == 0) {  // List only had one entry
            cout << "The list is now empty." << endl;
        }
        return;
    }
    else {
        while (tempPtr != nullptr && tempPtr->nextPtr != nullptr) { // While not tail or beyond
            if (tempPtr->nextPtr->data == key) { // nextPtr == key
                delPtr = tempPtr->nextPtr;
                tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
                if (tempPtr->nextPtr == nullptr) { tailPtr = tempPtr; } // Node was tailPtr
                delete delPtr;
                delPtr = nullptr;
                count--; // Decrement count when a node is deleted
                return;
            }
            tempPtr = tempPtr->nextPtr; // Iterate forward throught the list
        }
    }
    cout << "The entry " << key << " was not found in the list." << endl;
}

/*
* This is leftover from a previous program. Not being deleted due to future potential.
template<typename T>
void Linked<T>::printList() const {
    Node<T>* current = headPtr;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->nextPtr;
    }
    cout << endl;
}
*/
template<typename T>
int Linked<T>::size() const {
    return count;
}

template<typename T>
Node<T>* Linked<T>::getHeadPtr() const { return headPtr; }

template<typename T>
Node<T>* Linked<T>::getTailPtr() const { return tailPtr; }

// Template instantiation for common types
template class Linked<int>;
template class Linked<string>;
template class Linked<char>;
template class Linked<size_t>;
