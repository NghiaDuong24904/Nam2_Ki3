#include "Bai2.h"

Student::Student()
{
    this->studentId = "";
    this->fullname = "";
    this->grade = 0.0;
}

Student::Student(std::string studentId, double grade, std::string fullname)
{
    this->studentId = studentId;
    this->grade = grade;
    this->fullname = fullname;
}

std::istream &operator>>(std::istream &is, Student &student)
{
    std::string tempId;
    std::string tempName;
    double tempGrade;

    std::cout << "Enter Student ID: ";
    getline(is, student.studentId);
    std::cout << "Enter GPA: ";
    is >> student.grade;
    is.ignore();
    std::cout << "Enter Fullname: ";
    getline(is, student.fullname);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Student &student)
{
    os << "-----------------------------------------------\n";
    os << "Student ID: " << student.studentId << std::endl;
    os << "GPA: " << student.grade << std::endl;
    os << "Fullname: " << student.fullname << std::endl;
    return os;
}

std::string Student::getStudentId()
{
    return studentId;
}

void Student::setStudentId(std::string id)
{
    this->studentId = id;
}

double Student::getGrade()
{
    return grade;
}

void Student::setGrade(double grade)
{
    this->grade = grade;
}

std::string Student::getFullname()
{
    return fullname;
}

void Student::setFullname(std::string name)
{
    this->fullname = name;
}
