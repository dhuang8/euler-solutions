public class three {
    public static void main(String[] args) {
        double theNum = 600851475143.0;
        double max = Math.sqrt(theNum);
        boolean[] not_prime = new boolean[(int)max+1];
        double max_prime = 1;
        int cur = 2;
        while (theNum >= cur) {
            if (not_prime[cur]) {
                cur++;
            }
            else {
                for (int m = cur*2; m<max;m+=cur){
                    not_prime[m] = true;
                }
                while (theNum >= cur){     
                    if (theNum % cur == 0) {
                        max_prime = cur;
                        theNum/=cur;
                    }
                    else {
                        cur++;
                        break;
                    }
                }
            }
        }
        System.out.println(max_prime);
    }
}