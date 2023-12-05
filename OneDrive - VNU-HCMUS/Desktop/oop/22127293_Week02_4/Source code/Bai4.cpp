#include <iostream>
#include <cstring>
#include "Bai4.h"
Student::Student()
{
    this->studentId = nullptr;
    this->fullname = nullptr;
    this->address = nullptr;
    this->gpa = 0.0;
}
Student::Student(char *id, double gpa, char *name, char *address)
{
    this->studentId = new char[strlen(id) + 1];
    strcpy(this->studentId, id);

    this->fullname = new char[strlen(name) + 1];
    strcpy(this->fullname, name);

    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);

    this->gpa = gpa;
}
Student::Student(const Student &other)
{
    this->studentId = new char[strlen(other.studentId) + 1];
    strcpy(this->studentId, other.studentId);
    this->fullname = new char[strlen(other.fullname) + 1];
    strcpy(this->fullname, other.fullname);
    this->address = new char[strlen(other.address) + 1];
    strcpy(this->address, other.address);
    this->gpa = other.gpa;
}
Student::~Student()
{
    delete[] studentId;
    delete[] fullname;
    delete[] address;
}
std::ostream &operator<<(std::ostream &os, const Student &student)
{
    os << "-----------------------------------------------\n";
    os << "Student ID: " << student.studentId << std::endl;
    os << "Fullname: " << student.fullname << std::endl;
    os << "Address: " << student.address << std::endl;
    os << "GPA: " << student.gpa << std::endl;
    return os;
}

Student &Student::operator=(const Student &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] studentId;
    delete[] fullname;
    delete[] address;
    this->studentId = new char[strlen(other.studentId) + 1];
    strcpy(this->studentId, other.studentId);
    this->fullname = new char[strlen(other.fullname) + 1];
    strcpy(this->fullname, other.fullname);
    this->address = new char[strlen(other.address) + 1];
    strcpy(this->address, other.address);
    this->gpa = other.gpa;

    return *this;
}

std::istream &operator>>(std::istream &is, Student &student)
{
    char tempId[100];
    char tempName[100];
    char tempAddr[100];
    double tempGPA;

    std::cout << "Enter Student ID: ";
    is.getline(tempId, sizeof(tempId));
    std::cout << "Enter Fullname: ";
    is.getline(tempName, sizeof(tempName));
    std::cout << "Enter Address: ";
    is.getline(tempAddr, sizeof(tempAddr));
    std::cout << "Enter GPA: ";
    is >> tempGPA;
    student = Student(tempId, tempGPA, tempName, tempAddr);
    return is;
}