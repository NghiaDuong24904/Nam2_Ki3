#include <iostream>
#include "Bai3.h"
Queue::Queue()
{
    this->size = 0;
    this->frontIndex = -1;
    this->rearIndex = -1;
    this->arr = nullptr;
}
Queue::Queue(int size)
{
    this->size = size;
    this->arr = new int[size];
    this->frontIndex = -1;
    this->rearIndex = -1;
}
Queue::~Queue()
{
    if (arr != nullptr)
        delete[] arr;
}
bool Queue::isEmpty()
{
    return frontIndex == -1 || frontIndex > rearIndex;
}
bool Queue::isFull()
{
    return rearIndex == size - 1;
}
void Queue::enqueue(int value)
{
    if (isFull())
    {
        std::cout << "Queue is full. Cannot enqueue.\n";
        return;
    }
    else
    {
        if (frontIndex == -1)
            frontIndex = 0;
        std::cout << "Insert the element in queue: " << value << std::endl;
        rearIndex++;
        arr[rearIndex] = value;
        return;
    }
}
int Queue::dequeue()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        int dequeuedValue = arr[frontIndex];
        if (frontIndex == rearIndex)
        {
            frontIndex = -1;
            rearIndex = -1;
        }
        else
        {
            frontIndex++;
        }
        return dequeuedValue;
    }
}

int Queue::getFrontValue()
{
    if (isEmpty())
    {
        return -1;
    }
    else
        return arr[frontIndex];
}