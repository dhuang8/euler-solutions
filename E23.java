import java.math.BigInteger;
import java.util.ArrayList;

public class E23 {

    public static int sumDivisors(int i) {
        int sqrt = (int) Math.sqrt(i);
        int sum = 1;
        for (int j = 2; j <= sqrt; j++) {
            if (i % j == 0) {
                sum += j + i / j;
            }
        }
        if (sqrt * sqrt == i)
            sum -= sqrt;
        return sum;
    }

    public static boolean isAbundant(int n) {
        if (sumDivisors(n) > n)
            return true;
        return false;
    }

    public static void main(String[] args) {
        int max = 28124;

        int[] abundant = new int[max];
        int abundantLen = 0;
        for (int i = 5; i < abundant.length; i++) {
            if (isAbundant(i)) {
                abundant[abundantLen] = i;
                abundantLen++;
            }
        }

        boolean[] sumOfP = new boolean[max];

        for (int i = 0; i < abundantLen; i++) {
            for (int j = i; j < abundantLen; j++) {
                if (abundant[i] + abundant[j] < sumOfP.length)
                    sumOfP[abundant[i] + abundant[j]] = true;
            }
        }

        int sum = 0;
        for (int i = 1; i < sumOfP.length; i++) {
            if (!sumOfP[i]) {
                sum += i;
            }
        }
        System.out.println(sum);
    }
}