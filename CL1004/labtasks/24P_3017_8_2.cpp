#include <iostream>
#include <string>
using namespace std;

class device{
public: 
    string name,location;
    bool power_stat;
    
    void turn_on(){
        power_stat = true;
    }

    void turn_off(){
        power_stat = true;
    }

    void power(){
            int temp;
            cout<<"\n\t 1. ON 2. OFF";
            cin>>temp;
            if(temp==1){turn_on();}
            else{turn_off();}
    }

    void show_stat(){
        if(power_stat==true){
            cout<<"\nThe device is ON";
        }
        else{
            cout<<"\nThe device is OFF";
        }
    }

};

class light: public device{
    int bright;
    string color;
public:
   

    light(){
        cout<<"\n\t Enter Smart Light naem: ";
        getline(cin,name);
        turn_on();
        cout<<"\n\t Where is the Light located: ";
        getline(cin,location);
    }

    void navigate_light(){
        int option;
        cout<<"\n\t 1. Set brightness \n\t 2. Change Color \n\t 3. Power";
        cin>>option;
        
        if(option==1)
        {adjust_bright();}
        else if(option==2) 
        {change_color();}
        else{
            power();
        }
    }

    void adjust_bright(){
        cout<<"\n\t Brightness Level: ";
        cin>>bright;
        
    }

    void change_color(){
        cout<<"\n\t Color: ";
        cin>>color;
    }

};

class thermostat: public device{
    float temp;
    string mode;
public: 

    thermostat(){
        cout<<"\n\t Enter Security Cam name: ";
        getline(cin,name);
        turn_on();
        cout<<"\n\t Where is the Thermostat located: ";
        getline(cin,location);
    }

    void navi_ts(){
        int choice;
        cout<<"\n\t 1. Set Temperature \n\t 2. Set Mode \n\t 3. power";
        cin>>choice;
        
        if(choice==1){set_temp();}
        else if(choice==2){set_mode();}
        else {power();}
    }

    void set_temp(){
        cout<<"\n\t Temperature: ";
        cin>>temp;
    }

    void set_mode(){
        cout<<"\n\t Mode: ";
        cin>>mode;
    }

};

class security_camera: public device{
    string resolution;
    bool record_stat;
public:

    security_camera(){
        cout<<"\n\t Enter Security Cam name: ";
        getline(cin,name);
        turn_on();
        cout<<"\n\t Where is the Cam located: ";
        getline(cin,location);
        cout<<"\n\t Enter Resolution: ";
        cin>>resolution;   
    }

    void navi_cam(){
        int choice;
        cout<<"\n\t 1. Starting recording \n\t 2. stop recording \n\t 3. view feed \n\t 4. power";
        cin>>choice;
        
        if(choice==1){start_rec();}
        else if(choice==2){stop_rec();}
        else if (choice==3){view_feed();}
        else {power();}
    }
   
    void start_rec(){
        record_stat=true;
        cout<<"\n\t recording started";
    }

    void stop_rec(){
        record_stat=false;
        cout<<"\n\t recording stopped";
    }
    
    void view_feed(){
        if(power_stat==true){
            cout<<"\n\t displaying feed";
        }else{
            cout<<"\n\t Device not found (OFF)";
        }
    }

};

int main(){

    light l[2];
    thermostat ts[2];
    security_camera c[2];

    int option=1;

while(option){

    cout<<"\n\t 1. Manage Lights \n\t 2. Manage Thermostats \n\t 3. Manage Security Cameras \n\t 4. See Power Status \n\t 0 for ending code";
    cout<<"\n\n Enter Choice: ";
    cin>>option;

    switch(option){
        
        case 1:
            cout<<"\n\t Light no.";
            cin>>option;
            l[option-1].navigate_light();
        break;

        case 2:
            cout<<"\n\t ThermoStat no.";
            cin>>option;
            ts[option-1].navi_ts();
        break;
        
        case 3:
            cout<<"\n\t Cam no: ";
            cin>>option;
            c[option-1].navi_cam();
        break;

        case 4:
            for(int i=0;i<2;i++){
                cout<<"\n\t Name: "<<l[i].name;
                cout<<"\t ";
                l[i].show_stat();
                cout<<"\n\t Name: "<<ts[i].name;
                cout<<"\t ";
                ts[i].show_stat();
                cout<<"\n\t Name: "<<c[i].name;
                cout<<"\t ";
                c[i].show_stat();
            }
        break;

        case 0:
        break;

        default:
        cout<<"invalid";
    }
    }
}