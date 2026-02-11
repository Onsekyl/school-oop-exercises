#include "student.h"
#include <iostream>

using namespace std;

Student::Student(string newName, int newAge)
{
    name = newName;
    age = newAge;
}

void Student::setAge(int newAge)
{
    age = newAge;
}

void Student::setName(string newName)
{
    name = newName;
}

int Student::getAge()
{
    return age;
}

string Student::getName()
{
    return name;
}

void Student::printStudentInfo()
{
    cout << "Student name: " << name << ", Age: " << age << '\n';
}
