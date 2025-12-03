#include<iostream>
using namespace std;

struct stationNode{
    string name;
    int id;
    stationNode *next;
    stationNode *prev;

    stationNode(string n, int idNum):name(n), id(idNum), next(nullptr), prev(nullptr){}
};

struct passengerNode{
    int id;
    passengerNode *next;

    passengerNode(int idNum):id(idNum), next(nullptr){}
};

class SR02{
    public:
    stationNode *head;
    stationNode *tail;

    SR02():head(nullptr), tail(nullptr){
        string defaultStations[31]={"Chamkani", "Sardar Garhi", "Chughal Pura", "Faisal Colony", "Old Haji Camp", "Lahore Adda", "Gulbahar Chowk", "Hashtnagri",
        "Malik Saad Shaheed", "Khyber Bazar", "Shoba Bazar", "Dabgari Gardens", "Railway Station", "FC Chowk", "Saddar Bazar", "Mall Road", "Tehkal Payyan", 
        "Tehkal Bala", "Abdara Road", "University Town", "University of Peshawar", "Islamia College", "Board Bazar", "Mall of Hayatabad", "Bab-e-Peshawar", 
        "Hayatabad Phase 3", "Tatara Park", "PDA", "Hospital Chowk", "Karkhano Market"};
        
        for(int i=0;i<31;i++){
            int idNum=1000+rand()%9000;                // random 4 digit id for every station
            addStation(defaultStations[i], idNum);
        }
    }

    virtual ~SR02(){
        stationNode *temp=head;
        
        while(temp!=nullptr){
            stationNode *temp2=temp->next;
            delete temp;
            temp=temp2;
        }

        head=tail=nullptr;
    }

    void addStation(string name, int idNum){                           // pushBack
        stationNode *newStation=new stationNode(name, idNum);
        
        if(head==nullptr){
            head=tail=newStation;
            return;
        }

        tail->next=newStation;
        newStation->prev=tail;
        tail=newStation;
    }

    void removeStation(int idNum){
        if(head==nullptr){
            cout<<"\n\nNo such station exists."<<endl;
            return;
        }

        if(head->id==idNum && head->next==nullptr){
            delete head;
            head=tail=nullptr;

            cout<<"\n\nStation successfully removed."<<endl;
            return;
        }

        if(tail->id==idNum){
            stationNode *temp=tail;
            
            tail=tail->prev;
            tail->next=nullptr;
            
            delete temp;
            cout<<"\n\nStation successfully removed."<<endl;
            return;
        }

        stationNode *temp=head;
        stationNode *prev;
        while(temp!=nullptr){
            prev=temp;
            temp=temp->next;

            if(temp->id==idNum){
                prev->next=temp->next;
                temp->next->prev=prev;
                
                delete temp;
                cout<<"\n\nStation successfully removed."<<endl;
                return;
            }
        }

        cout<<"\n\nNo such station exists"<<endl;
    }

    void displayRouteMap(){                             // since theres inheritance no need for a separate display method for ER01
        stationNode *temp=head;
        while(temp!=nullptr){
            if(temp->next==nullptr){
                cout<<temp->name<<" || "<<temp->id<<endl;
                break;
            }
            cout<<temp->name<<" || "<<temp->id<<" <-> ";
            temp=temp->next;
        }
        cout<<endl;
    }

    int calculateFare(string from, string to){                  // bus type decided in main
        int perStation=70/31;
        int totalFare=0;

        stationNode *start=head;
        stationNode *end=head;
        while(start!=nullptr && end!=nullptr){
            if(start->name!=from) start=start->next;
            if(end->name!=to) end=end->next;
            if(start->name==from && end->name==to) break;
            if(start==nullptr || end==nullptr){
                cout<<"\n\nInvalid entries, cannot calculate fare."<<endl;
                return -1;
            }
        }

        while(start!=end){
            totalFare+=perStation;
            start=start->next;            
        }

        return totalFare;
    }

    int calculateTravelTime(string from, string to){               // bus type decided in main
        int timePerStation=137;
        int travelTime=0;

        stationNode *start=head;
        stationNode *end=head;
        while(start!=nullptr && end!=nullptr){
            if(start->name!=from) start=start->next;
            if(end->name!=to) end=end->next;
            if(start->name==from && end->name==to) break;
            if(start==nullptr || end==nullptr){
                cout<<"\n\nInvalid entries, cannot calculate fare."<<endl;
                return -1;
            }
        }

        while(start!=end){
            travelTime+=timePerStation;
            start=start->next;
        }

        return travelTime;                                                      // for comparison
    }

    void reverseRoute(){
        if(head==nullptr || head==tail) return;

        stationNode *temp=head;
        stationNode *temp2=nullptr;

        while(temp!=nullptr){
            temp2=temp->prev;
            temp->prev=temp->next;
            temp->next=temp2;
            temp=temp->prev;
        }

        if(temp2!=nullptr){
            head=temp2->prev;
        }

        cout<<"\n\nSuccessfully reversed route."<<endl;
    }

