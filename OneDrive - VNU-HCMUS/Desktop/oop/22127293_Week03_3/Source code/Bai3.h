#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Bai2.h"
bool inc_name(Student a, Student b);
bool dec_name(Student a, Student b);
bool inc_grade(Student a, Student b);
bool dec_grade(Student a, Student b);
std::string get_firstname(std::string a);
std::string get_midname(std::string a);
std::string get_lastname(std::string a);
class Course
{
private:
    std::string Id;
    std::string Name;
    std::vector<Student> Student_List;

public:
    Course();
    Course(std::string Id, std::string Name);
    void enroll(Student &student);
    void enroll_list(std::vector<Student> list);
    void unenroll(std::string Id);
    void unenroll_list(std::vector<std::string> list_id);
    std::vector<Student> exellent();
    std::vector<Student> very_good();
    std::vector<Student> good();
    std::vector<Student> average();
    std::vector<Student> below_ave();
    int cnt_pass();
    int cnt_fail();
    void sort_inc_name();
    void sort_dec_name();
    void sort_inc_grade();
    void sort_dec_grade();
    void write(std::string file_name);
    void read(std::string file_name);
};