#include "employees.h"
#include <fstream>
#include <iostream>
#include <algorithm>

EmployeeSystem::EmployeeSystem(const std::string& filename) : filename(filename) {
    LoadEmployees();
}

void EmployeeSystem::LoadEmployees() {
    employees.clear();
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cout << "Помилка відкриття файлу!" << std::endl;
        return;
    }

    Employee emp;
    while (inputFile >> emp.lastName >> emp.firstName >> emp.age) {
        employees.push_back(emp);
    }

    inputFile.close();
}

void EmployeeSystem::SaveEmployees() {
    std::ofstream outputFile(filename);

    for (const Employee& emp : employees) {
        outputFile << emp.lastName << " " << emp.firstName << " " << emp.age << std::endl;
    }

    outputFile.close();
}

void EmployeeSystem::AddEmployee(const Employee& emp) {
    employees.push_back(emp);
    SaveEmployees();
}

void EmployeeSystem::EditEmployee(const std::string& lastName) {
    for (Employee& emp : employees) {
        if (emp.lastName == lastName) {
            std::cout << "Введіть нові дані співробітника:" << std::endl;
            std::cout << "Ім'я: ";
            std::cin >> emp.firstName;
            std::cout << "Вік: ";
            std::cin >> emp.age;

            SaveEmployees();
            return;
        }
    }

    std::cout << "Співробітника з таким прізвищем не знайдено." << std::endl;
}

void EmployeeSystem::RemoveEmployee(const std::string& lastName) {
    auto emp = std::remove_if(employees.begin(), employees.end(),
        [&lastName](const Employee& e) { return e.lastName == lastName; });

    if (emp != employees.end()) {
        employees.erase(emp, employees.end());
        SaveEmployees();
        std::cout << "Співробітника видалено." << std::endl;
    }
    else {
        std::cout << "Співробітника з таким прізвищем не знайдено." << std::endl;
    }
}

void EmployeeSystem::SearchByLastName(const std::string& lastName) {
    for (const Employee& emp : employees) {
        if (emp.lastName == lastName) {
            std::cout << "Прізвище: " << emp.lastName << std::endl;
            std::cout << "Ім'я: " << emp.firstName << std::endl;
            std::cout << "Вік: " << emp.age << std::endl;
            return;
        }
    }

    std::cout << "Співробітника з таким прізвищем не знайдено." << std::endl;
}

void EmployeeSystem::SearchByAge(int age) {
    for (const Employee& emp : employees) {
        if (emp.age == age) {
            std::cout << "Прізвище: " << emp.lastName << std::endl;
            std::cout << "Ім'я: " << emp.firstName << std::endl;
            std::cout << "Вік: " << emp.age << std::endl;
        }
    }
}

void EmployeeSystem::SearchByInitialLetter(char letter) {
    for (const Employee& emp : employees) {
        if (emp.lastName[0] == letter) {
            std::cout << "Прізвище: " << emp.lastName << std::endl;
            std::cout << "Ім'я: " << emp.firstName << std::endl;
            std::cout << "Вік: " << emp.age << std::endl;
        }
    }
}

void EmployeeSystem::PrintAllEmployees() {
    for (const Employee& emp : employees) {
        std::cout << "Прізвище: " << emp.lastName << std::endl;
        std::cout << "Ім'я: " << emp.firstName << std::endl;
        std::cout << "Вік: " << emp.age << std::endl;
        std::cout << "--------------------" << std::endl;
    }
}
