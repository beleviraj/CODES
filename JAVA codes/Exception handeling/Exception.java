import java.io.IOException;

public class Exception
{
    public static void main(String args[])
    {
        // int a=5;
        // int b=0;
        // int d=a/b;
       // String a=null;
       String a="Hello World!";
       char c=a.charAt(14);
       System.out.println(c);
        try
        {
            // int[] a=new int[5];
            // a[6]=9;
        }
        catch(ArithmeticException e)
        {
            System.out.println("Arithmetic Exception");
            System.out.println(e.getMessage());
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Index out of bound Exception"+ e );
            System.out.println ("Array Index is Out Of Bounds"); 
        }
        catch(NumberFormatException e)
        {
            System.out.println("Number Format Exception"+ e );
        }
        catch(NullPointerException e)
        {
            System.out.println("Null pointer Exception"+ e );
        }
        catch(StringIndexOutOfBound e)
        {
            System.out.println("String Index out of bound Exception"+ e );
        }
        

    }
}