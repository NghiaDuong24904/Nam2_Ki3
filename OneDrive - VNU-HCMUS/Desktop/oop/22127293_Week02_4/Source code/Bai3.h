#pragma once
#include <iostream>
class Queue
{
private:
    int *arr;
    int frontIndex, rearIndex;
    int size;
public:
    Queue();
    Queue(int size);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int value);
    int dequeue();
    int getFrontValue();
};