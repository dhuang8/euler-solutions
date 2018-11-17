import java.util.Arrays;

public class six {

    public static int squareOfSum(int n) {
        return (int) Math.pow(n*(n+1)/2,2);
    }

    public static int sumOfSquares(int n) {
        int cur = 0;
        for (int i=1;i<n+1;i++){
            cur += i*i;
        }
        return cur;
    }

    public static void main(String[] args) {
        System.out.println(sumOfSquares(100) - squareOfSum(100));
    }
}