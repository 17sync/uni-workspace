#include <iostream>
using namespace std;

int main ()
{
    
    //Declaration of a+ib variables for 2 complex numbers
    int re1, re2;
    int im1, im2;

    //Declaration of variables for arithmetic operations
    int addre, addim;
    int subre, subim;
    int multre, multim;

    //Asking for real and imaginary parts
    cout<<"Enter real and imaginary parts of the first complex number: ";
    cin>>re1; cin>>im1;
    cout<<"Enter real and imaginary parts of the second complex number: ";
    cin>>re2; cin>>im2;

    //Performing arithemetic operations with the complex numbers
    addre = re1+re2; addim = im1+im2;
    subre = re1-re2; subim = im1-im2;
    multre = (re1*re2)+(-1*(im1*im2));                 //-1 mutltipied since i*i will make -1 which will be added to the real part
    multim = (im1*re2)+(re1*im2);

    //Displaying the end results
    cout<<"\n\nResult of addition: "<<addre<<" + "<<addim<<"i";
    cout<<"\nResult of subtraction: "<<subre<<" + "<<subim<<"i";
    cout<<"\nResult of multiplication: "<<multre<<" + "<<multim<<"i";

}