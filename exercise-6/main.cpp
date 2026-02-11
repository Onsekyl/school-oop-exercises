#include "student.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int addAge, selection = 0;
    string addName, searchName;
    vector<Student> studentList;
    vector<Student>::iterator it;

    do
    {
        cout<<endl;
        cout<<"[Select Menu]"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to name = 2"<<endl;
        cout<<"Sort and print students according to age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            cout << "\n(Selection 0) Add new student\nNew student's name: ";
            cin >> addName;

            cout << "And age: ";
            cin >> addAge;

            // Lisää uusi student StudentList vektoriin.
            studentList.emplace_back(addName, addAge);
            cout << "Added student: " << addName << ", " << addAge << '\n';
            break;

        case 1:
            cout << "\n(Selection 1) List of students:\n";

            // Tulosta StudentList vektorin kaikkien opiskelijoiden !nimet!.
            for (auto& student : studentList)
            {
                cout << student.getName() << '\n';
            }
            break;

        case 2:
            cout << "\n(Selection 2) Sort students by name and print infos:\n";

            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b)
            {
                return a.getName() < b.getName();
            });

            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            for (auto& student : studentList)
            {
                student.printStudentInfo();
            }
            break;

        case 3:
            cout << "\n(Selection 3) Sort students by age and print infos:\n";
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            sort(studentList.begin(), studentList.end(), [](Student& a, Student& b)
            {
                return a.getAge() < b.getAge();
            });

            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            for (auto& student : studentList)
            {
                student.printStudentInfo();
            }
            break;

        case 4:
            cout << "\n(Selection 4) Search student by name\nGive a name to search: ";
            // Kysy käyttäjältä opiskelijan nimi
            cin >> searchName;

            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            it = find_if(studentList.begin(), studentList.end(), [searchName](Student& student)
            {
                return student.getName() == searchName;
            });

            if (it != studentList.end())
            {
                cout << "Student with a name '" << searchName << "' found, info:\n";
                it->printStudentInfo();
            }
            else
            {
                cout << "No student with a name: " << searchName << '\n';
            }
            break;

        default:
            cout<< "Wrong selection, stopping...\n";
            break;
        }
    } while(selection < 5);

    return 0;
}
