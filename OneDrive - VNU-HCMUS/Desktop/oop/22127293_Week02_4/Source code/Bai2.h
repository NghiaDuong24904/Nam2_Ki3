#pragma once
#include <iostream>
class Stack
{
private:
    int *arr;
    int topIndex;
    int size;
public:
    Stack();
    Stack(int size);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int value);
    int pop();
    int getTopValue();
};