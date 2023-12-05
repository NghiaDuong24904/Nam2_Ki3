#include <iostream>
#include "Bai2.h"

Stack::Stack()
{
    this->size = 0;
    this->topIndex = -1;
    this->arr = nullptr;
}
Stack::Stack(int size)
{
    this->size = size;
    this->arr = new int[size];
    this->topIndex = -1;
}
Stack::~Stack()
{
    if (arr != nullptr)
        delete[] arr;
}
bool Stack::isEmpty()
{
    return topIndex == -1;
}

bool Stack::isFull()
{
    return topIndex == size - 1;
}

void Stack::push(int value)
{
    if (isFull())
    {
        std::cout << "Stack is full ! cannot be pushed.\n";
        return;
    }
    std::cout << "Insert the element in stack: " << value << "\n";
    arr[++topIndex] = value;
}

int Stack::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty ! cannot be poped.\n";
        return -1;
    }

    return arr[topIndex--];
}

int Stack::getTopValue()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty ! cannot be poped.\n";
        return -1;
    }
    else
    {
        return arr[topIndex];
    }
}
