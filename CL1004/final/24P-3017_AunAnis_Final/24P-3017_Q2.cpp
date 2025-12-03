#include<iostream>
using namespace std;

class device{
    public:
    string deviceID;
    string status;
    device(string id, string s): deviceID(id), status(s){}
    virtual void display_status()=0;
};

class controller: virtual public device{
    public:
    bool state;
    controller(string id, string s, bool st): device(id, s), state(st){}
    void display_status() override{
        cout<<"Controller "<<deviceID<<": Status="<<status<<", Active=";
        if(state=1)cout<<"Yes"<<endl;
        else if(state=0)cout<<"No"<<endl;
    }
    void on(){
        state=true;
        cout<<"Successfully turned on controller:"<<deviceID<<endl;
    }
    void off(){
        state=false;
        cout<<"Successfully turned off controller:"<<deviceID<<endl;
    }
};

class sensor: virtual public device{
    public:
    double value;
    sensor(string id, string s, double v): device(id, s), value(v){}
    void display_status() override{
        cout<<"Sensor "<<deviceID<<": Status="<<status<<", Value="<<value<<endl;
    }
    void measure_value(){
        cout<<"Enter value: ";cin>>value;
        cout<<"Value successfully added!"<<endl;
    }
};

class smartdevice: public controller, public sensor{
    public:
    smartdevice(string id, string s, double v, bool st): controller(id, s, st), sensor(id, s, v), device(id, s){}
    void display_status() override{
        cout<<"Smart Device "<<deviceID<<": Status="<<status<<", Value="<<value<<", Active=";
        if(state=1)cout<<"Yes"<<endl;
        else if(state=0)cout<<"No"<<endl;
    }
    void on(){
        state=true;
        cout<<"Successfully turned on smart device:"<<deviceID<<endl;
    }
    void off(){
        state=false;
        cout<<"Successfully turned off smart device:"<<deviceID<<endl;
    }
};

int main(){
    device *d1, *d2, *d3;
    sensor s("[ID1]","Online", 25.5);                  //arguments from examples in qs
    controller c("[ID2]", "Online", 1);
    smartdevice sd("[ID3]", "Online", 22.0, 0);
    d1=&s;
    d2=&c;
    d3=&sd;
    d1->display_status();
    d2->display_status();
    d3->display_status();
    
    cout<<"\nSmart Device status via DMA:\n";               //Smart objects created via DMA and status shown via device pointer
    device *d4=new smartdevice("[ID4]", "Online", 23.5, 1);
    device *d5=new smartdevice("[ID5]", "Offline", 25.5, 0);
    delete d4;
    d4=NULL;
    delete d5;
    d5=NULL;
}