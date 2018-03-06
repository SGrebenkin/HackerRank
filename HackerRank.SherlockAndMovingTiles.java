import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long l = sc.nextLong();
        int s1 = sc.nextInt();
        int s2 = sc.nextInt();
        int q = sc.nextInt();
        while (--q >= 0) {
            long cr = sc.nextLong();
            if (cr >= l*l) {
                System.out.println(0.f);
                continue;
            }

            double v = Math.abs(s1 - s2) * Math.sqrt(2) / 2;
            double descr = 4*l*l*v*v - 4 * (l*l - cr)*v*v;
            if (descr < 0) {
                System.out.println(0.f);
                continue;
            }
            
            double t1 = (2*l*v + Math.sqrt(descr)) / (2*v*v);
            double t2 = (2*l*v - Math.sqrt(descr)) / (2*v*v);
            
            if (t1 < t2 && t1 >= 0)
                System.out.println(t1);
            else if (t1 > t2 && t2 >= 0)
                System.out.println(t2);
            else
                System.out.println(0.f);
        }
    }
}