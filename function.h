#pragma once
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include "queue.h"
#include "menus.h"


using namespace std;

template <typename T>
void printQue(Queue<T>& que);

void findMatchingIndicesRecursive(const vector<int>& vec, const int& target, Queue<int>& matchQue, int index);

Queue<int> findMatchingIndices(const vector<int>& vec, const int& target);

Queue<int> createQueueWithRandomIntegers();

template <typename T>
void sortQueue(Queue<T>& queue);

void pressEnterToContinue();

string cleanInput(string in);

size_t boundTest(int min, int max, int in);

int getInput();

string getValue();

Queue<string> createQueueWithStrings();

Queue<int> createQueueWithIntegers();

template <typename T>
void manipQueues(Queue<T>& que);

vector<int> createVectorWithIntegers();