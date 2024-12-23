import java.util.*;
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner (System.in);
        long n = sc.nextLong();
        long a[] = new long [n - 1];
        long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            a[i] = sc.nextLong();
            sum += a[i];
        }

        long sum2 = (n * (n + 1)) / 2;
        long ans = sum2 - sum;


        System.out.println(ans);
    }
}
