#include<iostream>
using namespace std;
class vehicle
{
	private:
	string color;
	int gear=0;
	int speed=0;
	
	public:
	 void start()
	 {
	 	gear=1;
	 	speed=10;
	 	cout<<"Car started."<<endl;
	 	cout<<"Gear="<<gear;
	 	cout<<"\nSpeed="<<speed;
	 }
	 void setinrgear()
	 {
	 	if(gear<=5)
	 	{
	 		gear++;
	 		cout<<"\nGear="<<gear;
		 }
		 else
		 cout<<"You cannot increase Gear now. Its beyond limit\n";
	 }
	  void setdcrgear()
	 {
	 	if(gear>0&&gear<=5)
	 	{
	 		gear--;
	 		cout<<"\nGear="<<gear;
		 }
		 else
		 cout<<"You cannot decrease Gear now. Its already 0.\n";
	 }
	  void setinrspeed()
	 {
	 	if(gear<=350)
	 	{
	 		speed+=50;
	 		cout<<"\nSpeed="<<speed;
		 }
		 else
		 cout<<"You cannot increase Speed now. Its beyond limit\n";
	 }
	  void setdcrspeed()
	 {
	 	if(speed>0&&speed<=350)
	 	{
	 		speed-=50;
	 		cout<<"\nSpeed="<<speed;
		 }
		 else
		 cout<<"You cannot decrease Speed now. Its already 0.\n";
	 }
	 void stop()
	 {
	 	gear=0;
	 	speed=0;
	 	cout<<"Car stopped"<<endl;
	 	cout<<"Gear="<<gear;
	 	cout<<"\nSpeed="<<speed;
	 }
};
int main()
{
		int choice;
		vehicle v;
		while(choice!=7)
		{
			printf("\n\n1 Start\n2 Increase Gear\n3 Decrease Gear\n4 Increase Speed\n5 Decrease Speed\n6 Stop\n7 Exit.");
			printf("\n\nEnter your choice=");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
				v.start();
				break;
				
				case 2:
				v.setinrgear();
				break;
				
				case 3:
				v.setdcrgear();
				break;
				
				case 4:
				v.setinrspeed();
				break;
				
				case 5:
				v.setdcrspeed();
				break;
				
				case 6:
				v.stop();
				break;
				
				case 7:
				exit(0);
				break;	
						
			}	
		}
		return 0;
}
