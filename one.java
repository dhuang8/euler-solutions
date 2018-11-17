public class one {
    public static int triangularSum(int n){
        return n*(n+1)/2;
    }
    public static void main(String[] args){
        int sum = triangularSum(999/3)*3 + triangularSum(999/5)*5 - triangularSum(999/15)*15;
        System.out.println(sum);
    } 
}