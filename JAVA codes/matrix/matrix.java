package matrix;
import java.util.Scanner;

public class matrix 
{
    public static void main(String args[])
    {   
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no rows of array: ");
        int r=sc.nextInt();
        System.out.println("Enter the no column of array: ");
        int c=sc.nextInt();
        int M1[][]=new int [r][c];
        int M2[][]=new int [r][c];
        System.out.println("Enter the elements of 1st array: ");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
             M1[i][j]=sc.nextInt();
            }
        }
        System.out.println("Enter the elements of 2nd array: ");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
             M2[i][j]=sc.nextInt();
            }
        }
        System.out.println("Elements of 1st array are: ");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                System.out.print(" " +M1[i][j]);
            }
            System.out.println();
        }
        System.out.println("Elements of 2nd array are: ");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                System.out.print(" " +M2[i][j]);
            }
            System.out.println();
        }
        int choice=0;
        while(choice!=6)
        {   
            System.out.println(" Enter your choice: ");
            System.out.println("1.ADDITION\n2.SUBSTRACTION\n3.MULTIPLICATION\n4.TRANSPOSE of 1st MATRIX\n5.TRANSPOSE of 2nd MATRIX\n6.EXIT");
            System.out.println("___________________________");
            choice=sc.nextInt();
            switch(choice)
            {
                case 1:System.out.println("The addition is: ");
                        addition(M1,M2,r,c);
                        break;
                case 2:System.out.println("The substraction is: ");
                        substraction(M1,M2,r,c);
                        break;
                case 3:System.out.println("The multiplication is: ");
                        multiplication(M1,M2,r,c);
                        break;
                case 4:System.out.println("The Transpose of 1st matrix is: ");
                        transpose1(M1,r,c);
                        break;
                case 5:System.out.println("The Transpose of 2nd matrix is: ");
                        transpose1(M2,r,c);
                        break;
                case 6:break;
                default:System.out.println("INVALID!!! ");
                        break;
            }
        }  
        sc.close();
    }

    public static void addition(int M1[][],int M2[][],int r,int c)
        {
            int M3[][]=new int [r][c];
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {   
                    M3[i][j]=M1[i][j]+M2[i][j];
                    System.out.print("  " +M3[i][j]);
                }
                System.out.println();
            }
        }
    
    public static void substraction(int M1[][],int M2[][],int r,int c)
        {
            int M3[][]=new int [r][c];
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {   
                    M3[i][j]=M1[i][j]-M2[i][j];
                    System.out.print("  " +M3[i][j]);
                }
                System.out.println();
            }
        }

    public static void transpose1(int M1[][],int r,int c)
        {
            int M3[][]=new int [r][c];
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {   
                    M3[i][j]=M1[j][i];
                    System.out.print("  " +M3[i][j]);
                }
                System.out.println();
            }
        }

    public static void transpose2(int M2[][],int r,int c)
        {
            int M3[][]=new int [r][c];
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {   
                    M3[i][j]=M2[j][i];
                    System.out.print("  " +M3[i][j]);
                }
                System.out.println();
            }
        }
    public static void multiplication(int M1[][],int M2[][],int r,int c)
        {
            int M3[][]=new int [r][c];
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {   
                    for(int k=0;k<c;k++)
                    {
                    M3[i][j]+=M1[i][k]*M2[k][j];
                    }
                    System.out.print("  " +M3[i][j]);
                }
                System.out.println();
            }
        }
    
}
