#include<iostream>

using namespace std;

class date{
    private: 
    int day,month,year;
    public:
    void setday(int i){
        day=i;
    }
    void setmonth(int j){
        month=j;
    }
    void setyear(int k){
        year=k;
    }
    int getday(){
        return day;
    }
    int getmonth(){
        return month;
    }
    int getyear(){
        return year;
    }
    void validdate(int i,int j,int k){
        if(i>31 || j>12 || i==0  || j==0 || k==0){
           
            cout<<"\nDATE IS INVALID!!!";
        }
        else{
        if((j==4 || j==6 || j==9 || j==11) && i<31){
            cout<<"\nDATE IS VALID....";
            }
        else if((j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12)){
            cout<<"\nDATE IS VALID....";
        }
        else if(i<30 && j==2){
            if(((k % 4 == 0 && k % 100 != 0) || (k % 400 == 0)) && i<30){
            cout<<"\nDATE IS VALID....";   
            }
            else if(i<29){
            cout<<"\nDATE IS VALID....";
            }
            else{
            cout<<"\nDATE IS INVALID....";
            }
        }
        else{
             cout<<"\nDATE IS INVALID....";
        }  
        }  
            return;
    }

   void leap(int k) {
    if ((k % 4 == 0 && k % 100 != 0) || (k % 400 == 0)) {
        printf("%d is a leap year.\n", k);
    } else {
        printf("%d is not a leap year.\n", k);
    }
}



};

int main(){
    date d;
    int i,j,k;

int choice;
while(choice!=3){
    cout<<"\nEnter the day: ";
    cin>>i;
    d.setday(i);
    cout<<"Enter the month: ";
    cin>>j;
    d.setmonth(j);
    cout<<"Enter the year: ";
    cin>>k;
    d.setyear(k);
    cout<<"\nTHE DATE IS: "<<d.getday()<<"/"<<d.getmonth()<<"/"<<d.getyear()<<endl;
    cout<<"\n1.CHECK VALIDATION\n2.CHECK LEAP YEAR\n3.EXIT";
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice){
        case 1:d.validdate(i,j,k);
                break;
        case 2:d.leap(k);
                break;
        case 3: break;
    }

}

    return 0;
}