#pragma once
#include <iostream>
class Student
{
private:
    char *studentId;
    double gpa;
    char *fullname;
    char *address;

public:
    Student();
    Student(char *id, double gpa, char *name, char *address);
    Student(const Student &other);
    ~Student();
    Student &operator=(const Student &other);
    friend std::istream &operator>>(std::istream &is, Student &student);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};