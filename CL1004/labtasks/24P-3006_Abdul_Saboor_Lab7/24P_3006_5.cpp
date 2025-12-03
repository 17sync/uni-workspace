#include<iostream>
#include<string>
using namespace std;

class Device{
protected:
    string name;
    bool status;
public:
    Device(string n):name(n),status(false){}
    virtual void turnOn(){status=true;cout<<name<<" turned ON\n";}
    virtual void turnOff(){status=false;cout<<name<<" turned OFF\n";}
    virtual void showStatus(){cout<<name<<" is "<<(status?"ON":"OFF")<<"\n";}
    virtual ~Device(){}
};

class Networked{
protected:
    string ipAddress;
    int port;
public:
    Networked(string ip,int p):ipAddress(ip),port(p){}
    virtual void connect(){cout<<"Connected to "<<ipAddress<<":"<<port<<"\n";}
    virtual void disconnect(){cout<<"Disconnected from "<<ipAddress<<"\n";}
};

class Securable{
protected:
    string password;
    int securityLevel;
public:
    Securable(string pwd,int lvl):password(pwd),securityLevel(lvl){}
    bool authenticate(string pwd){return pwd==password;}
    void encrypt(){cout<<"Data encrypted at level "<<securityLevel<<"\n";}
};

class SmartLight:public Device, public Networked, public Securable{
    int brightness;
public:
    SmartLight(string n,string ip,int port,string pwd,int sec):Device(n),Networked(ip,port),Securable(pwd,sec),brightness(100){}
    void setBrightness(int b){brightness=b; cout<<name<<" brightness set to "<<brightness<<"\n";}
};

class SmartThermostat:public Device, public Networked, public Securable{
    double temp;
public:
    SmartThermostat(string n,string ip,int port,string pwd,int sec):Device(n),Networked(ip,port),Securable(pwd,sec),temp(22.0){}
    void setTemperature(double t){temp=t; cout<<name<<" temperature set to "<<temp<<"\n";}
};

class SecurityCamera:public Device, public Networked, public Securable{
public:
    SecurityCamera(string n,string ip,int port,string pwd,int sec):Device(n),Networked(ip,port),Securable(pwd,sec){}
    void record(){if(status)cout<<name<<" recording...\n";}
};

class SmartDoor:public Device, public Networked, public Securable{
public:
    SmartDoor(string n,string ip,int port,string pwd,int sec):Device(n),Networked(ip,port),Securable(pwd,sec){}
    void lock(){cout<<name<<" locked\n";status=false;}
    void unlock(){cout<<name<<" unlocked\n";status=true;}
};

class SmartHomeHub{
public:
    Device* devices[20];
    int count;
    SmartHomeHub():count(0){}
    void addDevice(Device* d){if(count<20)devices[count++]=d;}
    void showAllStatus(){for(int i=0;i<count;i++)devices[i]->showStatus();}
    void turnAllOn(){for(int i=0;i<count;i++)devices[i]->turnOn();}
    void turnAllOff(){for(int i=0;i<count;i++)devices[i]->turnOff();}
    void applyScene(string scene){
        cout<<"Applying scene: "<<scene<<"\n";
        if(scene=="Home"||scene=="Party"){turnAllOn();}
        else if(scene=="Away"||scene=="Sleep"){turnAllOff();}
    }
    ~SmartHomeHub(){for(int i=0;i<count;i++)delete devices[i];}
};

int main(){
    SmartHomeHub hub;
    hub.addDevice(new SmartLight("LivingRoomLight","192.168.1.10",80,"1234",1));
    hub.addDevice(new SmartThermostat("Thermo","192.168.1.11",80,"abcd",2));
    hub.addDevice(new SecurityCamera("Cam1","192.168.1.12",80,"cam123",3));
    hub.addDevice(new SmartDoor("FrontDoor","192.168.1.13",80,"doorpwd",2));

    hub.showAllStatus();
    hub.applyScene("Home");
    hub.showAllStatus();
    hub.applyScene("Sleep");
    hub.showAllStatus();

    ((SmartLight*)hub.devices[0])->setBrightness(70);
    ((SmartThermostat*)hub.devices[1])->setTemperature(20);
    ((SecurityCamera*)hub.devices[2])->record();
    ((SmartDoor*)hub.devices[3])->unlock();
}
