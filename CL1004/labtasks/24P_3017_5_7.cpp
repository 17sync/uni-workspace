#include <iostream>
using namespace std;
struct car;
float update_price(car, float);

struct car{
    string brand;
    int year;
    float price;
}c;

int main(){
    float discount=25, d_price;
    
    cout<<"(Limited time discount: 25%!)\n\n";
    cout<<"Enter car brand: ";
    cin>>c.brand;
    cout<<"Enter model year: ";
    cin>>c.year;
    cout<<"Enter price: $";
    cin>>c.price;

    d_price=update_price(c, discount);

    cout<<"\nNew discounted price: $"<<d_price;
}

float update_price(car c, float d){
    float new_price=((100-d)/100)*c.price;

    return new_price;
}