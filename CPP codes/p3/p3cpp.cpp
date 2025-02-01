#include<iostream>
#include<string>
using namespace std;
class vehicle{
    private:
    int numWheels, maxSpeed, maxGears, curGear=0, curSpeed=0;
    bool on,off;
    string color;
    public:
   
    vehicle(){
        numWheels=4;
        maxSpeed=400;
        maxGears=6;
        color="black";
        on=false;
        off=true;
    }

    void increasespeed(){
        if(!on){
            cout<<"\nStart the vehicle !!";
            return;
        }
        if(curGear>=1){
        if(curSpeed<maxSpeed){
            curSpeed=curSpeed+20;
        }
        else{
            cout<<"\nMAX SPEED REACHED";
        }
        }
        else{
            cout<<"\nVehicle is in Neutral state!!";
        }
        
        cout<<"\nThe current speed is: "<<curSpeed<<"kmph";
        cout<<"\nThe current gear is: "<<curGear;

    }

    void start(){
        if(on==true){
            cout<<"\nVehicle already started...";
        }
        else{
            on=true;
            off=false;
            cout<<"\nVehicle started...";
        }
        cout<<"\nThe current speed is: "<<curSpeed<<"kmph";
        cout<<"\nThe current gear is: "<<curGear;
    }

     void decreasespeed(){
       if(on==true){
            if(curSpeed!=0)
            curSpeed=curSpeed-20;
            curGear--;
       }
       else{
        cout<<"\nVehicle is off!!";
       }
       cout<<"\nThe current speed is: "<<curSpeed<<"kmph";
       cout<<"\nThe current gear is: "<<curGear;
    }

    void nextgear(){
        if(on==true){
            if(curGear<=maxGears){
                curGear++;
            }
            else{
                cout<<"\nMAX gear limit reached!!";
            }
        }
        else{
            cout<<"\nVehicle is off!!";
        }
        cout<<"\nThe current speed is: "<<curSpeed<<"kmph";
        cout<<"\nThe current gear is: "<<curGear;
    }

    void previousgear(){
        if(on==true){
            if(curGear>0){
                curGear--;
            }
            else{
                cout<<"\nVehicle is neutral";
            }
        }
        else{
            cout<<"\nVehicle is off";
        }
        cout<<"\nThe current speed is: "<<curSpeed<<"kmph";
        cout<<"\nThe current gear is: "<<curGear;

    }

    void stop(){
        if(on==true){
            on=false;
            off=true;
            curSpeed=0;
            cout<<"\nVehicle stopped!!";
        }
        else{
            curSpeed=0;
            cout<<"\nVehicle is already stopped";
        }
    }

};
int main(){
    vehicle v1;
    int choice;
    while(choice!=7){
        cout<<endl<<"\n1. Increase Speed\n2. Decrease speed\n3. nextGear\n4. previousGear\n5. Start\n6. Stop\n";
        cout<<endl<<"\nEnter the operation: ";
        cin>>choice;
        switch(choice){
            case 1:v1.increasespeed();
                break;
            case 2:v1.decreasespeed();
                break;
            case 3:v1.nextgear();
                break;
            case 4:v1.previousgear();
                break;
            case 5:v1.start();
                break;
            case 6:v1.stop();
                break;
            case 7:break;
        }
    }
    
}