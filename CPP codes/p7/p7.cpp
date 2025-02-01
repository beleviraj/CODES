#include<iostream>
using namespace std;

class complex {
private:
    int real;
    int img;

public:
    complex() {
        real = 0;
        img = 0;
    }

    complex(int r, int i) {
        real = r;
        img = i;
    }

    complex operator +(complex obj) {
        complex temp;
        temp.real = real + obj.real;
        temp.img = img + obj.img;
        return temp;
    }

    complex operator -(complex obj) {
        complex temp;
        temp.real = real - obj.real;
        temp.img = img - obj.img;
        return temp;
    }

    void display() {
        cout << real << "+" << img << "i" << endl;
    }
};

int main() {
    int real1, real2, img1, img2;
    cout << "Enter the real and imaginary part of 1st number: " << endl;
    cin >> real1 >> img1;
    cout << "Enter the real and imaginary part of 2nd number: " << endl;
    cin >> real2 >> img2;
    complex c1(real1, img1);
    complex c2(real2, img2);
    complex c3 = c1 + c2;
    complex c4 = c1 - c2;
    cout << "The sum of the two complex numbers is: ";
    c3.display();
    cout << "The difference of the two complex numbers is: ";
    c4.display();
    return 0;
}
