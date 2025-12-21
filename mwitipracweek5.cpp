#include <iostream>
using namespace std;


double& findLargest(double& num1, double& num2, double& num3) {

    if (num1 >= num2 && num1 >= num3) {
        return num1;
    }
    else if (num2 >= num1 && num2 >= num3) {
        return num2;
    }
    
    else {
        return num3;  
    }
}

int main() {
    
    double first = 0.75;   
    double second = 0.5;   
    double third = 0.833; 
    
    cout << "We have three fractions:\n";
    cout << "First:  " << first << endl;
    cout << "Second: " << second << endl;
    cout << "Third:  " << third << endl;
    cout << endl;
    
    double& biggest = findLargest(first, second, third);
    
    cout << "The largest fraction is: " << biggest << endl;
    
    return 0;
};