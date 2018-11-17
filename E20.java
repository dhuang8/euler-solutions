import java.math.*;

public class E20 {

    public static void main(String[] args) {
        BigInteger bi = new BigInteger("1");
        for (int i = 100; i > 0; i--) {
            bi = bi.multiply(new BigInteger("" + i));
        }
        String num = bi.toString();
        int total = 0;
        for (int i = num.length() - 1; i > -1; i--) {
            total += Character.getNumericValue(num.charAt(i));
        }
        System.out.println(total);
    }
}