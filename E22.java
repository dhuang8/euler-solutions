import java.math.*;
import java.util.*;
import java.io.*;

public class E22<T extends Comparable<? super T>> {

    //in-place insertion sort with binary search
    public static <T extends Comparable<T>> void sort(T[] arr) {
        if (arr.length < 2)
            return;
        for (int i = 1; i < arr.length; i++) {
            int index = binarySearch(arr[i], arr, 0, i - 1);
            T tmp = arr[i];
            int spot = i;
            while (spot > index) {
                arr[spot] = arr[--spot];
            }
            arr[index] = tmp;
        }
    }

    //binary search that returns the index of the first element that is greater than or equal to the search element
    public static <T extends Comparable<T>> int binarySearch(T search, T[] arr, int min, int max) {
        if (min >= max) {
            if (search.compareTo(arr[min]) < 0)
                return min;
            else
                return min + 1;
        }
        int mid = (min + max) / 2;
        if (search.compareTo(arr[mid]) < 0) {
            return binarySearch(search, arr, min, mid - 1);
        } else if (search.compareTo(arr[mid]) == 0) {
            return min + 1;
        } else {
            return binarySearch(search, arr, mid + 1, max);
        }
    }

    public static void main(String[] args) {
        String data = "";
        try {
            FileInputStream in = new FileInputStream("p022_names.txt");
            int i = 0;
            while ((i = in.read()) != -1) {
                data += (char) i;
            }
            in.close();
            //System.out.println(data);
        } catch (Exception e) {
            System.out.println(e);
            System.exit(0);
        }

        String[] dataArr = data.split(",");
        sort(dataArr);
        BigInteger total = BigInteger.valueOf(0);
        for (int j = 0; j < dataArr.length; j++) {
            int curtotal = 0;
            for (int k = 0; k < dataArr[j].length(); k++) {
                int charCode = Character.codePointAt(dataArr[j], k);
                if (charCode > 64 && charCode < 91) {
                    curtotal += charCode - 64;
                }
            }
            total = total.add(BigInteger.valueOf(curtotal * (j + 1)));
        }
        System.out.println(total);
    }
}