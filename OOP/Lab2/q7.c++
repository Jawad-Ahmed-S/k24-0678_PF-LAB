#include <iostream>
#include <cstring>
using namespace std;

struct ProductInfo
{
    string name;
    int price;
    int quantity;
    int ProductId;
};
void UpdateProductInfo(ProductInfo *&product, int *size)
{
    int index;
    int FindingProduct;
    cout << "Enter product ID: ";
    cin >> FindingProduct;
    for (int i = 0; i < *size; i++)
    {
        if (product[i].ProductId == FindingProduct)
        {
            index = i;
            break;
        }
    }
    cout << "Enter new product price: ";
    cin >> product[index].price;
    cout << "Enter new product quantity: ";
    cin >> product[index].quantity;
    cout << "Product updated successfully!\n";
}
void AddProduct(ProductInfo *&Prod, int *size)
{
    ProductInfo *Product = new ProductInfo[*size + 1];
    for (int i = 0; i < *size; i++)
    {
        Product[i] = Prod[i];
    }
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, Product[*size].name);
    cout << "Enter product price: ";
    cin >> Product[*size].price;
    cout << "Enter product quantity: ";
    cin >> Product[*size].quantity;
    cout << "Enter product ID: ";
    cin >> Product[*size].ProductId;
    (*size)++;
    delete[] Prod;

    Prod = Product;

    cout << "Product added successfully!\n";
}
void DisplayInventory(ProductInfo *product, int *size)
{
    cout << "\n\nProduct Inventory:\n";
    for (int i = 0; i < *size; i++)
    {
        cout << "Product ID: " << product[i].ProductId << "\n Name: " << product[i].name << "\n Price: " << product[i].price << "\n Quantity: " << product[i].quantity << "\n\n\n\n";
    }
}
void RemoveProduct(ProductInfo *&product, int *size)
{
    int id;
    cout << "Enter the product ID to remove: ";
    cin >> id;
    int index = -1;
    for (int i = 0; i < *size; i++)
    {
        if (product[i].ProductId == id)
        {
            index = i;
            break;
        }
    }
    ProductInfo *prod = new ProductInfo[*size - 1];

    for (int i = 0, j = 0; i < *size; i++)
    {
        if (i != index)
        {
            prod[j] = product[i];
            j++;
        }
    }
    delete[] product;
    product = prod;
    (*size)--;
    cout << "\n\nProduct removed!\n\n "
         << endl;
}
int main()
{
    ProductInfo *products = new ProductInfo[1];
    int op;
    int a = 0;
    int *size = &a;
    while (true)
    {
        cout << "Enter \n1. Add Product \n2. Display \n3. Remove \n4. Update \n5. Exit\n";
        cin >> op;

        switch (op)
        {
        case 1:
            AddProduct(products, size);
            break;
        case 2:
            DisplayInventory(products, size);
            break;
        case 3:
            RemoveProduct(products, size);
            break;
        case 4:
            UpdateProductInfo(products, size);
            break;
        case 5:
            delete[] products;
            return 0;
        default:
            cout << "Invalid option, try again.\n";
        }
    }
    return 0;
}
