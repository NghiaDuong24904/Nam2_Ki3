#pragma once
#include <iostream>
class Fraction
{
private:
    int num;
    int den;

public:
    Fraction()
    {
        this->num = 0;
        this->den = 1;
    }
    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    };
    Fraction(int num)
    {
        this->num = num;
        this->den = 1;
    }
    friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
    {
        os << fraction.num << "/" << fraction.den << "\n";
        return os;
    }
    bool operator!=(const Fraction &other)
{
    return num * other.den != other.num * den;
}
};
template <class T>
class Stack
{
private:
    T *data;
    int topIndex;
    int capacity;

public:
    Stack();
    Stack(int n);
    ~Stack();
    void clear();
    bool isFull();
    bool isEmpty();
    void push(const T &item);
    T pop();
    T getTop();
};

template <class T>
Stack<T>::Stack()
{
    capacity = 0;
    data = nullptr;
    topIndex = -1;
}

template <class T>
Stack<T>::Stack(int n)
{
    capacity = n;
    data = new T[capacity];
    topIndex = -1;
}

template <class T>
Stack<T>::~Stack()
{
    if (data != nullptr)
    {
        delete[] data;
    }
}

template <class T>
void Stack<T>::clear()
{
    topIndex = -1;
}

template <class T>
bool Stack<T>::isFull()
{
    return topIndex == capacity - 1;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return topIndex == -1;
}

template <class T>
void Stack<T>::push(const T &value)
{
    if (!isFull())
    {
        data[++topIndex] = value;
    }
    else std::cout << "Stack is full\n";
}

template <class T>
T Stack<T>::pop()
{
    if (!isEmpty())
    {
        return data[topIndex--];
    }
    return T(-1);
}

template <class T>
T Stack<T>::getTop()
{
    if (!isEmpty())
    {
        return data[topIndex];
    }
    return T(-1);
}
