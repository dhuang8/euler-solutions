import java.util.Arrays;

public class five {

    public static boolean[] not_prime = new boolean[20 + 1];

    public static int[] primeFac(int n) {
        int cur = 2;
        int[] result = new int[n + 1];
        while (n >= cur) {
            if (not_prime[cur]) {
                cur++;
            } else {
                for (int m = cur*2; m < not_prime.length; m += cur) {
                    not_prime[m] = true;
                }
                while (n >= cur) {
                    if (n % cur == 0) {
                        result[cur]++;
                        n /= cur;
                    } else {
                        cur++;
                        break;
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] curPrimeFac = new int[21];
        for (int i = 2; i < 21; i++) {
            int[] thisArr = primeFac(i);
            for (int j=2;j<thisArr.length;j++){
                if (thisArr[j]>curPrimeFac[j]) curPrimeFac[j]=thisArr[j];
            }
            //System.out.println(Arrays.toString(primeFac(i)));
        }
        //System.out.println(Arrays.toString(not_prime));

        int cur = 1;
        for (int j=2;j<curPrimeFac.length;j++){
            cur *= Math.pow(j,curPrimeFac[j]);
        }
        System.out.println(cur);
    }
}