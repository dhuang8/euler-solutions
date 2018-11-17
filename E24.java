import java.util.*;

public class E24 {
    static int count=0;
    /*
    Perm p;
    public E24(Perm p){
        this.p = p;
    }
    
    public class Perm {
        public String s;
        public ArrayList<String> leftover;
    
        public Perm(String s, ArrayList<String> leftover) {
            this.s = s;
            this.leftover = leftover;
        }
    
        public Perm next(int n) {
            ArrayList<String> newLeftover = (ArrayList<String>) leftover.clone();
            return new Perm(s + newLeftover.remove(n), newLeftover);
        }
    }
    */
    public static void listAll(String s, ArrayList<String> a) {
        if (count>1000000) return;
        if (a.size() > 0) {
            for (int i = 0; i < a.size(); i++) {
                ArrayList<String> copy = new ArrayList<String>(a);
                listAll(s + copy.remove(i), copy);
            }
        } else {
            count++;
            if (count==1000000) {
                System.out.println(count + ": " + s);
            }
        }
    }

    public static void main(String[] args) {

        ArrayList<String> s = new ArrayList<String>();
        Collections.addAll(s, "0", "1", "2", "3", "4" , "5" ,"6", "7", "8", "9");
        System.out.println(s);

        //Perm main = new Perm("", s);
        //E24 e = new E24(main);
        listAll("",s);
    }
}