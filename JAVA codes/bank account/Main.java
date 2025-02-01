class UserDefinedException extends Exception {
    public UserDefinedException(String message) {
        super(message);
    }
}

class LowBalanceException extends UserDefinedException {
    public LowBalanceException(String message) {
        super(message);
    }
}

class NegativeNumberException extends UserDefinedException {
    public NegativeNumberException(String message) {
        super(message);
    }
}

class BankAccount {
    private String accountNumber;
    private String accountHolderName;
    private double balance;

    public BankAccount() {
        this("UNKNOWN", "UNKNOWN", 0.0);
    }

    public BankAccount(String accountNumber, String accountHolderName, double initialBalance) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.balance = initialBalance;
    }

    public double getBalance() {
        return balance;
    }

    public void balanceEnquiry() {
        System.out.printf("The current balance for %s is: %.2f%n", accountHolderName, balance);
    }

    public void deposit(double amount) throws NegativeNumberException {
        if (amount <= 0) {
            throw new NegativeNumberException("Deposit amount must be positive.");
        }
        balance += amount;
        System.out.printf("Successfully deposited %.2f. Current balance: %.2f%n", amount, balance);
    }

    public void withdraw(double amount) throws LowBalanceException, NegativeNumberException {
        if (amount <= 0) {
            throw new NegativeNumberException("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw new LowBalanceException("Insufficient balance for withdrawal.");
        }
        balance -= amount;
        System.out.printf("Successfully withdrew %.2f. Current balance: %.2f%n", amount, balance);
    }
}

public class Main {
    public static void main(String[] args) {
        BankAccount account1 = new BankAccount("A123", "John Doe", 1000.00);
        BankAccount account2 = new BankAccount("B456", "Jane Smith", 500.00);

        try {
            account1.balanceEnquiry();
            account2.balanceEnquiry();

            account1.deposit(200.00);
            account2.withdraw(100.00);
            account2.withdraw(1000.00);

        } catch (User DefinedException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}