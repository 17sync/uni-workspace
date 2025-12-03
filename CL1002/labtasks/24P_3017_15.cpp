#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void filegen();

int main() 
{
    filegen();
    return 0;
}

void filegen() 
{ 
    string rolln;
    cout<<"What is your Roll #? ";
    cin>>rolln;

    ofstream outFile(rolln + ".txt"); 
    if(outFile.is_open()) 
    {
        string name, hobby;
        int age[5]; 
        int ages;

        cout<<"What is your name? ";
        cin.ignore(); 
        getline(cin, name);
        outFile<<"Name: "<<name<<endl;

        outFile<<"Roll #: "<<rolln<<endl;

        cout<<"What are your hobbies? ";
        getline(cin, hobby);
        outFile<<"Hobbies: "<<hobby<<endl;

       
        cout<<"Select number of ages (max = 5): "<<endl;
        cin>> ages;
        if (ages>5)
         {
            ages=5; 
        }
        for (int i=0; i<ages; i++) 
        {
            cout<<"Enter age: "<<(i+1)<<": ";
            cin>>age[i];
        }

        
        outFile<<"Ages: ";
        for (int i=0; i<ages; i++)
         {
            outFile<<age[i];
            if (i<ages-1)
             {
                outFile<<", "; 
            }
        }
        outFile<<endl;

        outFile.close();
        cout<<"Data transferred to "<<rolln<<" successfully.txt"<<endl;
    } else {
        cerr<<"File couldn't be created."<< endl;
    }
}


