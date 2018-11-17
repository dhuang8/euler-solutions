import java.math.BigInteger;

public class E12 {

    public static void main(String[] args) {
        int max = 100000000;
        //System.out.println(max);
        int[] nums = new int[max];
        int[] facCount = new int[max];

        for (int i=2;i<max;i*=2) {
            for (int j=i;j<max;j+=i){
                facCount[j]++;
            }
        }

        for (int i=2;i<max;i++) {
            nums[i] = facCount[i];
        }

        for (int curPrime=3;curPrime<max;curPrime++){
            if (nums[curPrime]>0) continue;
            
            facCount = new int[(max-1)/curPrime+1];

            for (int i=1;i<facCount.length;i*=curPrime) {
                for (int j=i;j<facCount.length;j+=i){
                    facCount[j]++;
                }
            }

            for (int i=1;i<facCount.length;i++) {
                if (nums[i*curPrime]<1) nums[i*curPrime]=1;
                nums[i*curPrime] *= facCount[i]+1;
                if (nums[i*curPrime]>250) max = i*curPrime;
            }
        }

        //System.out.println(max);

        


        for (int i =1;i<max;i++){
            if (nums[i]*nums[i+1]>500) {
                System.out.println(i);
                return;
            }
            
            //System.out.println(i+ ": " + nums[i]);
        }

/*
        int cur = 2;
        long curSum = 0;
        while (cur < not_prime.length) {
            if (not_prime[cur]) {
                cur++;
            } else {
                curSum = curSum + cur;
                for (int m = cur*2; m < not_prime.length; m += cur) {
                    not_prime[m] = true;
                }
                cur++;
            }
        }*/
    }
}