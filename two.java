public class two {
    public static void main(String[] args){
        boolean first = true;
        int one = 1;
        int two = 1;
        int sum = 1;
        while (one < 4000001 && two < 4000001){
            if (first){
                one += two;
                if (one % 2 == 0) sum += one;
            }
            else {
                two += one;
                if (two % 2 == 0) sum += two;
            }
            first = !first;
        }
        System.out.println(sum);
    }
}