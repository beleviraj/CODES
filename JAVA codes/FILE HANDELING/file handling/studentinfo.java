import java.io.*;
import java.util.Scanner;

public class studentinfo
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        try
        {
            System.out.println("Enter Roll No: ");
            int rollNo=sc.nextInt();
            System.out.println("Enter Class: ");
            String studentClass=sc.next();
            System.out.println("Enter Age: ");
            int age=sc.nextInt();
            System.out.println("Enter Weight in kg: ");
            float weight=sc.nextFloat();
            System.out.println("Enter Height in cm: ");
            float height=sc.nextFloat();
            System.out.println("Enter City: ");
            String city=sc.next();
            System.out.println("Enter Phone: ");
            String phone=sc.next();

            FileOutputStream F = new FileOutputStream("student_data.txt");
            DataOutputStream D = new DataOutputStream(F);

            D.writeInt(rollNo);
            D.writeUTF(studentClass);
            D.writeInt(age);
            D.writeFloat(weight);
            D.writeFloat(height);
            D.writeUTF(city);
            D.writeUTF(phone);
             D.close();
             F.close();

            FileInputStream FD = new FileInputStream("student_data.txt");
            DataInputStream DF = new DataInputStream(FD);

            System.out.println("\n Student Information:");
            System.out.println("Roll No: " + DF.readInt());
            System.out.println("Class: " + DF.readUTF());
            System.out.println("Age: " + DF.readInt());
            System.out.println("Weight: " + DF.readFloat() + "kg");
            System.out.println("Height: " + DF.readFloat() + "cm");
            System.out.println("City: " + DF.readUTF());
            System.out.println("Phone: " + DF.readUTF());

            DF.close();
            FD.close();
        }
        catch(IOException e)
        {   
            e.printStackTrace();
        }
        finally
        {
            sc.close();
        }
    }
}
