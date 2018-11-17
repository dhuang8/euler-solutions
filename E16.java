public class E16 {

    public static void main(String[] args) {
        int[] digits = new int[1000];
        int maxDigit = 0;
        digits[0] = 1;
        for (int i = 0; i < 1000; i++) {
            for (int j = maxDigit; j > -1; j--) {
                digits[j] *= 2;
                if (digits[j] / 10 > 0) {
                    digits[j + 1] += digits[j] / 10;
                    if (j + 1 > maxDigit) {
                        maxDigit = j + 1;
                        System.out.println(maxDigit);
                    }
                    digits[j] = digits[j] % 10;
                }
            }
        }
        int sum = 0;
        for (int j = 0; j < maxDigit+1; j++) {
            System.out.println(j + ": " + digits[j]);
            sum += digits[j];
        }
        System.out.println(sum);
    }
}