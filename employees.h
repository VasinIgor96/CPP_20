#pragma once

#include <vector>
#include <string>

struct Employee {
    std::string lastName;
    std::string firstName;
    int age;
};

class EmployeeSystem {
private:
    std::vector<Employee> employees;
    std::string filename;

public:
    EmployeeSystem(const std::string& filename);

    void LoadEmployees();
    void SaveEmployees();

    void AddEmployee(const Employee& emp);
    void EditEmployee(const std::string& lastName);
    void RemoveEmployee(const std::string& lastName);

    void SearchByLastName(const std::string& lastName);
    void SearchByAge(int age);
    void SearchByInitialLetter(char letter);

    void PrintAllEmployees();
};
