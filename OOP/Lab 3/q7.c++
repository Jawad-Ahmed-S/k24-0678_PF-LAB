#include <iostream>
using namespace std;
class StationaryShop
{
    int ExistingProducts = 1;
    string *Products = new string[ExistingProducts];
    int *Prices = new int[ExistingProducts];

public:
    StationaryShop()
    {
        Products = 0;
        Prices = 0;
    }
    StationaryShop(string ProductName, int price)
    {
        this->Products[0] = ProductName;
        this->Prices[0] = price;
    }
    void AddItems(string ProductName, int price)
    {
        string *Newproducts = new string[ExistingProducts + 1];
        int *Newprices = new int[ExistingProducts + 1];
        for (int i = 0; i < ExistingProducts; i++)
        {
            Newproducts[i] = Products[i];
            Newprices[i] = Prices[i];
        }
        Newproducts[ExistingProducts] = ProductName;
        Newprices[ExistingProducts] = price;
        ExistingProducts++;
        delete[] Products;
        delete[] Prices;
        Products = Newproducts;
        Prices = Newprices;
    }
    void UpdatePrices(string ProductName, int NewPrice)
    {

        for (int i = 0; i < ExistingProducts; i++)
        {
            if (Products[i] == ProductName)
            {
                Prices[i] = NewPrice;
            }
        }
    }
    void RemoveProduct(string ProductName)
    {
        string *Newproducts = new string[ExistingProducts + 1];
        int *Newprices = new int[ExistingProducts + 1];
        for (int i = 0, j = 0; i < ExistingProducts; i++)
        {
            if (Products[i] != ProductName)
            {
                Newproducts[j] = Products[i];
                Newprices[j] = Prices[i];
                j++;
            }
        }
        ExistingProducts--;
        delete[] Products;
        delete[] Prices;
        Products = Newproducts;
        Prices = Newprices;
    }
    void DisplayInventory()
    {
        cout << "Inventory : " << endl;
        for (int i = 0; i < ExistingProducts; i++)
        {
            cout << Products[i] << " : Rs." << Prices[i] << endl;
        }
    }
    void GenerateReceipt(string ProductName[], int quantities[], int count)
    {
        int total = 0;

        cout << "\n\n Receipt : " << endl;
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < ExistingProducts; j++)
            {
                if (ProductName[i] == Products[j])
                {
                    cout << ProductName[i] << " : " << quantities[i] << "   Rs " << (Prices[j] * quantities[i]) << endl;
                    total += Prices[j] * quantities[i];
                }
            }
        }
        cout << "\nTotal : " << total << endl;
    }
};
int main()
{
    StationaryShop S1("Pencil", 35);
    S1.DisplayInventory();
    cout << "\n\n New Inventory" << endl;
    S1.AddItems("Marker", 100);
    S1.AddItems("Pen", 200);
    S1.AddItems("Eraser", 300);
    S1.DisplayInventory();
    S1.RemoveProduct("Pen");
    S1.UpdatePrices("Pencil", 1000);
    S1.DisplayInventory();
    string bought[] = {"Marker", "Pencil"};
    int quant[] = {2, 3};
    S1.GenerateReceipt(bought, quant, 2);
    return 0;
}