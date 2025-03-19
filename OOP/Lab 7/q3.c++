#include <iostream>
using namespace std;
class Currency
{
protected:
    int amount;
    string Currenycode;
    string Symbol;
    float ExchangeRate;

public:
    Currency(int a, string c, string s, float e)
    {
        amount = a;
        Currenycode = c;
        Symbol = s;
        ExchangeRate = e;
    }
    virtual float convertToBase()
    {
        return 0.0;
    };
    virtual void displayDetails() {};
};
class Dollar : public Currency
{
public:
    Dollar(int a, float e) : Currency(a, "USD", "$", e) {};
    float convertToBase() override
    {
        return (amount * ExchangeRate);
    }
    void displayDetails() override
    {
        cout << "Amount: " << amount << Symbol << " (" << Currenycode << ")" << endl;
        cout << "Exchange Rate: " << ExchangeRate << " USD/1 " << Symbol << endl;
    }
};
class Euro : public Currency
{
public:
    Euro(int a, float e) : Currency(a, "EUR", "€", e) {};
    float convertToBase() override
    {
        return (amount * ExchangeRate);
    }
    void displayDetails() override
    {
        cout << "Amount: " << amount << Symbol << " (" << Currenycode << ")" << endl;
        cout << "Exchange Rate: " << ExchangeRate << " EUR/1 " << Symbol << endl;
    }
};
class Rupee : public Currency
{
public:
    Rupee(int a, float e) : Currency(a, "PKR", "Rs. ", e) {};
    void displayDetails() override
    {
        cout << "Amount: " << amount << Symbol << " (" << Currenycode << ")" << endl;
        cout << "Exchange Rate: " << ExchangeRate << " PKR/1 " << Symbol << endl;
    }
};
int main()
{
    Dollar d(500, 280);
    cout << d.convertToBase() << endl;
    d.displayDetails();

    Euro e(100, 300);
    cout << e.convertToBase() << endl;
    e.displayDetails();
    return 0;
}