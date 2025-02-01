class bankacc
{
	private String accnumber;
	private String accholdername;
	private double balance;
	
 	bankacc()
	{
		accholdername="UNKNOWN";
		accnumber="UNKNOWN";
		balance=0.0;
	}
	
	bankacc(String number,String name,double amount)
	{	
		accnumber=number;
		accholdername=name;
		balance=amount;
	}
	
	bankacc(bankacc B)
	{
		accnumber=B.accnumber;
		accholdername=B.accholdername;
		balance=B.balance;
	}

	
	public void deposit(double amount)
	{
		balance+=amount;
		System.out.println("The deposited amount  is :"+amount);
		System.out.println("The balance is :"+balance);
	}
	
	public void withdraw(double amount)
	{
		if(balance>=amount)
		{
			balance-=amount;
			System.out.println("The withdrawal amount  is :"+amount);
			System.out.println("The balance is :"+balance);
		}
		else
		{
			System.out.println("INSUFFICIENT BALANCE");
			System.out.println("The balance is :"+balance);
		}	
	}
	public void details()
	{
		System.out.println("Account number:  "+accnumber);
		System.out.println("Account Holder name:  "+accholdername);
		System.out.println("Account Balance:  "+balance);
		System.out.println("------------------------");
	}
	public static  void main(String args[])
	{
		
		bankacc acc1=new bankacc();
		acc1.details();
		bankacc acc2=new bankacc(acc1);
		acc2.details();
		bankacc acc3=new bankacc("A-313433","VIRAJ BELE",1000);
		acc3.deposit(200d);
		System.out.println("------------------------");
		acc3.withdraw(100d);
		System.out.println("------------------------");
		acc3.details();
		
		
	}

};