    void showNextStation(string current, string direction){
        stationNode *curr=head;
    
        while(curr!=nullptr && curr->name!=current){
            curr=curr->next;
        }
        if(curr==nullptr){
            cout<<"\n\nInvalid input, try again."<<endl;
            return;
        }

        if(direction=="forward") cout<<"\n\n"<<curr->next->name<<endl;
        else cout<<"\n\n"<<curr->prev->name<<endl;
    }

    void clearRoute(){                  // helper function so displayRoute() works correctly for both routes
        stationNode *temp=head;
        while (temp!=nullptr){
            stationNode *temp2=temp->next;
            delete temp;
            temp=temp2;
        }
        head=tail=nullptr;
    }
};

class ER01: public SR02{        // subset of SR02
    stationNode *head;
    stationNode *tail;
    
    public:
    ER01():head(nullptr), tail(nullptr){
        clearRoute();

        string defaultStations[11]={"Chamkani", "Sardar Garhi", "Lahore Adda", "Hashtnagri", "Malik Saad Shaheed", "Khyber Bazar", "Dabgari Gardens", "Saddar Bazar", 
        "University of Peshawar", "Mall of Hayatabad", "Karkhano Market"};
        
        for(int i=0;i<11;i++){
            int id=1000+rand()%9000;                
            addStation(defaultStations[i], id);
        }
    }

    ~ER01() override{
        stationNode *temp=head;
        
        while(temp!=nullptr){
            stationNode *temp2=temp->next;
            delete temp;
            temp=temp2;
        }

        head=tail=nullptr;
    }

    int calculateFare(string from, string to){                  
        int perStation=70/11;                           // lesser stations, faster travel times so more costly per station
        int totalFare=0;

        stationNode *start=head;
        stationNode *end=head;
        while(start!=nullptr && end!=nullptr){
            if(start->name!=from) start=start->next;
            if(end->name!=to) end=end->next;
            if(start->name==from && end->name==to) break;
            if(start==nullptr || end==nullptr){
                cout<<"\n\nInvalid entries, cannot calculate fare."<<endl;
                return -1;
            }
        }

        while(start!=end){
            totalFare+=perStation;
            start=start->next;            
        }

        return totalFare;
    }

    int calculateTravelTime(string from, string to){               
        int timePerStation=120;
        int travelTime=0;

        stationNode *start=head;
        stationNode *end=head;
        while(start!=nullptr && end!=nullptr){
            if(start->name!=from) start=start->next;
            if(end->name!=to) end=end->next;
            if(start->name==from && end->name==to) break;
            if(start==nullptr || end==nullptr){
                cout<<"\n\nInvalid entries, cannot calculate fare."<<endl;
                return -1;
            }
        }

        while(start!=end){
            travelTime+=timePerStation;
            start=start->next;
        }

        return travelTime;
    }
};


void findBestRoute(SR02 sr, ER01 er, string to, string from){
    if(sr.calculateTravelTime(to, from)>=er.calculateTravelTime(to, from)){
        cout<<"\n\nSR02 is the better route"<<endl;
        return;
    }
    else{
        cout<<"\n\nER01 is the better route"<<endl;
        return;
    }
    
}

