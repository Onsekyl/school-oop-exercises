#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
public:
    Student(std::string, int);
    void setAge(int);
    void setName(std::string);
    int getAge();
    std::string getName();
    void printStudentInfo();

private:
    std::string name;
    int age;
};

#endif // STUDENT_H
