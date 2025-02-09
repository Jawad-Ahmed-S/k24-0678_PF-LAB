#include <iostream>
using namespace std;
class SmartPhone
{
    string Company;
    int Model;
    string Resolution;
    int RAM;
    int ROM;
    int Storage;

public:
    SmartPhone()
    {
        Company = "";
        Model = 0;
        Resolution = "";
        RAM = 0;
        ROM = 0;
        Storage = 0;
    }
    string GetCompany()
    {
        return this->Company;
    }
    int GetModel()
    {
        return this->Model;
    }
    string GetResolution()
    {
        return this->Resolution;
    }
    int GetRAM()
    {
        return this->RAM;
    }
    int GetROM()
    {
        return this->ROM;
    }
    int GetStorage()
    {
        return this->Storage;
    }
    void setCompany(string company)
    {
        this->Company = company;
    }
    void SetModel(int model)
    {
        this->Model = model;
    }
    void SetResolution(string resolution)
    {
        this->Resolution = resolution;
    }
    void SetRAM(int RAM)
    {
        this->RAM = RAM;
    }
    void SetROM(int ROM)
    {
        this->ROM = ROM;
    }
    void SetStorage(int storage)
    {
        this->Storage = storage;
    }

    void MakePhoneCall()
    {
        cout << "Calling...." << endl;
    }
    void SendMessage()
    {
        cout << "Sending Message...." << endl;
    }
    void ConnectToWifi()
    {
        cout << "Connecting to Wifi...." << endl;
    }
    void BrowseInternet()
    {
        cout << "Browsing Internet...." << endl;
    }
};
int main()
{

    SmartPhone Phone;
    Phone.setCompany("Samsung");
    Phone.SetModel(2025);
    Phone.SetResolution("1080p");
    Phone.SetRAM(12);
    Phone.SetROM(512);
    Phone.SetStorage(128);

    Phone.MakePhoneCall();
    Phone.SendMessage();
    Phone.ConnectToWifi();
    Phone.BrowseInternet();

    cout << "Phone Details : " << endl;
    cout << "Company : " << Phone.GetCompany() << endl;
    cout << "Model : " << Phone.GetModel() << endl;
    cout << "Display Resolution : " << Phone.GetResolution() << endl;
    cout << "RAM : " << Phone.GetRAM() << "GB" << endl;
    cout << "ROM : " << Phone.GetROM() << "GB" << endl;
    cout << "Storage : " << Phone.GetStorage() << "GB" << endl;

    return 0;
}