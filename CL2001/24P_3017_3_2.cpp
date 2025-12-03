#include<iostream>
using namespace std;

class store{
    int *cart;
    int length;
    int capacity;
    
    public:
    store();
    ~store();
    bool isEmpty();
    bool isFull();
    void addProduct(int);
    void addProductAt(int, int);
    void removeProduct(int);
    void sortCart();
    void reverseCart();
    void displayCart();
};

int main(){
    cout<<"24P-3017\n"<<endl;

    store cart;
    
    cart.addProduct(4509);
    cart.addProduct(9876);
    cart.addProduct(5643);
    cart.addProduct(1201);
    cart.addProduct(8732);
    cart.addProduct(3421);
    cart.addProduct(6543);
    cart.addProduct(8764);
    cart.addProduct(2132);
    cart.addProduct(4632);
    cart.displayCart();
    cart.addProductAt(7621, 2);
    cart.removeProduct(6543);
    cart.displayCart();
    cart.sortCart();
    cart.displayCart();
}

store::store(){
    capacity=50;
    cart=new int[capacity];
    length=0;
}

store::~store(){
    delete cart;
}

bool store::isEmpty(){
    if(length==0) return true;
    else return false;
}

bool store::isFull(){
    if(length==capacity) return true;
    else return false;
}

void store::addProduct(int productID){
    if(isFull()==true){
        cout<<"Cart is full, cannot add any more items."<<endl;
        return;
    }
    if(productID<0){
        cout<<"Invalid product ID."<<endl;
        return;
    }
    
    cart[length]=productID;
    length++;
    cout<<"item #"<<productID<<" has been successfully added."<<endl;
}

void store::addProductAt(int productID, int index){
    if(isFull()==true){
        cout<<"Cart is full, cannot add any more items."<<endl;
        return;
    }
    else if(isEmpty()==true && index!=0){
        cout<<"Cart is currently empty."<<endl;
    }
    else if(index<0 || index>length){
        cout<<"Invalid index, try again."<<endl;
    }

    for(int i=length;i>index;i--){
        cart[i]=cart[i-1];
    }
    length++;
    cout<<"item #"<<productID<<" successfully added at index #"<<index<<endl;
}

void store::removeProduct(int productID){
    if(isEmpty()==true){
        cout<<"Cart is currently empty."<<endl;
        return;
    }
    else if(productID<0){
        cout<<"Invalid product ID"<<endl;
        return;
    }

    for(int i=0;i<length;i++){
        if(cart[i]==productID){
            for(int j=i;j<length-1;j++){
                cart[j]=cart[j+1];
            }
            cout<<"Successfully removed item #"<<productID<<" from the cart."<<endl;
            return;
        }
        else continue;
    }

    cout<<"No such item in cart."<<endl;
}

void store::sortCart(){
    for(int i=0;i<length;i++){
        bool swapped=false;
        for(int j=0;j<length;j++){
            if(cart[j]>cart[j+1]){
                swap(cart[j], cart[j+1]);
                swapped=true;
            }
            else continue;
        }
        if(!swapped) break;
    }

    cout<<"Cart has been sorted in ascending order successfully!"<<endl;
}

void store::reverseCart(){
    int *ptr;
    ptr=&cart[length-1];
    
    cout<<"\nCart in reverse: ";
    for(int i=0;i<length;i++){
        cout<<*(ptr-i)<<" ";
    }
    cout<<endl;
}

void store::displayCart(){
    cout<<"\nCart: ";
    for(int i=0;i<length;i++){
        cout<<cart[i]<<" ";
    }
    cout<<endl;
}