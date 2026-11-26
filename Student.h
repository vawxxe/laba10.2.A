
#pragma once

#include <string>

using namespace std;

// Перелік спеціальностей
enum Specialty
{
    ComputerScience,
    Informatics,
    MathEconomics,
    PhysicsInformatics,
    LaborTraining
};

// Структура студента
struct Student
{
    string surname;
    int course;
    Specialty specialty;
    int physics;
    int mathematics;
    int informatics;
};

// Оголошення функцій
Student* createStudents(int n);
void inputStudents(Student* students, int n);
void printStudents(const Student* students, int n);

void physicalSort(Student* students, int n);
void indexSort(const Student* students, int n, int* indexes);

string getSpecialtyName(Specialty specialty);

