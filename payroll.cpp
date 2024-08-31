#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Employee class definition
class Employee {
private:
    string name;
    int id;
    double hoursWorked;
    double hourlyRate;

public:
    // Constructor
    Employee(string empName, int empId, double hours, double rate)
        : name(empName), id(empId), hoursWorked(hours), hourlyRate(rate) {}

    // Function to calculate salary
    double calculateSalary() const {
        return hoursWorked * hourlyRate;
    }

    // Function to display employee details
    void display() const {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Total Salary: $" << calculateSalary() << endl;
        cout << "-------------------------------" << endl;
    }
};

// Main function
int main() {
    vector<Employee> employees;

    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++) {
        string name;
        int id;
        double hoursWorked, hourlyRate;

        cout << "Enter employee " << i + 1 << " name: ";
        cin.ignore(); // Ignore leftover newline character from previous input
        getline(cin, name);

        cout << "Enter employee " << i + 1 << " ID: ";
        cin >> id;

        cout << "Enter hours worked by " << name << ": ";
        cin >> hoursWorked;

        cout << "Enter hourly rate for " << name << ": ";
        cin >> hourlyRate;

        // Add the employee to the list
        employees.emplace_back(name, id, hoursWorked, hourlyRate);
    }

    // Display the payroll details for all employees
    cout << "\n--- Payroll Details ---\n";
    for (const auto &employee : employees) {
        employee.display();
    }

    return 0;
}
