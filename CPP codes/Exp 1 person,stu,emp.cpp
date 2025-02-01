#include<iostream>
using namespace std;
class person
{
	private:
		string name;
		string address;
		string phone;
		string birthdate;
		
		string classs;
		string prn;
		float avgmark;
		
		int id;
		string designation;
		float salary;
		
	public:
		//Functions for Person 
	void setname(string n)
	{
			name=n;
	}	
	string getname()
	{
		return name;
	}
	void setaddress(string a)
	{
			address=a;
	}	
	string getaddress()
	{
		return address;
	}
	
	void setphone(string p)
	{
			phone=p;
	}	
	string getphone()
	{
		return phone;
	}
	
	void setbirthdate(string b)
	{
			birthdate=b;
	}	
	string getbirthdate()
	{
		return birthdate;
	}
	
	void setprn(string pr)
	{
		prn=pr;
	}
	string getprn()
	{
		return prn;
	}
};

int main()
{
	person p1;
	p1.setname("Siddhi Lipare");
	cout<<"Name:-"<<p1.getname()<<endl;
	
	p1.setaddress("Near IGM hospital,Ich");
	cout<<"Address:-"<<p1.getaddress()<<endl;
	
	p1.setphone("98xxxxx1");
	cout<<"Phone:-"<<p1.getphone()<<endl;	
	
	p1.setbirthdate("07 MAY 2004");
	cout<<"Birthdate:-"<<p1.getbirthdate()<<endl;
	cout<<endl;
	
	person s1;
	s1.setprn("22uad035");
	cout<<"PRN:-"<<s1.getprn();
	
	return 0;
}
