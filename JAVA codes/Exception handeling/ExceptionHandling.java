class UserDefinedException extends Exception {
    public UserDefinedException(String message) {
        super(message);
    }

    public static String TooLongAddition() {
        return "Too long addition";
    }

    public static String NegativeNumber() {
        return "Negative Number";
    }
}

class VerifyOperation {
    void verify(int val) throws UserDefinedException {
        if (val < 0) {
            throw new UserDefinedException(UserDefinedException.NegativeNumber());
        } else if (val > 9999) {
            throw new UserDefinedException(UserDefinedException.TooLongAddition());
        } else {
            System.out.println("Valid Number");
        }
    }
}

public class ExceptionHandling {
    public static void main(String[] args) {
        try {
            // Arithmetic exception
            // int i = 1;
            // int j = 0;
            // int k = i / j;
            // System.out.println("Value of k is: " + k);

            // Array index out of bounds exception
            // int[] arr = new int[10];
            // for (int i = 0; i < 11; i++) {
            //     System.out.println("hi " + arr[i]);
            // }

            // Null pointer exception
            // String s = null;
            // System.out.println(s.length());

            // Testing custom exception
            VerifyOperation u1 = new VerifyOperation();
            u1.verify(100000000);
        } catch (ArithmeticException e) {
            System.out.println("Arithmetic Exception is (" + e + ")");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array out of bound Exception is (" + e + ")");
        } catch (NullPointerException e) {
            System.out.println("Null Pointer Exception is (" + e + ")");
        } catch (UserDefinedException e) {
            System.out.println("UserDefinedException: " + e.getMessage());
        }
    }
}
