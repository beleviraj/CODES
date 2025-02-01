import java.util.Scanner;

class arithmatic
{
	public static void main(String args[])
	{
		
		Scanner S=new Scanner(System.in);
		System.out.println("Enter 1st number: ");
		int a=S.nextInt();
		System.out.println("Enter 2nd number: ");
		int b=S.nextInt();
		Add Z=new Add();
		Z.setA(a);
		Z.setB(b);
		int sum=Z.addition();
		System.out.println(" Addition is: "+sum);
		S.close();
	}
}

class Add
{
	private int a;
	private int  b;
	
	void setA(int x){a=x;}
	void setB(int y){b=y;}
	int addition()
	{
	return a+b;
	}
}
