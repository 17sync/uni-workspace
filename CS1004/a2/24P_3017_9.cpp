#include <iostream>
using namespace std;

class Vehicle {
public:
    void startEngine() {
        cout << "Vehicle engine started." << endl;
    }
};

class Airplane : public Vehicle {
public:
    void startEngine() {
        cout << "Airplane engine started with turbine." << endl;
    }
};

int main() {
    Vehicle v;
    Airplane a;

    v.startEngine();        // Base class function
    a.startEngine();        // Overridden function in derived class

    Vehicle* vp = &a;
    vp->startEngine();      // Still calls Vehicle's version (no virtual used)

    return 0;
}
