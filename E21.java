import java.math.*;
import java.util.*;

public class E21 {

    public static int sumDivisors(int i) {
        int sqrt = (int)Math.sqrt(i);
        int sum = 1;
        for (int j = 2; j < sqrt; j++) {
            if (i % j == 0) {
                sum += j + i/j;
            }
        }
        if (i % sqrt == 0)
            sum += sqrt;
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(sumDivisors(220));
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i=1;i<10000;i++) {
            //search ArrayList
            if (list.indexOf(i)<0) {
                int a = sumDivisors(i);
                if (a!=i) {
                    int b = sumDivisors(a);
                    if (b==i) {
                        list.add(i);
                        list.add(a);
                    }
                }
            }
        }
        Iterator<Integer> it = list.iterator();
        int total = 0;
        while (it.hasNext()){
            total+=it.next();
        }
        System.out.println(total);
    }
}