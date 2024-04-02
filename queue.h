#pragma once
#include "linked.h"

template <typename T>
class Queue {
private:
    Linked<T> list; // Utilizing the Linked class

public:
    // Default constructor
    Queue();

    // Basic queue operations
    void push(const T& value);
    void pop();
    T front() const;
    int size() const;
    bool empty() const;

    // Function to move the front element to the rear
    void move_to_rear();
};