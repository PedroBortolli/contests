import java.util.Scanner;
public class a795 {
    public static void main(String[] args) {
    	Scanner in = new Scanner(System.in);
      int n = in.nextInt();
      int l = in.nextInt();
      int r = in.nextInt();
      int[] a = new int[100005];
      int[] b = new int[100005];
      for (int i = 0; i < n; i++) {
        a[i] = in.nextInt();
      }
      for (int i = 0; i < n; i++) {
        b[i] = in.nextInt();
      }

      int ok = 1;
      for (int i = 0; i < l-1; i++) {
        if (a[i] != b[i]) ok = 0;
      }

      for (int i = r; i < n; i++) {
        if (a[i] != b[i]) ok = 0;
      }

      if (ok == 0) System.out.println("LIE");
      else System.out.println("TRUTH");
    }
}