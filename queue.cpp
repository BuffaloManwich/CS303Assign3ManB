#include "queue.h"

template <typename T>
Queue<T>::Queue() : list() {}

template <typename T>
void Queue<T>::push(const T& value) {
    list.addNode(value); // Add value to the rear
}

template <typename T>
void Queue<T>::pop() {
    if (!this->empty()) {
        T frontValue = this->front(); // Retrieve the front value
        list.delNode(frontValue); // Remove the node with this value
    }
}

template <typename T>
T Queue<T>::front() const {
    if (!this->empty()) {
        Node<T>* headNode = list.getHeadPtr();
        return headNode->data; // Directly access the data of the head node
    }
    else {
        cout << "The list is empty. No value to return" << endl;
    }
}

template <typename T>
int Queue<T>::size() const {
    return list.size(); // Return the size of the queue
}

template <typename T>
bool Queue<T>::empty() const {
    return list.size() == 0; // Check if the queue is empty
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (!this->empty()) {
        T frontElement = this->front(); // Get the front element
        this->pop(); // Remove it from the queue
        this->push(frontElement); // Push it back to the rear
    }
}

// Explicit instantiation for 'int'
template class Queue<int>;

// Explicit instantiation for 'string'
template class Queue<string>;

// Explicit instantiation for 'char'
template class Queue<char>;

// Explicit instantiation for 'size_t'
template class Queue<size_t>;