public class four {
    public static boolean isPalin(int n){
        String num = "" + n;
        for (int m = 0; m < num.length()/2; m++){
            if (num.charAt(m) != num.charAt(num.length()-1-m)) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        int max = 0;
        for (int i=999;i>99;i--){
            for (int j=i;j>99;j--){
                int cur = i*j;
                if (cur>max && isPalin(cur)){
                    max = cur;
                }
            }
        }
        System.out.println(max);
    }
}