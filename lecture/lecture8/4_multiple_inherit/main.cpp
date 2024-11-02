#include <iostream>
#include <string>
using namespace std;

class Personal {
public:
    Personal() : id("None"), age(0)
    {}

    Personal(string sid, int sage)
        : id(sid), age(sage)
    {}

    ~Personal()
    {}

    string getID() const
    {  return id; }

    int getAge() const
    {  return age; }

    void print() const {
        cout << "ID: " << id << endl;
        cout << "Age: " << age << endl;
    }

private:
    string id;
    int age;
};

class Transient {
public:
    Transient() : months(0) {}
    Transient(int m) : months(m) {}

    int getMonths() const { return months; }

private:
    int months;
};

class Student : public Personal, public Transient {
public:
    Student() : classNo("None"), yearEn(2022)
    {}

    Student(string sid, int sage, string sclassNo, int syear, int months)
        : Personal(sid, sage), Transient(months), classNo(sclassNo), yearEn(syear)
    {}

    string getClassNo() const
    {  return classNo; }

    int getYear() const
    {  return yearEn; }

    void print() const {
        cout << "ID: " << getID() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Class: " << classNo << endl;
        cout << "Year Enrolled: " << yearEn << endl;
        cout << "Months to Stay: " << getMonths() << endl;
    }

private:
    string classNo;   // Class number
    int yearEn;       // Year enrolled
};

int main()
{
    Student s("12345", 19, "F2212345", 2022, 48);

    s.print();
    return 0;
}
