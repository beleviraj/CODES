import java.util.Random;

class RandomNumberThread extends Thread {
    public void run() {
        Random random = new Random();
        while (true) {
            int num = random.nextInt(100);
            if (num % 2 == 0) {
                new SquareThread(num).start();
            } else {
                new CubeThread(num).start();
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class SquareThread extends Thread {
    int number;
    SquareThread(int number) {
        this.number = number;
    }

    public void run() {
        System.out.println("Square of " + number + " is: " + (number * number));
    }
}

class CubeThread extends Thread {
    int number;
    CubeThread(int number) {
        this.number = number;
    }

    public void run() {
        System.out.println("Cube of " + number + " is: " + (number * number * number));
    }
}

public class MultiThreadApplication {
    public static void main(String[] args) {
        new RandomNumberThread().start();
    }
}
