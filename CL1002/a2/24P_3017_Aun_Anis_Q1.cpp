#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of variable storing the 3 digit number
    int num;
    bool tdn = false;

    //Asking for 3 digit number
    do{
    cout<<"Enter a 3 digit integer: "; cin>>num;
    if (num>=100 && num<=999){
        tdn = true;
    }
    else{
        cout<<"\n---ERROR: Entered integer is not 3 digits---\n\n";
    }
    }while(tdn == false);

    //Computing word for display
    num%=10;
    if (num==1 || num==4 || num==7){
        cout<<"\nCool";
    }
    else if (num==2 || num==5 || num==8){
        cout<<"\nModerate";
    }
    else if (num==3 || num==6 || num==9){
        cout<<"\nWarm";
    }
    else if (num==0){
        cout<<"\nNeutral";
    }

}