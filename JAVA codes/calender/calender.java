class calender
{
    public void dayname(int day,int month,int year)
        {
        int k=year%100;
        int j=year/100;
        int h=(day +((13*(month + 1))/5)+k+(k/4)+(j/4)+5*j)%7;
        switch(h)
        {
            case 0:
                System.out.println("The day is : SATURDAY");
                break;
            case 1:
                System.out.println("The day is : SUNDAY");
                break;
            case 2:
                System.out.println("The day is : MONDAY");
                break;
            case 3:
                System.out.println("The day is : TUESDAY");
                break;
            case 4:
                System.out.println("The day is : WEBNESDAY");
                break;
            case 5:
                System.out.println("The day is : THURSDAY");
                break;
            case 6:
                System.out.println("The day is : FRIDAY");
                break;
            default:
                System.out.println("INVALID!!");
                break;
        }
        }
    public static void main(String args[])
    {
        //System.out.println("The date is: "+args[0]+"/"+args[1]+"/"+args[2]);
        // int day=Integer.parseInt(args[0]);
        // int month=Integer.parseInt(args[1]);
        // int year=Integer.parseInt(args[2]);
        String str=args[0];
        int day=Integer.parseInt(str.substring(0,2));
        int month=Integer.parseInt(str.substring(3,5));
        int year=Integer.parseInt(str.substring(6));
        System.out.println(day+" "+month+" "+year);
        calender c=new calender();
        c.dayname(day,month,year);
    }
}