#include<iostream>
using namespace std;

class Product {
protected:
    int productId;
    int price;
public:
    Product(int productId, int price) {
        this->productId = productId;
        this->price = price;
    }
    Product() {
        productId = 0;
        price = 0;
    }
    virtual void applyDiscount(int discount) {
        price -= discount;
    }
    virtual void applyDiscount(float discount) {
        price -= (price * discount) / 100;
    }
    virtual void applyDiscount() {
        cout << "Buy get one free\n";
    }
    virtual int calculatePrice() {
        return price;
    }
    int getPrice() const { return price; }
    int getProductId() const { return productId; }
    virtual ~Product() {}
};

class Electronics : public Product {
public:
    Electronics(int productId, int price) : Product(productId, price) {}
    int calculatePrice() override {
        return price - (price * 0.15);
    }
};

class Clothing : public Product {
public:
    Clothing(int productId, int price) : Product(productId, price) {}
    int calculatePrice() override {
        return price - (price * 0.05);
    }
};

class ShoppingCart {
    int totalPrice;
    Product** p;
    int pcount;
public:
    ShoppingCart() {
        totalPrice = 0;
        pcount = 0;
        p = new Product*[100]; // max 100 items
    }

    void addProduct(Product* prod) {
        totalPrice += prod->calculatePrice();
        p[pcount++] = prod;
    }

    void removeProduct(Product* prod) {
        totalPrice -= prod->calculatePrice();
        // for simplicity, we won't delete from array here
        pcount--;
    }

    void displayCart() {
        for (int i = 0; i < pcount; i++) {
            cout << "Product ID: " << p[i]->getProductId() << ", Price: " << p[i]->getPrice() << endl;
        }
        cout << "Total Price: " << totalPrice << endl;
    }

    void operator+(ShoppingCart& s) {
        cout << "Added to cart\n";
        for (int i = 0; i < s.pcount; i++) {
            this->addProduct(s.p[i]);
        }
    }

    void operator-(Product* prod) {
        cout << "Removed from cart\n";
        removeProduct(prod);
    }

    void operator*() {
        for (int i = 0; i < pcount; i++) {
            p[i]->applyDiscount(10.0f);  // 10% discount
        }
        cout << "Bulk discount applied on all products\n";
    }

    void operator/(int users) {
        if (users <= 0) {
            cout << "Invalid number of users\n";
            return;
        }
        cout << "Each user pays: " << totalPrice / users << endl;
    }

    ~ShoppingCart() {
        delete[] p;
    }
};

int main() {
    ShoppingCart cart;
    Electronics* e1 = new Electronics(101, 1000);
    Clothing* c1 = new Clothing(202, 500);

    cart.addProduct(e1);
    cart.addProduct(c1);

    *cart;          // apply bulk discount
    cart / 2;       // split bill among 2 users

    cart.displayCart();  // Optional: show final state

    return 0;
}