int main(){
    SR02 sr;
    ER01 er;
    
    char choice;
    do{
        cout<<"\n\n\n======================================================="<<endl;
        cout<<"       Peshawar BRT Network Management System"<<endl;
        cout<<"======================================================="<<endl;
        cout<<"    [1] Add Station to Route\n";
        cout<<"    [2] Remove Station from Route\n";
        cout<<"    [3] Display Full Map (SR-02)\n";
        cout<<"    [4] Display Express Map (ER-01)\n";
        cout<<"    [5] Calculate Fare (SR/ER)\n";
        cout<<"    [6] Calculate Travel Time (SR/ER)\n";
        cout<<"    [7] Find Best Route (Compare SR vs ER)\n";
        cout<<"    [8] Reverse Route (Chamkani <-> Karkhano)\n";
        cout<<"    [9] Show Next Station (given current + direction)\n";
        cout<<"    [0] Meet-Up Simulation (Two Users)\n";
        cout<<"------------------------------------------------------"<<endl;
        cout<<"    [q] Quit Application\n";
        cout<<"======================================================"<<endl;
        cout<<"Enter choice: "; cin>>choice;

        switch(choice){
            case '1':{
                int subChoice;
                cout<<"\n\nSelect Route:\n\n";
                cout<<"[1] SR02"<<endl;
                cout<<"[2] ER01"<<endl; cin>>subChoice;

                if(subChoice==1){
                    string name;
                    int id;
                    cout<<"\nEnter station name: "; cin>>name;
                    cout<<"Enter station id: "; cin>>id;
                    sr.addStation(name, id);
                }
                else if(subChoice==2){
                    string name;
                    int id;
                    cout<<"\nEnter station name: "; cin>>name;
                    cout<<"Enter station id: "; cin>>id;
                    er.addStation(name, id);
                }
                else cout<<"\nInvalid Input try again."<<endl;

                break;
            }
            case '2':{
                int subChoice;
                cout<<"\n\nSelect Route:\n\n";
                cout<<"[1] SR02"<<endl;
                cout<<"[2] ER01"<<endl; cin>>subChoice;

                if(subChoice==1){
                    int id;
                    cout<<"\nEnter station id: "; cin>>id;
                    sr.removeStation(id);
                }
                else if(subChoice==2){
                    int id;
                    cout<<"\nEnter station id: "; cin>>id;
                    er.removeStation(id);
                }
                else cout<<"\nInvalid Input try again."<<endl;

                break;
            }
            case '3':{
                cout<<endl;
                cout<<"SR02 Route:\n\n";
                sr.displayRouteMap();

                break;
            }
            case '4':{
                cout<<endl;
                cout<<"ER01 Route:\n\n";
                er.displayRouteMap();

                break;
            }
            case '5':{
                int subChoice;
                cout<<"\n\nSelect Route:\n\n";
                cout<<"[1] SR02"<<endl;
                cout<<"[2] ER01"<<endl; cin>>subChoice;
                
                if(subChoice==1){
                    string from; string to;
                    cout<<"\nEnter starting station: "; cin>>from;
                    cout<<"Enter destination station: "; cin>>to;

                    cout<<"\nTotal fare: "<<sr.calculateFare(from, to)<<endl;
                }
                else if(subChoice==2){
                    string from; string to;
                    cout<<"\nEnter starting station: "; cin>>from;
                    cout<<"Enter destination station: "; cin>>to;
                    
                    cout<<"\nTotal fare: "<<er.calculateFare(from, to)<<endl;
                }
                else cout<<"\nInvalid Input try again."<<endl;

                break;
            }
            case '6':{
                int subChoice;
                cout<<"\n\nSelect Route:\n\n";
                cout<<"[1] SR02"<<endl;
                cout<<"[2] ER01"<<endl; cin>>subChoice;
                
                if(subChoice==1){
                    string from; string to;
                    cout<<"\nEnter starting station: "; cin>>from;
                    cout<<"Enter destination station: "; cin>>to;

                    int travelTime=sr.calculateTravelTime(from, to);
                    
                    int hours=travelTime/3600;
                    int mins=(travelTime%3600)/60;
                    int seconds=travelTime%60;

                    cout<<"\nTravel Time: "<<hours<<":"<<mins<<":"<<seconds<<endl;
                }
                else if(subChoice==2){
                    string from; string to;
                    cout<<"\nEnter starting station: "; cin>>from;
                    cout<<"Enter destination station: "; cin>>to;

                    int travelTime=er.calculateTravelTime(from, to);
                    
                    int hours=travelTime/3600;
                    int mins=(travelTime%3600)/60;
                    int seconds=travelTime%60;

                    cout<<"\nTravel Time: "<<hours<<":"<<mins<<":"<<seconds<<endl;
                }
                else cout<<"\nInvalid Input try again."<<endl;

                break;
            }
            case '7':{
                string from; string to;
                cout<<"\nEnter starting station: "; cin>>from;
                cout<<"Enter destination station: "; cin>>to;

                findBestRoute(sr, er, to, from);

                break;
            }
            case '8':{
                int subChoice;
                cout<<"\n\nSelect Route:\n\n";
                cout<<"[1] SR02"<<endl;
                cout<<"[2] ER01"<<endl; cin>>subChoice;

                if(subChoice==1) sr.reverseRoute();
                
                else if(subChoice==2) er.reverseRoute();
                
                else cout<<"\nInvalid Input try again."<<endl;

                break;
            }
            case '9':{
                int subChoice;
                cout<<"\n\nSelect Route:\n\n";
                cout<<"[1] SR02"<<endl;
                cout<<"[2] ER01"<<endl; cin>>subChoice;

                if(subChoice==1){
                    string currStation;
                    cout<<"\nEnter current station: "; cin>>currStation;
                    cout<<"\nSelect direction:\n\n";
                    cout<<"[1] forward"<<endl;
                    cout<<"[2] backward"<<endl; cin>>subChoice;
                    
                    if(subChoice==1) sr.showNextStation(currStation, "forward");
                    else if(subChoice==2) sr.showNextStation(currStation, "backward");
                    else cout<<"\nInvalid Input try again."<<endl;
                }
                
                else if(subChoice==2){
                    string currStation;
                    cout<<"\nEnter current station: "; cin>>currStation;
                    cout<<"\nSelect direction:\n\n";
                    cout<<"[1] forward"<<endl;
                    cout<<"[2] backward"<<endl; cin>>subChoice;
                    
                    if(subChoice==1) er.showNextStation(currStation, "forward");
                    else if(subChoice==2) er.showNextStation(currStation, "backward");
                    else cout<<"\nInvalid Input try again."<<endl;
                }
                
                else cout<<"\nInvalid Input try again."<<endl;

                break;
            }
            case '0':{
                break;;
            }
            case 'q':{
                cout<<"\n\nThank you for using Zu Peshawar."<<endl;
                break;
            }
            default:{
                cout<<"\n\nInvalid input, try again."<<endl;
                break;
            }
        }
    }while(choice!='q' && choice!='Q');
}