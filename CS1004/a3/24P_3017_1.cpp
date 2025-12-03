#include <iostream>
using namespace std;

class Distance{
private:
    int feet;
    int inches;
    static int count;

    void simplify() {
        while (inches >= 12){
            feet++;
            inches -= 12;
        }
        while (inches < 0){
            feet--;
            inches += 12;
        }
    }

public:
    // Default constructor
    Distance(){
        feet = 0;
        inches = 0;
        count++;
    }

    // Parameterized constructor
    Distance(int f, int i){
        feet = f;
        inches = i;
        simplify();
        count++;
    }

    // Copy constructor
    Distance(const Distance &d){
        feet = d.feet;
        inches = d.inches;
        count++;
    }

    // Destructor
    ~Distance(){
        count--;
    }

    // Get user input
    void getDistance(){
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        simplify();
    }

    // Show distance
    void showDistance(){
        cout << feet << "'-" << inches << "\"" << endl;
    }

    // Overload +
    Distance operator+(Distance d){
        Distance temp;
        temp.feet = feet + d.feet;
        temp.inches = inches + d.inches;
        temp.simplify();
        return temp;
    }

    // Overload +=
    void operator+=(Distance d){
        feet = feet + d.feet;
        inches = inches + d.inches;
        simplify();
    }

    // Overload <
    bool operator<(Distance d){
        if (feet < d.feet) return true;
        else if (feet == d.feet && inches < d.inches) return true;
        else return false;
    }

    // Pre-increment
    Distance operator++(){
        inches++;
        simplify();
        return *this;
    }

    // Pre-decrement
    Distance operator--(){
        inches--;
        simplify();
        return *this;
    }

    // Friend function for <<
    friend ostream& operator<<(ostream &out, Distance d){
        out << d.feet << "'-" << d.inches << "\"";
        return out;
    }

    // Friend function for >>
    friend istream& operator>>(istream &in, Distance &d){
        cout << "Enter feet: ";
        in >> d.feet;
        cout << "Enter inches: ";
        in >> d.inches;
        d.simplify();
        return in;
    }

    // Static function to get object count
    static int getCount(){
        return count;
    }
};

// Initialize static variable
int Distance::count = 0;

int main() {
    Distance d1, d2(6, 9);
    cout << "Enter d1:\n";
    d1.getDistance();

    Distance d3 = d1 + d2;
    cout << "\nd1: ";
    d1.showDistance();
    cout << "d2: ";
    d2.showDistance();
    cout << "d3 = d1 + d2: ";
    d3.showDistance();

    d1 += d2;
    cout << "\nAfter d1 += d2: ";
    d1.showDistance();

    cout << "\nCompare d1 < d2: " << (d1 < d2 ? "Yes" : "No") << endl;

    ++d1;
    cout << "\nAfter ++d1: ";
    d1.showDistance();

    --d2;
    cout << "After --d2: ";
    d2.showDistance();

    cout << "\nUsing << operator: " << d3 << endl;

    Distance d4;
    cin >> d4;
    cout << "You entered: " << d4 << endl;

    cout << "\nTotal objects: " << Distance::getCount() << endl;

    return 0;
}
