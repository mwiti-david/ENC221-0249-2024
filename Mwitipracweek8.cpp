#include <iostream>
using namespace std;

class Square {
protected:
    double side;
    
public:
    Square(double s) {
        side = s;
        cout << "Square with side " << side << " created" << endl;
    }
    
    ~Square() {
        cout << "Square destroyed" << endl;
    }
    
    double getPeri() {
        return 4 * side;
    }
    
    double getArea() {
        return side * side;
    }
};

class Cube : public Square {
public:
    Cube(double s) : Square(s) {
        cout << "Cube with side " << side << " created" << endl;
    }
    
    ~Cube() {
        cout << "Cube destroyed" << endl;
    }
    
    double getArea() {
        return 6 * side * side;
    }
    
    double getVolume() {
        return side * side * side;
    }
};

int main() {
    cout << "Creating Square object:" << endl;
    Square sq(5.0);
    cout << "Perimeter: " << sq.getPeri() << endl;
    cout << "Area: " << sq.getArea() << endl;
    
    cout << "\nCreating Cube object:" << endl;
    Cube cb(3.0);
    cout << "Surface Area: " << cb.getArea() << endl;
    cout << "Volume: " << cb.getVolume() << endl;
    
    cout << "\nDestructors being called:" << endl;
    return 0;
}
