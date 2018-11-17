import java.math.BigInteger;
import java.util.ArrayList;

public class E14 {
    static int[] collatz = new int[10000000];
    static final BigInteger one = new BigInteger("1");
    static final BigInteger zero = new BigInteger("0");
    static final BigInteger two = new BigInteger("2");
    static final BigInteger three = new BigInteger("3");
    static final BigInteger collatzSize = new BigInteger(""+collatz.length);

    public static int getInt(BigInteger i){
        return Integer.parseInt(i.toString());
    }

    public static int getCollatz(BigInteger i) {
        if (i.compareTo(collatzSize)<0 && collatz[getInt(i)]!=0) {
            return collatz[getInt(i)];
        };
        int ans;
        if (i.mod(two).compareTo(zero)==0) {
            ans = getCollatz(i.divide(two))+1;
        }
        else {
            ans = getCollatz(i.multiply(three).add(one))+1;
        }
        if(i.compareTo(collatzSize)<0) collatz[getInt(i)]=ans;
        return ans;
    }

    public static void main(String[] args) {
        collatz[1]=1;
        int maxChain = 1;
        int bestNum = 1;
        for (int i=2;i<1000000;i++){
            int ans = getCollatz(new BigInteger(""+i));
            if (ans>maxChain) {
                maxChain = ans;
                bestNum=i;
            }
        }
        System.out.println(bestNum);
    }
}