#include <iostream>
using namespace std;
class MenuItem
{
public:
    MenuItem()
    {
        FoodName = "";
        price = 0;
    }
    MenuItem(string FoodName, int price)
    {
        this->FoodName = FoodName;
        this->price = price;
    }
    string FoodName;
    int price;
};
class Menu
{
    MenuItem *M;
    int sizeOfMenu;

public:
    Menu(int sizeOfMenu, MenuItem *M)
    {
        this->sizeOfMenu = sizeOfMenu;
        this->M = new MenuItem[sizeOfMenu];
        for (int i = 0; i < sizeOfMenu; i++)
        {
            this->M[i] = M[i];
        }
    };
    void displayMenu()
    {
        cout << "Menu:" << endl;
        for (int i = 0; i < sizeOfMenu; i++)
        {
            cout << M[i].FoodName << " - " << M[i].price << endl;
        }
    }
    void addMenuItem(MenuItem Item)
    {
        MenuItem *temp = new MenuItem[sizeOfMenu + 1];
        for (int i = 0; i < sizeOfMenu; i++)
        {
            temp[i].FoodName = M[i].FoodName;
            temp[i].price = M[i].price;
        }
        temp[sizeOfMenu].FoodName = Item.FoodName;
        temp[sizeOfMenu].price = Item.price;
        delete[] M;
        M = temp;
        sizeOfMenu++;
    }
    void removeMenuItem(string foodName)
    {
        for (int i = 0; i < sizeOfMenu; i++)
        {
            if (M[i].FoodName == foodName)
            {
                for (int j = i; j < sizeOfMenu - 1; j++)
                {
                    M[j].FoodName = M[j + 1].FoodName;
                    M[j].price = M[j + 1].price;
                }
                sizeOfMenu--;
                return;
            }
        }
    }
};
class RestruantOrderingSystem
{
    Menu menu;

public:
    void PlaceOrder()
    {
        // Place order logic here
    }
};
class Payment
{
    int amount;

public:
    void Payement()
    {
        amount = 0;
    }
    void setAmount(int amount)
    {
        this->amount = amount;
    }
    int getAmount()
    {
        return this->amount;
    }
    void displayAmount()
    {
        cout << "Amount: " << amount << endl;
    }
};
class Order
{
    MenuItem *menuItems;
    Payment payment;
    int sizeOrder;

public:
    Order()
    {
        menuItems = new MenuItem[0];
        payment.Payement();
        sizeOrder = 0;
    }
    Order(Payment payment)
    {
        menuItems = new MenuItem[0];
        this->payment = payment;
        sizeOrder = 0;
    }
    void addItem(MenuItem item)
    {
        MenuItem *temp = new MenuItem[sizeOrder + 1];
        for (int i = 0; i < sizeOrder; i++)
        {
            temp[i].FoodName = menuItems[i].FoodName;
            temp[i].price = menuItems[i].price;
        }
        temp[sizeOrder].FoodName = item.FoodName;
        temp[sizeOrder].price = item.price;
        delete[] menuItems;
        menuItems = temp;
        sizeOrder++;
    }
    void calculatePayment()
    {
        for (int i = 0; i < sizeOrder; i++)
        {
            payment.setAmount(payment.getAmount() + menuItems[i].price);
        }
    }
    void displayOrder()
    {
        cout << "Order:" << endl;
        for (int i = 0; i < sizeOrder; i++)
        {
            cout << menuItems[i].FoodName << " - " << menuItems[i].price << endl;
        }
        payment.displayAmount();
    }
};
int main()
{
    MenuItem M1("Biryani", 250);
    MenuItem M2("Chicken Curry", 300);
    MenuItem M3("Pasta", 150);
    MenuItem menu[3] = {M1, M2, M3};
    Menu M(3, menu);
    M.displayMenu();
    M.addMenuItem(MenuItem("Pizza", 400));
    M.displayMenu();
    M.removeMenuItem("Chicken Curry");
    M.displayMenu();
    Order o;
    o.addItem(M1);
    o.addItem(M3);
    o.calculatePayment();
    o.displayOrder();

    return 0;
}