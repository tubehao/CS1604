#include <iostream>
#include <string>
using namespace std;

class Personal {
public:
    Personal() : id("None"), age(0)
    {
        cout << "Personal: Constructor" << endl;
    }

    Personal(string sid, int sage)
        : id(sid), age(sage)
    {
        cout << "Personal: Constructor" << endl;
    }

    ~Personal()
    {
        cout << "Personal: Destructor" << endl;
    }

    string getID() const
    {  return id; }

    int getAge() const
    {  return age; }

private:
    string id;
    int age;
};

class Student : public Personal {
public:
    Student() : classNo("None"), yearEn(2022)
    {
        cout << "Student: Constructor" << endl;
    }

    Student(string sid, int sage, string sclassNo, int syear)
        : Personal(sid, sage), classNo(sclassNo), yearEn(syear)
    {
        cout << "Student: Constructor" << endl;
    }

    ~Student()
    {
        cout << "Student: Destructor" << endl;
    }

    string getClassNo() const
    {  return classNo; }

    int getYear() const
    {  return yearEn; }

private:
    string classNo;   // Class number
    int yearEn;        // Year enrolled
};

int main()
{
    Student s("12345", 19, "F2212345", 2022);

    cout << endl;
    cout << "Student ID: " << s.getID() << endl;
    cout << "Student Age: " << s.getAge() << endl;
    cout << "Student ClassNo: " << s.getClassNo() << endl;
    cout << "Year Enrolled: " << s.getYear() << endl;
    cout << endl;
    return 0;
}
