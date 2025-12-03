#include <iostream>
using namespace std;

class Car {
    string model;
    int year;
public:
    Car(string m, int y) : model(m), year(y) {
        cout << "Car Created: " << model << ", " << year << endl;
    }
    ~Car() {
        cout << "Car " << model << " destroyed." << endl;
    }
};

int main() {
    Car c1("Toyota", 2020);
    Car c2("Honda", 2022);
    return 0;
}
