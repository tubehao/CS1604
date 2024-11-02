#include <iostream>
#include <string>
using namespace std;

class Personal {
public:
    Personal() : id("None"), age(0) {}

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
    Student() : classNo("None"), yearEn(2022) {}

    string getClassNo() const
    {  return classNo; }

    int getYear() const
    {  return yearEn; }

    void printParent() const
    {
        //cout << "ID: " << id << endl
        //     << "AGE: " << age << endl;
        cout << "ID: " << getID() << endl
             << "AGE: " << getAge() << endl;
    }

private:
    string classNo;   // Class number
    int yearEn;        // Year enrolled
};

int main()
{
    Student s;

    cout << "Student ID: " << s.getID() << endl;
    cout << "Student Age: " << s.getAge() << endl;
    cout << "Student ClassNo: " << s.getClassNo() << endl;
    cout << "Year Enrolled: " << s.getYear() << endl;
    cout << "---------------" << endl;

    s.printParent();

    return 0;
}
