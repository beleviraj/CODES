#include <iostream>
using namespace std;

class Complex
{
    private:
      float real;
      float imag;
    public:
       Complex(): real(0), imag(0){ }
       void input()
       {
           cout << "Enter real and imaginary parts respectively: ";
           cin >> real;
           cin >> imag;
       }

       Complex operator - (Complex c2)
       {
           Complex temp;
           temp.real = real - c2.real;
           temp.imag = imag - c2.imag;

           return temp;
       }
	
	Complex operator + (Complex c1)
       {
           Complex add;
           add.real = real + c1.real;
           add.imag = imag + c1.imag;

           return add;
       }

       void output1()
       {
	   if(imag < 0)
			cout << "\nSubtraction of  Complex number: "<< real << imag << "i";
           else
                      	cout << "\nSubtraction of Complex number: " << real << "+" << imag << "i";
       }

	void output2()
       	{
		   if(imag < 0)
				cout << "\nAddition of  Complex number: "<< real << imag << "i";
        	   else
        	              	cout << "\nAddition of Complex number: " << real << "+" << imag << "i";
       	}
};

int main()
{
    Complex c1, c2, result1,result2;

    cout<<"First complex number\n";
    c1.input();

    cout<<"Second complex number:\n";
    c2.input();

    result1= c1 - c2;
    result2= c1 + c2;

    result1.output1();
    result2.output2();

    return 0;
}
