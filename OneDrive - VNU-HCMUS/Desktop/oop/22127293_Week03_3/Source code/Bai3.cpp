#include "Bai3.h"
Course::Course()
{
    this->Id = "";
    this->Name = "";
}
Course::Course(std::string Id, std::string Name)
{
    this->Id = Id;
    this->Name = Name;
}
void Course::enroll(Student &student)
{
    for (auto it = Student_List.begin(); it != Student_List.end(); it++)
    {
        if (it->getStudentId() == student.getStudentId())
        {
            std::cout << "Error: Student with ID " << student.getStudentId() << " already exists in the course." << std::endl;
            return;
        };
    }
    Student_List.push_back(student);
}
void Course::enroll_list(std::vector<Student> list)
{
    for (auto &newStudent : list)
    {
        bool studentExists = false;
        for (auto &student : Student_List)
        {
            if (student.getStudentId() == newStudent.getStudentId())
            {
                std::cout << "Error: Student with ID " << student.getStudentId() << " already exists in the course." << std::endl;
                studentExists = true;
                break;
            }
        }
        if (!studentExists)
        {
            Student_List.push_back(newStudent);
        }
    }
}
void Course::unenroll(std::string Id)
{
    for (auto it = Student_List.begin(); it != Student_List.end();)
    {
        if (it->getStudentId() == Id)
        {
            std::cout << "Removing student with ID " << it->getStudentId() << " from the course." << std::endl;
            Student_List.erase(it);
            return;
        }
        else
            ++it;
    }
    std::cout << "Error: Student with ID " << Id << " doesn't exists in the course." << std::endl;
    return;
}
void Course::unenroll_list(std::vector<std::string> list_id)
{
    for (const auto &remove_id : list_id)
    {
        bool check = false;
        for (auto it = Student_List.begin(); it != Student_List.end();)
        {
            if (it->getStudentId() == remove_id)
            {
                std::cout << "Removing student with ID " << it->getStudentId() << " from the course." << std::endl;
                Student_List.erase(it);
                check = true;
                break;
            }
            else
            {
                ++it;
            }
        }
        if (!check)
        {
            std::cout << "Error: Student with ID " << remove_id << " doesn't exists in the course." << std::endl;
        }
        check = true;
    }
    return;
}

std::vector<Student> Course::exellent()
{
    std::vector<Student> excellent_student;
    for (auto &student : Student_List)
    {
        double grade = student.getGrade();
        if (grade >= 9.0)
            excellent_student.push_back(student);
    }
    return excellent_student;
}
std::vector<Student> Course::very_good()
{
    std::vector<Student> verygood_student;
    for (auto &student : Student_List)
    {
        double grade = student.getGrade();
        if (grade >= 8.0 && grade < 9.0)
            verygood_student.push_back(student);
    }
    return verygood_student;
}
std::vector<Student> Course::good()
{
    std::vector<Student> good_student;
    for (auto &student : Student_List)
    {
        double grade = student.getGrade();
        if (grade >= 7.0 && grade < 8.0)
            good_student.push_back(student);
    }
    return good_student;
}
std::vector<Student> Course::average()
{
    std::vector<Student> average_student;
    for (auto &student : Student_List)
    {
        double grade = student.getGrade();
        if (grade >= 5.0 && grade < 7.0)
            average_student.push_back(student);
    }
    return average_student;
}
std::vector<Student> Course::below_ave()
{
    std::vector<Student> below_student;
    for (auto &student : Student_List)
    {
        double grade = student.getGrade();
        if (grade < 5.0)
            below_student.push_back(student);
    }
    return below_student;
}
int Course::cnt_pass()
{
    int cnt = 0;
    for (auto &student : Student_List)
    {
        if (student.getGrade() >= 5.0)
            cnt++;
    }
    return cnt;
}
int Course::cnt_fail()
{
    return Student_List.size() - cnt_pass();
}
std::string get_lastname(std::string fullName)
{
    int space_index = fullName.rfind(" ");
    std::string lastname = fullName.substr(space_index + 1);
    return lastname;
}
std::string get_firstname(std::string fullname)
{
    int space_index = fullname.find(" ");
    std::string firstname = fullname.substr(0, space_index);
    return firstname;
}
std::string get_midname(std::string fullname)
{
    int pos = fullname.find(" ");
    int length = fullname.rfind(" ");
    std::string midname = fullname.substr(pos + 1, length - pos - 1);
    return midname;
}
bool inc_name(Student a, Student b)
{
    if (get_lastname(a.getFullname()) != get_lastname(b.getFullname()))
    {
        return get_lastname(a.getFullname()) < get_lastname(b.getFullname());
    }
    else if (get_firstname(a.getFullname()) != get_firstname(b.getFullname()))
    {
        return get_firstname(a.getFullname()) < get_firstname(b.getFullname());
    }
    else
        return get_midname(a.getFullname()) < get_midname(b.getFullname());
}
bool dec_name(Student a, Student b)
{
    if (get_lastname(a.getFullname()) != get_lastname(b.getFullname()))
    {
        return get_lastname(a.getFullname()) > get_lastname(b.getFullname());
    }
    else if (get_firstname(a.getFullname()) != get_firstname(b.getFullname()))
    {
        return get_firstname(a.getFullname()) > get_firstname(b.getFullname());
    }
    else
        return get_midname(a.getFullname()) > get_midname(b.getFullname());
}
bool dec_grade(Student a, Student b)
{
    return a.getGrade() > b.getGrade();
}
bool inc_grade(Student a, Student b)
{
    return a.getGrade() < b.getGrade();
}
void Course::sort_inc_name()
{
    sort(Student_List.begin(), Student_List.end(), inc_name);
}
void Course::sort_dec_name()
{
    sort(Student_List.begin(), Student_List.end(), dec_name);
}
void Course::sort_inc_grade()
{
    sort(Student_List.begin(), Student_List.end(), inc_grade);
}
void Course::sort_dec_grade()
{
    sort(Student_List.begin(), Student_List.end(), dec_grade);
}
void Course::write(std::string file_name)
{
    std::ofstream out(file_name);
    if (out.is_open())
    {
        out << Id << "\n";
        out << Name << "\n";
        for (auto it = Student_List.begin(); it != Student_List.end(); ++it)
        {
            out << it->getStudentId() << "," << it->getFullname() << "," << it->getGrade() << "\n";
        }
        out.close();
    }
}
void Course::read(std::string file_name)
{
    std::ifstream in(file_name);
    if (in.is_open())
    {
        std::getline(in, Id);
        std::getline(in, Name);
        Student_List.clear();
        std::string line;
        while (std::getline(in, line))
        {
            std::istringstream iss(line);
            Student student;
            std::string token;
            std::getline(iss, token, ',');
            student.setStudentId(token);
            std::getline(iss, token, ',');
            student.setFullname(token);
            std::getline(iss, token, ',');
            student.setGrade(std::stof(token));
            Student_List.push_back(student);
        }
        in.close();
    }
}