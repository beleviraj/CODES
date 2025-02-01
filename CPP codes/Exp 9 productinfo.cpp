#include <iostream>
#include <string>

class product {
private:
    std::string name;
    double price;
    int quantity;

public:
    // constructor
    product(std::string productname, double productprice, int productquantity) {
        name = productname;
        price = productprice;
        quantity = productquantity;
    }

    // getters
    std::string getname() const {
        return name;
    }

    double getprice() const {
        return price;
    }

    int getquantity() const {
        return quantity;
    }

    // setters
    void setname(std::string newname) {
        name = newname;
    }

    void setprice(double newprice) {
        price = newprice;
    }

    void setquantity(int newquantity) {
        quantity = newquantity;
    }

    // other methods
    void displayinfo() const {
        std::cout << "product name: " << name << std::endl;
        std::cout << "price: $" << price << std::endl;
        std::cout << "quantity: " << quantity << std::endl;
    }
};

int main() {
    // creating a product object and displaying its information
    product product1("shirt", 29.99, 10);
    product1.displayinfo();

    // modifying the product information
    product1.setprice(39.99);
    product1.setquantity(5);
    product1.displayinfo();
    return 0;
}
