// employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
protected:
    string firstName;
    char initial;
    string lastName;
public:
    Employee(string fn, char init, string ln);
    virtual double calculatePay() = 0;
    void display();
};

#endif

// salaryemployee.h
#ifndef SALARYEMPLOYEE_H
#define SALARYEMPLOYEE_H

class SalaryEmployee : public Employee {
private:
    double monthlySalary;
public:
    SalaryEmployee(string fn, char init, string ln, double salary);
    double calculatePay();
};

#endif

// hourlyemployee.h
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(string fn, char init, string ln, double rate, int hours);
    double calculatePay();
};

#endif

// employee.cpp
#include <iostream>

Employee::Employee(string fn, char init, string ln) {
    firstName = fn;
    initial = init;
    lastName = ln;
}

void Employee::display() {
    cout << firstName << " " << initial << ". " << lastName << endl;
}

// salaryemployee.cpp
SalaryEmployee::SalaryEmployee(string fn, char init, string ln, double salary) 
    : Employee(fn, init, ln) {
    monthlySalary = salary;
}

double SalaryEmployee::calculatePay() {
    return monthlySalary;
}

// hourlyemployee.cpp
HourlyEmployee::HourlyEmployee(string fn, char init, string ln, double rate, int hours) 
    : Employee(fn, init, ln) {
    hourlyRate = rate;
    hoursWorked = hours;
}

double HourlyEmployee::calculatePay() {
    return hourlyRate * hoursWorked;
}

// main.cpp
int main() {
    SalaryEmployee emp1("John", 'A', "Smith", 5000.0);
    HourlyEmployee emp2("Mary", 'B', "Johnson", 25.0, 160);
    
    cout << "Salary Employee: ";
    emp1.display();
    cout << "Monthly Pay: $" << emp1.calculatePay() << endl << endl;
    
    cout << "Hourly Employee: ";
    emp2.display();
    cout << "Monthly Pay: $" << emp2.calculatePay() << endl << endl;
    
    Employee* ptr;
    
    ptr = &emp1;
    cout << "Using polymorphism:" << endl;
    ptr->display();
    cout << "Pay: $" << ptr->calculatePay() << endl << endl;
    
    ptr = &emp2;
    ptr->display();
    cout << "Pay: $" << ptr->calculatePay() << endl;
    
    return 0;
}
