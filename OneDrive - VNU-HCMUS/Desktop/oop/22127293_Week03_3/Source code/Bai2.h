#pragma once
#include <iostream>
#include <string>
class Student
{
private:
    std::string studentId;
    double grade;
    std::string fullname;

public:
    Student();
    Student(std::string studentId, double grade, std::string fullname);
    friend std::istream &operator>>(std::istream &is, Student &student);
    friend std::ostream &operator<<(std::ostream &os, const Student &student);
    std::string getStudentId();
    void setStudentId(std::string id);
    double getGrade();
    void setGrade(double grade);
    std::string getFullname();
    void setFullname(std::string name);
};
