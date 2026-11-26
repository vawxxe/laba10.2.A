
#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

// Створення динамічного масиву студентів
Student* createStudents(int n)
{
    return new Student[n];
}

// Введення даних про студентів
void inputStudents(Student* students, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Enter surname: ";
        cin >> students[i].surname;

        cout << "Enter course: ";
        cin >> students[i].course;

        while (cin.fail() || students[i].course < 1 || students[i].course > 6)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid course! Enter again (1-6): ";
            cin >> students[i].course;
        }

        cout << "\nChoose specialty:" << endl;
        cout << "1. Computer Science" << endl;
        cout << "2. Informatics" << endl;
        cout << "3. Math and Economics" << endl;
        cout << "4. Physics and Informatics" << endl;
        cout << "5. Labor Training" << endl;
        cout << "Your choice: ";

        int choice;
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 5)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice! Enter 1-5: ";
            cin >> choice;
        }

        students[i].specialty = static_cast<Specialty>(choice - 1);

        cout << "Enter Physics grade: ";
        cin >> students[i].physics;

        while (cin.fail() || students[i].physics < 0 || students[i].physics > 100)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid grade! Enter 0-100: ";
            cin >> students[i].physics;
        }

        cout << "Enter Mathematics grade: ";
        cin >> students[i].mathematics;

        while (cin.fail() || students[i].mathematics < 0 || students[i].mathematics > 100)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid grade! Enter 0-100: ";
            cin >> students[i].mathematics;
        }

        cout << "Enter Informatics grade: ";
        cin >> students[i].informatics;

        while (cin.fail() || students[i].informatics < 0 || students[i].informatics > 100)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid grade! Enter 0-100: ";
            cin >> students[i].informatics;
        }
    }
}

// Отримання назви спеціальності
string getSpecialtyName(Specialty specialty)
{
    switch (specialty)
    {
    case ComputerScience:
        return "Computer Science";

    case Informatics:
        return "Informatics";

    case MathEconomics:
        return "Math/Economics";

    case PhysicsInformatics:
        return "Physics/Info";

    case LaborTraining:
        return "Labor Training";

    default:
        return "Unknown";
    }
}

// Виведення таблиці студентів
void printStudents(const Student* students, int n)
{
    cout << "\n";
    cout << left
        << setw(5) << "No."
        << setw(15) << "Surname"
        << setw(10) << "Course"
        << setw(20) << "Specialty"
        << setw(12) << "Physics"
        << setw(15) << "Math"
        << setw(12) << "Informatics" << endl;

    cout << string(89, '-') << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left
            << setw(5) << i + 1
            << setw(15) << students[i].surname
            << setw(10) << students[i].course
            << setw(20) << getSpecialtyName(students[i].specialty)
            << setw(12) << students[i].physics
            << setw(15) << students[i].mathematics
            << setw(12) << students[i].informatics
            << endl;
    }
}

// Фізичне сортування масиву
void physicalSort(Student* students, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            bool needSwap = false;

            if (students[j].physics > students[j + 1].physics)
                needSwap = true;

            else if (students[j].physics == students[j + 1].physics &&
                students[j].course > students[j + 1].course)
                needSwap = true;

            else if (students[j].physics == students[j + 1].physics &&
                students[j].course == students[j + 1].course &&
                students[j].surname < students[j + 1].surname)
                needSwap = true;

            if (needSwap)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Сортування індексного масиву
void indexSort(const Student* students, int n, int* indexes)
{
    for (int i = 0; i < n; i++)
    {
        indexes[i] = i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int first = indexes[j];
            int second = indexes[j + 1];

            bool needSwap = false;

            if (students[first].physics > students[second].physics)
                needSwap = true;

            else if (students[first].physics == students[second].physics &&
                students[first].course > students[second].course)
                needSwap = true;

            else if (students[first].physics == students[second].physics &&
                students[first].course == students[second].course &&
                students[first].surname > students[second].surname)
                needSwap = true;

            if (needSwap)
            {
                int temp = indexes[j];
                indexes[j] = indexes[j + 1];
                indexes[j + 1] = temp;
            }
        }
    }
}