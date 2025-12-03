 #include<iostream>
 using namespace std;
 int main(){

//Declaration of variables for rows, columns, spaces and rows
int i,j,k;
int row;

//Asking for number of rows
cin>>row;

//Displaying pattern
 for(i = 1; i <= row; i++) {
    for(j = 1; j <= row - i; j++) {
        cout << " "; 
    }
    for(j = 1; j <= 2 * i - 1; j++) {
        cout << "*"; 
    }
    cout << endl;
}


for(i = row - 1; i >= 1; i--) {
    for(j = 1; j <= row - i; j++) {
        cout << " "; 
    }
    for(j = 1; j <= 2 * i - 1; j++) {
        cout << "*"; 
    }
    cout << endl;
    }
 }
