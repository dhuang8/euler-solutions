public class E19 {

    public static int getDaysInMonth(int month, int year) {
        if (year%4==0 && month==2) {
            if (year%100==0) {
                if (year%400==0) {
                    return 29;
                }
            }
            else return 29;
        }
        int[] days = new int[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[month-1];
    }

    public static void main(String[] args) {
        int count = 0;
        int month = 1;
        int day = 6;
        int year = 1901;
        while (year < 2001) {
            if (day == 1) {
                count++;
            }
            day += 7;
            int numDays = getDaysInMonth(month, year);
            if (day > numDays) {
                day -= numDays;
                month++;
            }
            if (month > 12) {
                month -= 12;
                year++;
            }
            //System.out.println(month+"/"+day+"/"+year);
        }
        System.out.println(count);
    }
}