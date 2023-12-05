#include <iostream>
#include "Bai1.cpp"
#include "Bai2.cpp"
#include "Bai3.cpp"
#include "Bai4.cpp"
int main()
{
    // Bài 1
    std::cout << "Bai 1 --------------- \n";
    Fraction f1, f2;     // 0/1
    Fraction f3(1, -7);  // -1/7
    Fraction f4(f3);     // Copy constructor
    Fraction f5 = f2;    // Copy constructor
    Fraction f6, f7, f8; // Default constructor
    f6 = f3;             // Operator =
    f7 = f1 + f5;
    f8 = f2 - f4;
    f3 = f1 * f7;
    f5 = f6 / f2; // Cannot divide by zero!
    if (f2 == f3)
        std::cout << "f2==f3" << std::endl;
    if (f3 != f1)
        std::cout << "f3!=f1" << std::endl;
    if (f2 >= f5)
        std::cout << "f2>=f5" << std::endl;
    if (f2 > f5)
        std::cout << "f2>f5" << std::endl;
    if (f5 <= f3)
        std::cout << "f5<=f3" << std::endl;
    if (f5 < f3)
        std::cout << "f5<f3" << std::endl;
    f1 = f2 + 3;
    f3 = -7 + f1;
    f5 = 7 * f3;
    f6 = f4 - 6;
    std::cout << f3 << std::endl;
    std::cout << f6 << std::endl;
    f1 += f5;
    f6 -= f7;
    f8 *= f1;
    f8 /= f2; // Cannot divide by zero!
    std::cout << f8++ << std::endl;
    std::cout << ++f7 << std::endl;
    std::cout << f8-- << std::endl;
    std::cout << --f7 << std::endl;
    f3 += Fraction(11, 2);
    int x = int(f3);     // 3/2 => 1
    float f = (float)f3; // 3/2 => 1.5
    std::cout << x << std::endl;
    std::cout << f << std::endl;

    // Bài 2
    std::cout << "Bai 2 --------------- \n";
    Stack st(5);
    for (int i = 0; i < 6; i++)
    {
        st.push(i);
    }
    std::cout << "Top value is: " << st.getTopValue() << "\n";
    while (!st.isEmpty())
    {
        std::cout << "Delete the element in stack: " << st.pop() << "\n";
    }

    // Bài 3
    std::cout << "Bai 3 --------------- \n";
    Queue qu(5);
    for (int i = 0; i < 6; i++)
    {
        qu.enqueue(i);
    }
    std::cout << "Front value is: " << qu.getFrontValue() << "\n";
    while (!qu.isEmpty())
    {
        std::cout << "Delete the element in queue: " << qu.dequeue() << "\n";
    }
    if (qu.getFrontValue() == -1)
        std::cout << "Queue is empty.\n";
    else
        std::cout << qu.getFrontValue() << "\n";

    // Bài 4
    std::cout << "Bai 4 --------------- \n";
    Student student1;
    std::cin >> student1;
    std::cout << student1;
    Student student2("22127294", 10, "Ho Phuoc Nghia", "KTX KHTN");
    Student student3(student2);
    std::cout << student3;

    return 0;
}