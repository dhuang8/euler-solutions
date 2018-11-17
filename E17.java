public class E17 {

    public static void main(String[] args) {
        int[] numLetterCount = new int[1001];
        numLetterCount[1] = 3;
        numLetterCount[2] = 3;
        numLetterCount[3] = 5;
        numLetterCount[4] = 4;
        numLetterCount[5] = 4;
        numLetterCount[6] = 3;
        numLetterCount[7] = 5;
        numLetterCount[8] = 5;
        numLetterCount[9] = 4;
        numLetterCount[10] = 3;
        numLetterCount[11] = 6;
        numLetterCount[12] = 6;
        numLetterCount[13] = 8;
        numLetterCount[14] = 8;
        numLetterCount[15] = 7;
        numLetterCount[16] = 7;
        numLetterCount[17] = 9;
        numLetterCount[18] = 8;
        numLetterCount[19] = 8;
        numLetterCount[20] = 6;
        numLetterCount[30] = 6;
        numLetterCount[40] = 5;
        numLetterCount[50] = 5;
        numLetterCount[60] = 5;
        numLetterCount[70] = 7;
        numLetterCount[80] = 6;
        numLetterCount[90] = 6;
        for (int i = 20; i < 100; i += 10) {
            for (int j = 1; j < 10; j++) {
                numLetterCount[i + j] = numLetterCount[i] + numLetterCount[j];
            }
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 100; j++) {
                if (j == 0) {
                    numLetterCount[i * 100] = numLetterCount[i] + 7;
                } else {
                    numLetterCount[i * 100 + j] = numLetterCount[i * 100] + numLetterCount[j] + 3;
                }
            }
        }
        numLetterCount[1000] = 11;//one thousand
        int total = 0;
        for (int i = 1; i < 1001; i++) {
            total += numLetterCount[i];
        }
        System.out.println(total);
    }
}