package Maths.Statistics;

import java.util.Arrays;

class Statistics
{
	 public double mean(int[] numbers) {
        int sum = 0;
        for (int i = 0; i < numbers.length; i++) {
            sum += numbers[i];
        }
        return (double) sum / numbers.length;
    }

	public static double median(int[] numbers) {
        Arrays.sort(numbers);
        int n = numbers.length;
        if (n % 2 == 0) {
            return (numbers[n/2 - 1] + numbers[n/2]) / 2.0;
        } else {
            return numbers[n/2];
        }
    }
};

