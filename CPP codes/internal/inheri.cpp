#include<iostream>
using namespace std;
class base1
{
private:
int x,y;

public:
   int operate(int a,int b)
   {
    return 0;
   }

   void displaybase(int a,int b)
   {
    x=a,y=b;
    cout<<"a="<<x<<" "<<"b="<<y<<endl;
    cout<<"\n";
   }
};
//single
class addition:public base1
{
    public:
    int operate(int a,int b)
    {
        return a+b;
    }

    void displaya(int a,int b)
    {
        cout<<"ADDITION IS: "<<a+b;
        cout<<"\n";
    }

};
//single
class substraction:public base1
{
    public:
    int operate(int a,int b)
    {
        return a-b;
    }

    void displays(int a,int b)
    {
        cout<<"SUBSTRACTION IS: "<<a+b;
    }

};
class base2 
{
    public:
    void check(int a,int b)
    {
        if(b==0)
        {
            cout<<"Division by zero is not possible"<<endl;
        }
    }
    
};

//multiple
class division: public base1,public base2
{
    public:
    float operate(int a,int b)
    {
        return (float)a/b;
    }

    void displayd(int a,int b)
    {
        cout<<"DIVISON IS: "<<a+b;
    } 
};
//multilevel
class multiplication:public addition
{
    public:
    int operate(int a,int b)
    {
        return a*b;
    }

    void displaym(int a,int b)
    {
        cout<<"MULTIPLICATION  IS: "<<a*b;
    } 
};
//hybrid
class addsub:public addition,public substraction
{
    public:
    int operate(int a,int b)
    {
        return a-b+(a+b);
    }
    void displaysa(int a,int b)
    {
        cout<<"addition + substraction :"<<a-b+(a+b);
    }
};

int main()
{
    int a,b;
    cout<<"enter the value of a and b:"<<endl;
    cin>>a>>b;
    base1 A;
    A.displaybase(a,b);
    //single
    addition B;
    B.displaybase(a,b);
    B.operate(a,b);
    B.displaya(a,b);
    //single
    substraction C;
    C.displaybase(a,b);
    C.operate(a,b);
    C.displays(a,b);
    //multiple
    division D;
    D.displaybase(a,b);
    D.check(a,b);
    D.operate(a,b);
    D.displayd(a,b);
    //multilevel
    multiplication E;
    E.displaybase(a,b);
    E.operate(a,b);
    E.displaym(a,b);
    E.addition::operate(a,b);
    E.displaya(a,b);
    //hybrid
    addsub F;
    //F.displaybase(a,b);
    F.addition::operate(a,b);
    F.substraction::operate(a,b);
    F.operate(a,b);
    F.displaysa(a,b);
    



    

    return 0;
}