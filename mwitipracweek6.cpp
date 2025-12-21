#include <iostream>
#include <cstdlib>  
#include <ctime>  

using namespace std;

int main() {
    
    srand(time(0));
    
    int numbers[20];
    
    int oddNumbers[20];
    int evenNumbers[20];
    int oddCount = 0;
    int evenCount = 0;

    cout << "Original array of 20 numbers:" << endl;
    for (int i = 0; i < 20; i++) {
        
        numbers[i] = (rand() % 100) + 1;
        cout << numbers[i] << " ";
    }
    cout << endl << endl;
    

    for (int i = 0; i < 20; i++) {
        
        if (numbers[i] % 2 == 0) {
            evenNumbers[evenCount] = numbers[i];
            evenCount++;
        } 
        else {
            oddNumbers[oddCount] = numbers[i];
            oddCount++; 
        }
    }
    
    cout << "Odd numbers (" << oddCount << " total):" << endl;
    for (int i = 0; i < oddCount; i++) {
        cout << oddNumbers[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Even numbers (" << evenCount << " total):" << endl;
    for (int i = 0; i < evenCount; i++) {
        cout << evenNumbers[i] << " ";
    }
    cout << endl;
    
    return 0;
}