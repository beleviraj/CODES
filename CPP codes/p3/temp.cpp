#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100;

class Product {
private:
    int productid;
    string productname;
    int stock;
    float productprice;

public:
    Product() : productid(0), productname(""), stock(0), productprice(0.0) {}
    Product(int id, string name, int inv, float p) : 
        productid(id), productname(name), stock(inv), productprice(p) {}

    void setproductid(int id) { productid = id; }
    void setproductname(string name) { productname = name; }
    void setinventory(int inv) { stock = inv; }
    void setproductprice(float p) { productprice = p; }

    int getproductid() const { return productid; }
    string getproductname() const { return productname; }
    int getinventory() const { return stock; }
    float getproductprice() const { return productprice; }  

    void displayinfo() const {
        cout << "Product ID: " << productid << endl;
        cout << "Product Name: " << productname << endl;
        cout << "Stock: " << stock << endl;
        cout << "Product Price: Rs." << productprice << endl;
    }

    void additem() {
        int id, inv;
        float price;
        string name;
        cout << "Enter product ID: ";
        cin >> id;
        cin.ignore(); 
        setproductid(id);
        cout << "Enter product name: ";
        getline(cin, name);
        setproductname(name);
        cout << "Enter inventory: ";
        cin >> inv;
        cin.ignore();
        setinventory(inv);
        cout << "Enter product price: ";
        cin >> price;
        setproductprice(price);

        ofstream out("product_info.txt", ios::app);
        if (!out) {
            cout << "CANT OPEN FILE" << endl;
        } else {
            out << "Product ID: " << getproductid() << endl;
            out << "Product Name: " << getproductname() << endl;
            out << "Inventory: " << getinventory() << endl;
            out << "Product Price: Rs." << getproductprice() << endl;
            out << "------------------------" << endl;
        }
        out.close();
    }

    bool search(int id) const {
        return productid == id;
    }
};

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice = 0;

    while (choice != 5) {
        cout << "***** PHEONIX SHOPPING MALL *****" << endl;
        cout << "1. ADD PRODUCT" << endl << "2. SEARCH PRODUCT" << endl << "3. DISPLAY" << endl << "4. NO. OF PRODUCTS" << endl << "5. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                system("cls"); 
                if (count < MAX_PRODUCTS) {
                    products[count].additem();
                    count++;
                } else {
                    cout << "Product list is full!" << endl;
                }
                break;
            case 2: {
                system("cls");
                int searchID;
                cout << "Enter product ID to search: ";
                cin >> searchID;
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (products[i].search(searchID)) {
                        products[i].displayinfo();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Product not found!" << endl;
                }
                break;
            }
            case 3:
                system("cls");
                for (int i = 0; i < count; i++) {
                    products[i].displayinfo();
                    cout << endl;
                }
                break;
            case 4:
                system("cls");
                cout << "THE NUMBER OF PRODUCTS ARE: " << count << endl;
                break;
            case 5:
                cout << "THANKS FOR COMING......" << endl;
                break;
            default:
                cout << "INVALID CHOICE!" << endl;
        }
    }
    return 0;
}
