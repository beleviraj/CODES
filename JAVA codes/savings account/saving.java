import java.util.*;

class saving
{
    static double rate=12;
    double savingbalance;
    saving()
    {
        savingbalance=500;
    }
    saving(double balance)
    {
        savingbalance=balance;
    }
   public void caslculatemonthlyinterest()
    {
            double monthlyinterest=savingbalance*(rate/1200);
            savingbalance=savingbalance+monthlyinterest;
    }

   public static void modifyinterest(double newrate)
    {
        rate=newrate;
    }

   public double getsavingbalance()
    {
        return savingbalance;
    }

    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        saving s1=new saving();
        System.out.println("Enter the saving balance: ");
        s1.savingbalance=sc.nextDouble();
        s1.caslculatemonthlyinterest();
        int choice=0;
        
        while(choice!=3)
        {
            System.out.println("Enter your operation : ");
            System.out.println("1. Modify Interest\n2. Get Saving Balance\n3. Exit");
            choice=sc.nextInt();
            switch(choice)
            {
                case 1:double rate;
                       System.out.println("Enter the new interest rate : ");
                       rate=sc.nextDouble();
                       saving.modifyinterest(rate);
                       s1.caslculatemonthlyinterest();
                break;
                case 2: System.out.println("Saving balance is: " + s1.getsavingbalance());
                break;        
                case 3:
                break;
            }

        }
            sc.close();
    }
};