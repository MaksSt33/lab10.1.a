#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

// Перелік спеціальностей
enum Specialnist { KN, PM, FI };
string specialnistStr[] = { "КН", "ПМ", "ФІ" };

// Структура студента з об'єднанням для оцінок
struct Student {
    string prizv;
    int kurs;
    Specialnist specialnist;
    union {
        struct {
            int ocinka_fizyka;
            int ocinka_matematyka;
            int ocinka_informatyka;
        };
        int ocinki[3]; // Альтернативне представлення оцінок у вигляді масиву
    };
};

// Функція для створення масиву студентів
void CreateStudents(Student* students, const int N) {
    int specialnist;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cout << " Прізвище: ";
        cin >> students[i].prizv;
        cout << " Курс: ";
        cin >> students[i].kurs;
        cout << " Спеціальність (0 - КН, 1 - ПМ, 2 - ФІ): ";
        cin >> specialnist;
        students[i].specialnist = (Specialnist)specialnist;

        // Введення оцінок через окремі поля об'єднання
        cout << " Оцінка з фізики: ";
        cin >> students[i].ocinka_fizyka;
        cout << " Оцінка з математики: ";
        cin >> students[i].ocinka_matematyka;
        cout << " Оцінка з інформатики: ";
        cin >> students[i].ocinka_informatyka;
        cout << endl;
    }
}

// Функція для виведення таблиці студентів
void PrintStudents(const Student* students, const int N) {
    cout << "=============================================================================================================" << endl;
    cout << "| № | Прізвище        | Курс | Спеціальність | Оцінка з фізики | Оцінка з математики | Оцінка з інформатики |" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "|" << setw(2) << i + 1
            << " |  " << setw(15) << left << students[i].prizv
            << "|   " << setw(3) << students[i].kurs
            << "|" << setw(15) << specialnistStr[students[i].specialnist]
            << "|   " << setw(14) << students[i].ocinka_fizyka
            << "|   " << setw(18) << students[i].ocinka_matematyka
            << "| " << setw(20) << students[i].ocinka_informatyka << " |" << endl;
    }
    cout << "=============================================================================================================" << endl;
}

// Функція для обчислення найбільшого середнього бала серед студентів
double FindMaxAverage(const Student* students, const int N) {
    double maxAverage = 0;
    for (int i = 0; i < N; i++) {
        double average = (students[i].ocinki[0] + students[i].ocinki[1] + students[i].ocinki[2]) / 3.0;
        if (average > maxAverage) {
            maxAverage = average;
        }
    }
    return maxAverage;
}

// Функція для обчислення відсотка студентів, які отримали "5" або "4" з фізики
double PhysicsPercentage(const Student* students, const int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].ocinka_fizyka == 4 || students[i].ocinka_fizyka == 5) {
            count++;
        }
    }
    return (double)count / N * 100;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];

    CreateStudents(students, N);
    PrintStudents(students, N);

    double maxAverage = FindMaxAverage(students, N);
    cout << "Найбільший середній бал серед студентів: " << maxAverage << endl;

    double physicsHighGradesPercentage = PhysicsPercentage(students, N);
    cout << "Відсоток студентів, які отримали '5' або '4' з фізики: " << PhysicsPercentage << "%" << endl;

    delete[] students;
    return 0;
}
