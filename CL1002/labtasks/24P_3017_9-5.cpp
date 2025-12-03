#include <iostream>
using namespace std;

int main() {

	//Declaration of variables
    int i, j; 
    
	//Asking for i and j
    cout << "Enter the value of i: ";
    cin >> i;
    cout << "Enter the value of j: ";
    cin >> j;

	//Displaying end result
    double s = 0.0; 
    double term = 1.0; 

    for (int k = 0; k <= j; ++k) {
        s += term; 

        
        term = term * i / (k + 1); 
    }

    cout << "The sum of the series is: " << s << endl;

    return 0;
}
