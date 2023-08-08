#include "employees.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    EmployeeSystem empSystem("employees.txt");

    while (true) {
        cout << "Оберіть дію:" << endl;
        cout << "1. Додати співробітника" << endl;
        cout << "2. Редагувати співробітника" << endl;
        cout << "3. Видалити співробітника" << endl;
        cout << "4. Пошук за прізвищем" << endl;
        cout << "5. Пошук за віком" << endl;
        cout << "6. Пошук за першою літерою прізвища" << endl;
        cout << "7. Вивести список співробітників" << endl;
        cout << "0. Вихід" << endl;

        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            string lastName, firstName;
            int age;

            cout << "Введіть дані співробітника:" << endl;
            cout << "Прізвище: ";
            cin >> lastName;
            cout << "Ім'я: ";
            cin >> firstName;
            cout << "Вік: ";
            cin >> age;

            Employee newEmployee = { lastName, firstName, age };
            empSystem.AddEmployee(newEmployee);

            cout << "Дані співробітника успішно додано!" << endl;
            break;
        }

        case 2: {
            string lastName;

            cout << "Введіть прізвище співробітника для редагування:" << endl;
            cin >> lastName;

            empSystem.EditEmployee(lastName);
            break;
        }

        case 3: {
            string lastName;

            cout << "Введіть прізвище співробітника для видалення:" << endl;
            cin >> lastName;

            empSystem.RemoveEmployee(lastName);
            break;
        }

        case 4: {
            string lastName;

            cout << "Введіть прізвище співробітника для пошуку:" << endl;
            cin >> lastName;

            empSystem.SearchByLastName(lastName);
            break;
        }

        case 5: {
            int age;

            cout << "Введіть вік співробітників для пошуку:" << endl;
            cin >> age;

            empSystem.SearchByAge(age);
            break;
        }

        case 6: {
            char letter;

            cout << "Введіть першу літеру прізвища для пошуку:" << endl;
            cin >> letter;

            empSystem.SearchByInitialLetter(letter);
            break;
        }

        case 7: {
            empSystem.PrintAllEmployees();
            break;
        }

        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    }

    return 0;
}
