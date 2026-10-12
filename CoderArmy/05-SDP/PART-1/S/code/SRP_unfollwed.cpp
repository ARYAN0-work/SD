#include <iostream>
#include <vector>

using namespace std;

// Product class representing any item of any ECommerce.
class Product {
public:
    string name;
    double price;
 
    Product(string name, double price) {// ye uska constructor
        this->name = name;
        this->price = price;
    }
};

// Violating SRP: ShoppingCart is handling multiple responsibilities
class ShoppingCart {
private:
    vector<Product*> products; // shopping cart k andar multiple vector so we made a list has a relationship

public:
    void addProduct(Product* p) { 
        products.push_back(p);// setter 
    }

    const vector<Product*>& getProducts() { 
        return products;// getter 
    } 

    // 1. Calculates total price in cart.
    double calculateTotal() {
        double total = 0;
        for (auto p : products) {
            total += p->price;
        }
        return total;
    }

    // 2. Violating SRP - Prints invoice (Should be in a separate class)
    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << calculateTotal() << endl;
    }

    // 3. Violating SRP - Saves to DB (Should be in a separate class)
    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    cart->printInvoice();  
    cart->saveToDatabase();

    return 0;
}

// yha sub kuch print hoga but SRP break ho gya