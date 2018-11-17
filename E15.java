public class E15 {

    public static long[][] grid = new long[21][21];

    public static long pathCount(int x, int y) {
        if (grid[x][y]>0) return grid[x][y];
        long ans=0;
        if (x>0) ans+=pathCount(x-1,y);
        if (y>0) ans+=pathCount(x,y-1);
        grid[x][y] = ans;
        return ans;
    }
    
    public static void main(String[] args) {
        grid[0][0]=1;
        System.out.println(pathCount(20,20));
    }
}