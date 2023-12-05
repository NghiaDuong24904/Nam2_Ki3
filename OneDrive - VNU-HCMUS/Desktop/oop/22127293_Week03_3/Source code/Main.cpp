#include <iostream>
#include "Bai1.h"
#include "Bai2.cpp"
#include "Bai3.cpp"

int main()
{
    // Bài 1
    std::cout << "Bai 1 --------------- \n";
    Stack<int> intStack(3);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Top element of intStack: " << intStack.getTop() << std::endl;

    int poppedInt = intStack.pop();
    if (poppedInt != -1)
    {
        std::cout << "Popped element from intStack: " << poppedInt << std::endl;
    }
    else
        std::cout << "Stack is empty\n";
    Stack<Fraction> fractionStack(2);
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    fractionStack.push(f1);
    fractionStack.push(f2);

    Fraction poppedFraction = fractionStack.pop();
    if (poppedFraction != -1)
    {
        std::cout << "Popped element from fractionStack: " << poppedFraction << std::endl;
    }
    else
        std::cout << "Stack is empty\n";

    // Bài 2
    std::cout << "Bai 2 --------------- \n";
    Student a;
    std::cin >> a;
    std::cout << a;
    Student b("22127294", 10, "Ho Phuoc Nghia");
    std::cout << "-----------------------------------------------\n";
    std::cout << b.getStudentId() << " " << b.getGrade() << " " << b.getFullname() << "\n";
    b.setStudentId("22127125");
    b.setGrade(8);
    b.setFullname("Nguyen Dang Viet Hoang");
    std::cout << b.getStudentId() << " " << b.getGrade() << " " << b.getFullname() << "\n";
    return 0;

    // Bài 3
    std::cout << "Bai 3 --------------- \n";
    Course hk1;
    hk1.read("danhsach.txt");
    Student st1("22127141", 5, "Huynh Cong Hieu");
    Student st2("22127142", 10, "Huynh Cong Hieu");
    Student st3("22127190", 6, "Huynh Cong Van");
    std::vector<std::string> id = {"22127293", "22127295", "22127283"};
    std::vector<Student> v = {st1, st2, st3};
    // hk1.enroll_list(v);
    // hk1.unenroll_list(id);
    if (hk1.exellent().size() == 0)
        std::cout << "Khong co hoc sinh xuat sac.\n";
    else
    {
        std::cout << "Hoc sinh xuat sac: \n";
        for (auto &student : hk1.exellent())
        {
            std::cout << student.getStudentId() << " " << student.getGrade() << " " << student.getFullname() << "\n";
        }
    }
    if (hk1.very_good().size() == 0)
        std::cout << "Khong co hoc sinh gioi.\n";
    else
    {
        std::cout << "Hoc sinh gioi: \n";
        for (auto &student : hk1.very_good())
        {
            std::cout << student.getStudentId() << " " << student.getGrade() << " " << student.getFullname() << "\n";
        }
    }
    if (hk1.good().size() == 0)
        std::cout << "Khong co hoc sinh kha.\n";
    else
    {
        std::cout << "Hoc sinh kha: \n";
        for (auto &student : hk1.good())
        {
            std::cout << student.getStudentId() << " " << student.getGrade() << " " << student.getFullname() << "\n";
        }
    }
    if (hk1.average().size() == 0)
        std::cout << "Khong co hoc sinh trung binh.\n";
    else
    {
        std::cout << "Hoc sinh trung binh: \n";
        for (auto &student : hk1.average())
        {
            std::cout << student.getStudentId() << " " << student.getGrade() << " " << student.getFullname() << "\n";
        }
    }
    if (hk1.below_ave().size() == 0)
        std::cout << "Khong co hoc sinh duoi trung binh.\n";
    else
    {
        std::cout << "Hoc sinh duoi trung binh: \n";
        for (auto &student : hk1.below_ave())
        {
            std::cout << student.getStudentId() << " " << student.getGrade() << " " << student.getFullname() << "\n";
        }
    }
    std::cout << "Pass: " << hk1.cnt_pass() << "\n";
    std::cout << "Fail: " << hk1.cnt_fail();
    hk1.sort_dec_name();
    hk1.write("danhsach.txt");
}