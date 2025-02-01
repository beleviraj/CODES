#include<iostream>
using namespace std;


class abc
{
    private:
            int arr[3][3];
    public:
            void accept()
            {
                int i,j;
                for(i=0;i<3;i++)
                {
                        for(j=0;j<3;j++)
                        {
                            cin>>arr[i][j];
                        }
                }
            }
            void display()
            {
                int i,j;
                for(i=0;i<3;i++)
                {
                        for(j=0;j<3;j++)
                        {
                            cout<<"";
                            cout<<arr[i][j]<<" ";
                        }
                        cout<<"\n";
                }
            }
            void operator*(abc p)
            {
               int add[3][3];
               int i,j;
               for(i=0;i<3;i++)
               {
                   for(j=0;j<3;j++)
                   {
                       add[i][j]=arr[i][j]*p.arr[i][j];
                   }
               }
               cout<<"\nAddition Matrix is:\n";
               for(i=0;i<3;i++)
                {
                        for(j=0;j<3;j++)
                        {
                            cout<<"";
                            cout<<add[i][j]<<" ";
                        }
                        cout<<"\n";
                }
            }
};
int main()
{
    abc a,b,result;
     printf("\nEnter First matrix: \n");
    a.accept();
    printf("\nEnter Second matrix: \n");
    b.accept();
    printf("\nFirst matrix: \n");
    a.display();
    printf("\nSecond matrix: \n");
    b.display();
    a*b;
    return 0;

}
