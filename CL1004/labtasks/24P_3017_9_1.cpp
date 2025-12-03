#include<iostream>
using namespace std;

class coffeeorder{
    protected:
    float price, size;
    public:
    coffeeorder(){
        cout<<"\n\nEnter the size of the coffee: ";
        cin>>size;
        cout<<"Enter the price of a single ounce: $";
        cin>>price;
    }

    void process_order(){
        cout<<"\nYour total is: $"<<price*size;
    }
};

class customorder: public coffeeorder{
    public:
    void process_order(){
        cout<<"\nThank you for choosing us, enjoy your coffee! :)";
        coffeeorder:: process_order();
    }
};

int main(){
    cout<<"Basic order: ";
    coffeeorder c1;
    c1.process_order();
    cout<<"\n\nCustom order: ";
    customorder c2;
    c2.process_order();
}