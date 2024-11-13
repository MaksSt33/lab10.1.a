#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

// ������ ��������������
enum Specialnist { KN, PM, FI };
string specialnistStr[] = { "��", "��", "Բ" };

// ��������� �������� � ��'�������� ��� ������
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
        int ocinki[3]; // ������������� ������������� ������ � ������ ������
    };
};

// ������� ��� ��������� ������ ��������
void CreateStudents(Student* students, const int N) {
    int specialnist;
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;
        cout << " �������: ";
        cin >> students[i].prizv;
        cout << " ����: ";
        cin >> students[i].kurs;
        cout << " ������������� (0 - ��, 1 - ��, 2 - Բ): ";
        cin >> specialnist;
        students[i].specialnist = (Specialnist)specialnist;

        // �������� ������ ����� ����� ���� ��'�������
        cout << " ������ � ������: ";
        cin >> students[i].ocinka_fizyka;
        cout << " ������ � ����������: ";
        cin >> students[i].ocinka_matematyka;
        cout << " ������ � �����������: ";
        cin >> students[i].ocinka_informatyka;
        cout << endl;
    }
}

// ������� ��� ��������� ������� ��������
void PrintStudents(const Student* students, const int N) {
    cout << "=============================================================================================================" << endl;
    cout << "| � | �������        | ���� | ������������� | ������ � ������ | ������ � ���������� | ������ � ����������� |" << endl;
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

// ������� ��� ���������� ���������� ���������� ���� ����� ��������
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

// ������� ��� ���������� ������� ��������, �� �������� "5" ��� "4" � ������
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
    cout << "������ ������� ��������: ";
    cin >> N;

    Student* students = new Student[N];

    CreateStudents(students, N);
    PrintStudents(students, N);

    double maxAverage = FindMaxAverage(students, N);
    cout << "��������� �������� ��� ����� ��������: " << maxAverage << endl;

    double physicsHighGradesPercentage = PhysicsPercentage(students, N);
    cout << "³������ ��������, �� �������� '5' ��� '4' � ������: " << PhysicsPercentage << "%" << endl;

    delete[] students;
    return 0;
}
