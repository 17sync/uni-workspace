#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string name;
    bool status;
public:
    Device(string n="Unknown") : name(n), status(false) {}
    virtual void turnOn() { status = true; }
    virtual void turnOff() { status = false; }
    virtual void show() { cout << name << " Status: " << (status ? "ON" : "OFF") << endl; }
    virtual ~Device() {}
};

class Networked {
protected:
    string ipAddress;
    int port;
    bool connected;
public:
    Networked(string ip="", int p=0) : ipAddress(ip), port(p), connected(false) {}
    virtual void connect() { connected = true; }
    virtual void disconnect() { connected = false; }
};

class Scheduled {
protected:
    string schedule;
    bool scheduleActive;
public:
    Scheduled(string s="None") : schedule(s), scheduleActive(false) {}
    virtual void setSchedule(string s) { schedule = s; scheduleActive = true; }
    virtual bool checkSchedule() { return scheduleActive; }
};

class Securable {
protected:
    string password;
    int securityLevel;
    bool authenticated;
public:
    Securable(string pass="", int lvl=0) : password(pass), securityLevel(lvl), authenticated(false) {}
    virtual bool authenticate(string pass) {
        authenticated = (pass == password);
        return authenticated;
    }
    virtual void encrypt() {
        if (authenticated) password = "***";
    }
};

class SmartLight : public Device, public Networked, public Scheduled {
    string color;
public:
    SmartLight(string n, string ip, int p, string c)
        : Device(n), Networked(ip, p), Scheduled(), color(c) {}

    void show() override {
        cout << "Light: " << name << ", Status: " << (status ? "ON" : "OFF")
             << ", Color: " << color << ", IP: " << ipAddress << endl;
    }
};

class SmartThermostat : public Device, public Networked, public Scheduled {
    int temperature;
public:
    SmartThermostat(string n, string ip, int p, int t)
        : Device(n), Networked(ip, p), Scheduled(), temperature(t) {}

    void setTemp(int t) { temperature = t; }
    void show() override {
        cout << "Thermostat: " << name << ", Temp: " << temperature
             << ", Status: " << (status ? "ON" : "OFF")
             << ", Schedule: " << (scheduleActive ? "Active" : "Inactive") << endl;
    }
};

class SecurityCamera : public Device, public Networked, public Securable {
    bool recording;
public:
    SecurityCamera(string n, string ip, int p, string pass, int lvl)
        : Device(n), Networked(ip, p), Securable(pass, lvl), recording(false) {}

    void startRecording() { recording = true; }
    void stopRecording() { recording = false; }
    void show() override {
        cout << "Camera: " << name << ", IP: " << ipAddress
             << ", Recording: " << (recording ? "YES" : "NO") << endl;
    }
};

class SmartDoor : public Device, public Networked, public Securable {
    bool locked;
public:
    SmartDoor(string n, string ip, int p, string pass, int lvl)
        : Device(n), Networked(ip, p), Securable(pass, lvl), locked(true) {}

    void lock() { locked = true; }
    void unlock() { locked = false; }
    void show() override {
        cout << "Door: " << name << ", Locked: " << (locked ? "YES" : "NO")
             << ", Security Level: " << securityLevel << endl;
    }
};

class SmartHomeHub {
    Device* devices[10];
    int count;
public:
    SmartHomeHub() : count(0) {}

    void addDevice(Device* d) {
        if (count < 10) devices[count++] = d;
    }

    void activateHomeMode() {
        cout << "Home Mode Activated" << endl;
        for (int i = 0; i < count; i++) devices[i]->turnOn();
    }

    void activateAwayMode() {
        cout << "Away Mode Activated" << endl;
        for (int i = 0; i < count; i++) devices[i]->turnOff();
    }

    void activateSleepMode() {
        cout << "Sleep Mode Activated" << endl;
        for (int i = 0; i < count; i++) devices[i]->turnOff();
    }

    void showAll() {
        for (int i = 0; i < count; i++) devices[i]->show();
    }
};

int main() {
    SmartLight light("Living Room Light", "192.168.1.100", 80, "Warm White");
    SmartThermostat thermo("Main Thermostat", "192.168.1.120", 90, 72);
    SecurityCamera cam("Front Camera", "192.168.1.150", 70, "1234", 5);
    SmartDoor door("Front Door", "192.168.1.200", 60, "abcd", 3);

    cam.authenticate("1234");
    cam.startRecording();

    SmartHomeHub hub;
    hub.addDevice(&light);
    hub.addDevice(&thermo);
    hub.addDevice(&cam);
    hub.addDevice(&door);

    hub.activateHomeMode();
    hub.showAll();

    cout << "Sleep Mode..." << endl;
    hub.activateSleepMode();
    hub.showAll();
}
