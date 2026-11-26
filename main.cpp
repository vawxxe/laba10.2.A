#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    while (cin.fail() || n <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid number! Enter again: ";
        cin >> n;
    }

    Student* students = createStudents(n);

    inputStudents(students, n);

    int choice;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Show students" << endl;
        cout << "2. Physical sorting" << endl;
        cout << "3. Index sorting" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        while (cin.fail() || choice < 0 || choice > 3)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice! Enter 0-3: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            printStudents(students, n);
            break;

        case 2:
            physicalSort(students, n);
            cout << "\nStudents after physical sorting:" << endl;
            printStudents(students, n);
            break;

        case 3:
        {
            int* indexes = new int[n];

            indexSort(students, n, indexes);

            cout << "\nStudents after index sorting:" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << "\nStudent " << i + 1 << ":" << endl;

                Student temp = students[indexes[i]];
                printStudents(&temp, 1);
            }

            delete[] indexes;
            break;
        }

        case 0:
            cout << "Program finished." << endl;
            break;
        }

    } while (choice != 0);

    delete[] students;

    return 0;
}
