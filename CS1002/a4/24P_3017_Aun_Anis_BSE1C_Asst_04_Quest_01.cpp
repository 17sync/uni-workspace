#include <iostream>
using namespace std;

int main() 
{
    
    //Declaration of arrays and pointers storing different products
    const char* category[3]={"Dairy", "Fruits", "Grains"};    
    const char* pdairy[2]={"butter", "yoghurt"};
    int bdairy[2][3]={{3, 7, 12}, {1, 6}}; 
    const char* pfruit[2]={"apple", "bannana"};           //pointer to maneuver between batches
    int bfruit[2][2]={{5, 10}, {2, 8}};  
    const char* pgrain[2]={"wheat", "barley"};
    int bgrain[2][2]={{4, 11}, {9, 13}};  

    //Displaying products category wise
    cout<<"Produts Available:\n"<<endl;
   
    for (int i=0; i<3; i++) {
        cout<<"\nCategory: "<<category[i]<<endl;  
         if (i==0) {
            for (int j = 0; j < 2; j++) { 
                cout<<"Product: "<<pdairy[j]<<endl;
                for (int k=0; k<(j == 0 ? 3 : 2); k++) {  
                
                    cout<<"Batch "<<k+1<<": "<<bdairy[j][k]<<" days till expiry"<<endl;
                }
            }
        }

       
        else if (i==1) {
            for (int j=0; j<2; j++) {  
                cout<<"Product: "<<pfruit[j]<<endl;
                for (int k=0; k<2; k++) { 
                
                    cout<<"Batch "<< k+1 <<": "<<bfruit[j][k]<<" days till expiry"<<endl;
                }
            }
        }

       
        else if (i==2) {
            for (int j=0; j<2; j++) {  
                cout<< "Product: "<< pgrain[j]<<endl;
                for (int k=0; k<2; k++) {  
                
                    cout<<"Batch "<<k+1<<": "<<bgrain[j][k]<<" days till expiry"<< endl;
                }
            }
        }

        cout << endl;  
    }
    
    //Displaying expiration dates of each batch
    cout << "Expiration Check:" << endl;
   

    for (int i = 0; i < 2; i++) {  
        for (int j = 0; j < (i == 0 ? 3 : 2); j++) {  
        
            int expirytime=(i==0 ? bdairy[i][j] : bdairy[i][j]);
            if (expirytime<=0) {
                cout<<pdairy[i]<<" Batch "<<j+1<<" has expired!"<<endl;
            } else if (expirytime<=5) {
                cout<<pdairy[i]<<" Batch "<<j+1<<" is nearing expiration date!"<<endl;
            } else {
                cout<<pdairy[i]<<" Batch "<<j+1<<" is good for sale!"<<endl;
            }
        }
    }

    for (int i=0; i<2; i++) {  
        for (int j = 0; j < 2; j++) {  
            int expirytime=bfruit[i][j];
            if (expirytime<=0) {
                cout<<pfruit[i]<<" Batch "<<j+1<<" has expired!"<< endl;
            } else if (expirytime<=5) {
                cout<<pfruit[i]<<" Batch "<< j+1 <<" is nearing expiration date!"<< endl;
            } else {
                cout<<pfruit[i]<<" Batch "<< j+1 <<" is good for sale!"<< endl;
            }
        }
    }

  for (int i=0; i<2; i++) {  
    for (int j=0; j<2; j++) {  
        int expirytime=bgrain[i][j];  
        if (expirytime<=0) {
            cout<<pgrain[i]<<" Batch "<<j+1<<" has expired!"<<endl;
        } else if (expirytime <= 5) {
            cout<<pgrain[i]<<" Batch "<<j+1<< " is nearing expiration date!"<<endl;
        } else {
            cout<<pgrain[i]<<" Batch "<<j+1<<" is good for sale!"<<endl;
        }
    }
}

    cout<<"\n---Warehouse Status END---"<<endl;

}
