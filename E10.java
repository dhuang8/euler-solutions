import java.math.BigInteger;

public class E10 {

    public static void main(String[] args) {
        
        boolean[] not_prime = new boolean[2000000];
        //boolean[] not_prime = new boolean[10];
        int cur = 2;
        long curSum = 0;
        while (cur < not_prime.length) {
            if (not_prime[cur]) {
                cur++;
            } else {
                curSum = curSum + cur;
                for (int m = cur*2; m < not_prime.length; m += cur) {
                    not_prime[m] = true;
                }
                cur++;
            }
        }
        System.out.println(curSum);
    }
}