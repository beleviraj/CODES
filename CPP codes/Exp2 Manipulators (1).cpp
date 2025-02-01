#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	
	char name[100];
	cout<<"Enter the movie name:-";
	cin>>name;
//	getchar();
	//cout<<endl;
	
	int tickets;
	cout<<"Enter the number of tickests sold:-";
	cin>>tickets;
	
	double gross;
	cout<<"Enter the gross amount:-";
	cin>>gross;
	
	double pergross;
	cout<<"Enter the percentage of gross amount:-";
	cin>>pergross;
	
	double amountdenoted;
	amountdenoted=(gross/100)*pergross;
	
	double netsale;
	netsale=gross-amountdenoted;
	cout<<endl;
	cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
	cout<<"\nMovie Name:-"<<setfill('.')<<setw(30)<<right<<name<<endl;
	cout<<"Number of Tickets sold:-"<<setfill('.')<<setw(18)<<right<<tickets<<endl;
	cout<<"Gross Amount:-"<<setfill('.')<<setw(21)<<"$"<<fixed<<setprecision(2)<<gross<<endl;
	cout<<"Percentage of gross amount denoted:-"<<fixed<<setprecision(2)<<pergross<<"%"<<endl;
	cout<<"Amount Denoted:-"<<setfill('.')<<"$"<<fixed<<setprecision(2)<<amountdenoted<<endl;
	cout<<"Net Sale:-"<<setfill('.')<<setw(25)<<"$"<<fixed<<setprecision(2)<<netsale<<endl;
	cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n\n";
	
}
