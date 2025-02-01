 #include <iostream>

using namespace std;



// Base class

class Base {

public:

    void display() {

        cout << "Base class" << endl;

    }

};



// Single inheritance

class Derived1 : public Base {

public:

    void displayDerived1() {

        cout << "Derived1 class" << endl;

    }

};



// Multiple inheritance

class Base2 {

public:

    void displayBase2() {

        cout << "Base2 class" << endl;

    }

};



class Derived2 : public Base, public Base2 {

public:

    void displayDerived2() {

        cout << "Derived2 class" << endl;

    }

};



// Multilevel inheritance

class Derived3 : public Derived1 {

public:

    void displayDerived3() {

        cout << "Derived3 class" << endl;

    }

};



// Hybrid inheritance

class Base3 {

public:

    void displayBase3() {

        cout << "Base3 class" << endl;

    }

};



class Derived4 : public Base, public Base3 {

public:

    void displayDerived4() {

        cout << "Derived4 class" << endl;

    }

};



// Hierarchical inheritance

class Derived5 : public Base {

public:

    void displayDerived5() {

        cout << "Derived5 class" << endl;

    }

};



class Derived6 : public Base {

public:

    void displayDerived6() {

        cout << "Derived6 class" << endl;

    }

};



int main() {

    // Single inheritance

    Derived1 obj1;

    obj1.display();

    obj1.displayDerived1();

    

    // Multiple inheritance

    Derived2 obj2;

    obj2.display();

    obj2.displayBase2();

    obj2.displayDerived2();

    

    // Multilevel inheritance

    Derived3 obj3;

    obj3.display();

    obj3.displayDerived1();

    obj3.displayDerived3();

    

    // Hybrid inheritance

    Derived4 obj4;

    obj4.display();

    obj4.displayBase3();

    obj4.displayDerived4();

    

    // Hierarchical inheritance

    Derived5 obj5;

    obj5.display();

    obj5.displayDerived5();

    

    Derived6 obj6;

    obj6.display();

    obj6.displayDerived6();

    

    return 0;

}