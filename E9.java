import java.util.Arrays;

public class E9 {

    public static void main(String[] args) {
        for (int a=0;a<333;a++){
            for (int b=a+1;b<((1000-a)/2);b++){
                int c = 1000-b-a;
                if (a*a+b*b==c*c) {
                    System.out.println(a * b * c);
                    break;   
                }
            }
        }
    }
}