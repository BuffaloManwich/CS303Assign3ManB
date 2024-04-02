#pragma once
#include <string>
#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node* nextPtr;
};

template<typename T>
class Linked {
protected:
    Node<T>* headPtr;
    Node<T>* tailPtr;
    int count;
public:
    Linked(); // Default constructor
    Linked(const Linked<T>& other); // Copy constructor
    ~Linked(); // Destructor
    Linked<T>& operator=(const Linked<T>& other); // Assignment operator
    void addNode(T d);
    void delNode(T key);
    // void printList() const; Remenant from imported class, leaving for later usage.
    int size() const;
    Node<T>* getHeadPtr() const;
    Node<T>* getTailPtr() const;
};
