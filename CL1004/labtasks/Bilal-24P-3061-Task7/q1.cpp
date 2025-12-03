#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand, model;
    int year;
    double price;

public:
    Vehicle(string b = "Unkown", string m = "Unknown", int y = 0, double p = 0.0)
        : brand(b), model(m), year(y), price(p) {}

    virtual void displayInfo() {
        cout << brand << endl;
        cout << model << endl;
        cout << year << endl;
        cout << price << endl;
    }

    virtual void startEngine() {
        cout << "Engine started" << endl;
    }

    virtual double calculateDepreciation() {
        return price * 0.10;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int doors;
    string fuelType;

public:
    Car(string b, string m, int y, double p, int d, string f)
        : Vehicle(b, m, y, p), doors(d), fuelType(f) {}

    void openTrunk() {
        cout << "Trunk opened" << endl;
    }

    void playMusic() {
        cout << "Music playing" << endl;
    }

    void displayInfo() override {
        cout << brand << endl;
        cout << model << endl;
        cout << year << endl;
        cout << price << endl;
        cout << doors << endl;
        cout << fuelType << endl;
    }

    void startEngine() override {
        cout << "Car engine started" << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    string type;
    bool hasHelmet;

public:
    Motorcycle(string b, string m, int y, double p, string t, bool h)
        : Vehicle(b, m, y, p), type(t), hasHelmet(h) {}

    void doWheelie() {
        cout << "Wheelie performed" << endl;
    }

    double calculateDepreciation() override {
        return price * 0.20;
    }

    void displayInfo() override {
        cout << brand << endl;
        cout << model << endl;
        cout << year << endl;
        cout << price << endl;
        cout << type << endl;
        cout << hasHelmet << endl;
    }

    void startEngine() override {
        cout << "Motorcycle engine started" << endl;
    }
};

class Truck : public Vehicle {
private:
    double capacity;
    int axles;

public:
    Truck(string b, string m, int y, double p, double c, int a)
        : Vehicle(b, m, y, p), capacity(c), axles(a) {}

    void loadCargo() {
        cout << "Cargo loaded" << endl;
    }

    void unloadCargo() {
        cout << "Cargo unloaded" << endl;
    }

    void displayInfo() override {
        cout << brand << endl;
        cout << model << endl;
        cout << year << endl;
        cout << price << endl;
        cout << capacity << endl;
        cout << axles << endl;
    }

    void startEngine() override {
        cout << "Truck engine started" << endl;
    }
};

class VehicleShowroom {
private:
    Vehicle* vehicles[10];
    int count;

public:
    VehicleShowroom() : count(0) {}

    void addVehicle(Vehicle* v) {
        if (count < 10)
            vehicles[count++] = v;
    }

    void showAll() {
        for (int i = 0; i < count; i++)
            vehicles[i]->displayInfo();
    }

    void startAllEngines() {
        for (int i = 0; i < count; i++)
            vehicles[i]->startEngine();
    }
};

int main() {
    VehicleShowroom showroom;

    Car c1("Toyota", "Corolla", 2020, 25000, 4, "Petrol");
    Motorcycle m1("Honda", "CD70", 2022, 90000, "Standard", true);
    Truck t1("Volvo", "FH16", 2019, 15000000, 25.5, 4);

    showroom.addVehicle(&c1);
    showroom.addVehicle(&m1);
    showroom.addVehicle(&t1);

    showroom.showAll();
    showroom.startAllEngines();

    return 0;
}
