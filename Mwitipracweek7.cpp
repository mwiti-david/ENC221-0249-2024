#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int age;
    int serviceYear;
    double salary;
    
public:
    Employee(string n, int a, int sy, double s) {
        name = n;
        age = a;
        serviceYear = sy;
        salary = s;
        cout << "Employee " << name << " created" << endl;
    }
    
    ~Employee() {
        cout << "Employee " << name << " destroyed" << endl;
    }
    
    string getName() {
        return name;
    }
    
    int getAge() {
        return age;
    }
    
    int getServiceYear() {
        return serviceYear;
    }
    
    double getSalary() {
        return salary;
    }
};

int main() {
    Employee emp1("John Smith", 35, 10, 55000.50);
    Employee emp2("Mary Johnson", 28, 5, 48000.75);
    
    cout << "\nEmployee Details:" << endl;
    cout << "Name: " << emp1.getName() << endl;
    cout << "Age: " << emp1.getAge() << endl;
    cout << "Service Years: " << emp1.getServiceYear() << endl;
    cout << "Salary: $" << emp1.getSalary() << endl;
    
    cout << "\nEmployee Details:" << endl;
    cout << "Name: " << emp2.getName() << endl;
    cout << "Age: " << emp2.getAge() << endl;
    cout << "Service Years: " << emp2.getServiceYear() << endl;
    cout << "Salary: $" << emp2.getSalary() << endl;
    
    return 0;
}
