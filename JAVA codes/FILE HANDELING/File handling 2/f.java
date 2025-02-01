import java.io.*;
import java.util.Scanner;
class f
{
    public static void main(String[] args)
    {
        File file = new File("C:\\Users\\ASUS\\OneDrive\\Desktop\\VIRAJ\\java codes\\FILE HANDELING\\File handling 2\\t.txt");
        if(file.exists())
        {
            System.out.println("Sorry File already present");
        }
        else
        {
        
            file.mkdir();
            System.out.println("file created!");
        }
    int choice=0;
    while(choice!=0)
    {
        System.out.println("1.Create a file");
        System.out.println("2.Delete a file");
        System.out.println("3.Write");
        System.out.println("4.Read");
        System.out.println("5.Exit");
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your choice");
        choice = sc.nextInt();
        switch(choice)
        {
            case 1: try {
                File Obj = new File("myfile.txt");
                if (Obj.createNewFile()) {
                    System.out.println("File created: "
                                       + Obj.getName());
                }
                else {
                    System.out.println("File already exists.");
                }
            }
            catch (IOException e) {
                System.out.println("An error has occurred.");
                e.printStackTrace();
            }
        }

    }
    }
}

