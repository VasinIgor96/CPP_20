#include "employees.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    EmployeeSystem empSystem("employees.txt");

    while (true) {
        cout << "������ ��:" << endl;
        cout << "1. ������ �����������" << endl;
        cout << "2. ���������� �����������" << endl;
        cout << "3. �������� �����������" << endl;
        cout << "4. ����� �� ��������" << endl;
        cout << "5. ����� �� ����" << endl;
        cout << "6. ����� �� ������ ������ �������" << endl;
        cout << "7. ������� ������ �����������" << endl;
        cout << "0. �����" << endl;

        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            string lastName, firstName;
            int age;

            cout << "������ ��� �����������:" << endl;
            cout << "�������: ";
            cin >> lastName;
            cout << "��'�: ";
            cin >> firstName;
            cout << "³�: ";
            cin >> age;

            Employee newEmployee = { lastName, firstName, age };
            empSystem.AddEmployee(newEmployee);

            cout << "��� ����������� ������ ������!" << endl;
            break;
        }

        case 2: {
            string lastName;

            cout << "������ ������� ����������� ��� �����������:" << endl;
            cin >> lastName;

            empSystem.EditEmployee(lastName);
            break;
        }

        case 3: {
            string lastName;

            cout << "������ ������� ����������� ��� ���������:" << endl;
            cin >> lastName;

            empSystem.RemoveEmployee(lastName);
            break;
        }

        case 4: {
            string lastName;

            cout << "������ ������� ����������� ��� ������:" << endl;
            cin >> lastName;

            empSystem.SearchByLastName(lastName);
            break;
        }

        case 5: {
            int age;

            cout << "������ �� ����������� ��� ������:" << endl;
            cin >> age;

            empSystem.SearchByAge(age);
            break;
        }

        case 6: {
            char letter;

            cout << "������ ����� ����� ������� ��� ������:" << endl;
            cin >> letter;

            empSystem.SearchByInitialLetter(letter);
            break;
        }

        case 7: {
            empSystem.PrintAllEmployees();
            break;
        }

        default:
            cout << "������� ����. ��������� �� ���." << endl;
        }
    }

    return 0;
}
