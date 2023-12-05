#include <iostream>
#include <string>
#include <cstring>
class MyString
{
private:
    char *m_Data;
    int m_Length;

public:
    MyString() {}
    MyString(const char *data)
    {
        m_Length = strlen(data);
        m_Data = new char[m_Length + 1];
        strcpy(m_Data, data);
    }
    MyString(const MyString &other)
    {
        m_Length = other.m_Length;
        m_Data = new char[m_Length + 1];
        strcpy(m_Data, other.m_Data);
    }
    ~MyString()
    {
        delete[] m_Data;
    }

    MyString &operator=(const MyString &other)
    {
        delete m_Data[];
        m_size = a.m_size;
        m_data = new int[m_size];
        for (int i = 0; i < m_size; i++)
            m_data[i] = a.m_data[i];
        return *this;
    }
    MyString concaterate(const MyString &other)
    {
        char *newData = new char[m_Length + other.m_Length + 1];
        strcpy(newData, m_Data);
        strcat(newData, other.m_Data);
        MyString result(newData);
        delete[] newData;
        return result;
    }

    void display()
    {
        for (int i = 0; i < m_Length; i++)
        {
            std::cout << m_Data[i];
        }
    }
};
int main()
{
    MyString str1("abc");
    MyString str2("xyz");
    MyString str3(str1);
    MyString str4 = str1.concaterate(str2);
    str3.display();
    std::cout << "\n";
    str4.display();
    return 0;
}