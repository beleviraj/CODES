#include<iostream>

using namespace std;

	class vehicle{
		private:
			int speed,gear;
			int maxspeed,maxgear;
			bool on,off;
			
		public:
			
			void start()
			{
				on=1, off=0;
				speed=0 ,gear=0;
				cout<<"vehicle is started."<<endl;
				cout<<"current gear:"<<gear<<endl;
				cout<<"current speed:"<<speed<<endl<<endl;
			
			}
			
			void increase()
			{  
			   if(on==1 && off==0){
			   	if(gear>=5)
			     cout<<"reached to max gear."<<endl;
			     
			    else{
			     gear=gear+1;
				 speed=speed+50;
				}
			   	
		    }
			   else
			    cout<<"start the vehicle first."<<endl;
			    
				cout<<"current gear:"<<gear<<endl;
				cout<<"current speed:"<<speed<<endl<<endl;
			}
			
			void decrease()
			{
				if(gear>=1){
				 gear=gear-1;
				speed=speed-50;	
				}
				
				cout<<"current gear:"<<gear<<endl;
				cout<<"current speed:"<<speed<<endl<<endl;
			}
			
			void stop()
			{
				on=0,off=1;
				gear=0,speed=0;
				cout<<"vehicle is stoped."<<endl;
				cout<<"current gear:"<<gear<<endl;
				cout<<"current speed:"<<speed<<endl<<endl;
			}
	};

int main()
{
	vehicle v1;
	int status;
	do{
		cout<<"1-start,2-increase,3-decrease,4-stop:";
		cin>>status;
		
		switch (status){
		 case 1:
		 	v1.start();
		 	break;
		 	
		 case 2:
		 	v1.increase();
		 	break;
		 	
		 case 3:
		 	v1.decrease();
		 	break;
		 	
		 case 4:
		 	v1.stop();
		 	break;
		}
	}while(status!=5);

}
