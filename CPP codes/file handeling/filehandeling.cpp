#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int maxproduct = 100;

class File {
private:
    int productid;
    string productname;
    int stock;
    float price;

public:
    File() : productid(0), productname(""), stock(0), price(0.0) {}
    File(int id, string name, int stk, float p) : productid(id), productname(name), stock(stk), price(p) {}

    void setproductid(int id) { productid = id; }
    void setproductname(string name) { productname = name; }
    void setproductstock(int stk) { stock = stk; }
    void setproductprice(float p) { price = p; }

    int getproductid() { return productid; }
    string getproductname() { return productname; }
    int getproductstock() { return stock; }
    float getproductprice() { return price; }

    void additem() {
        int id, stk;
        string name;
        float p;
        cout << "Enter product ID: ";
        cin >> id;
        cin.ignore();
        setproductid(id);
        cout << "Enter product name: ";
        getline(cin, name);
        setproductname(name);
        cout << "Enter inventory: ";
        cin >> stk;
        setproductstock(stk);
        cout << "Enter product price: ";
        cin >> p;
        setproductprice(p);
        ofstream out("file.txt", ios::app);
        if (!out) {
            cout << "CANNOT OPEN FILE" << endl;
        } else {
            out<<"Product ID: "<<getproductid()<<endl;
            out<<"Product Name: "<<getproductname()<<endl;
            out<<"Inventory: "<<getproductstock()<<endl;
            out<<"Product Price: Rs."<<getproductprice()<<endl;
            out << "------------------------" << endl;        }
        out.close();
    }

    void display() {
        cout << "Product ID: " << productid << endl;
        cout << "Product Name: " << productname << endl;
        cout << "Product Stock: " << stock << endl;
        cout << "Product Price: Rs. " << price << endl;
    }

    bool search(int id) {
        return productid == id;
    }
};

int main() {
    File f[maxproduct];
    int count = 0;
    int choice = 0;

    while (choice != 5) {
        cout << "1. ADD PRODUCT" << endl
             << "2. SEARCH PRODUCT" << endl
             << "3. DISPLAY ALL PRODUCTS" << endl
             << "4. NUMBER OF PRODUCTS" << endl
             << "5. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:system("cls");
            if (count < maxproduct) {
                f[count].additem();
                count++;
            } else {
                cout << "LIST IS FULL!!" << endl;
            }
            break;

        case 2: {system("cls");
            int searchid;
            cout << "Enter the product ID: ";
            cin >> searchid;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (f[i].search(searchid)) {
                    f[i].display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Product not found" << endl;
            }
            break;
        }

        case 3:system("cls");
            for (int i = 0; i < count; i++) {
                f[i].display();
                cout << "------------------------" << endl;
            }
            break;

        case 4:system("cls");
            cout << "THE NUMBER OF PRODUCTS ARE: " << count << endl;
            break;

        case 5:system("cls");
            break;

        default:
            cout << "INVALID CHOICE!" << endl;
        }
    }

    return 0;
}
