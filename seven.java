import java.util.Arrays;

public class seven {

    public static boolean[] not_prime = new boolean[999999999];

    public static int nthPrime(int n) {
        int cur = 2;
        int curNum = 0;
        int[] result = new int[n + 1];
        while (true) {
            if (not_prime[cur]) {
                cur++;
            } else {
                curNum++;
                if (curNum == n) return cur;
                for (int m = cur*2; m < not_prime.length; m += cur) {
                    not_prime[m] = true;
                }
                cur++;
            }
        }
        //return 0;
    }

    public static void main(String[] args) {
        System.out.println(nthPrime(10001));
    }
}