import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n1 = in.nextInt();
        int n2 = in.nextInt();
        int n3 = in.nextInt();
        int h1[] = new int[n1];
        int sum1 = 0;
        for(int h1_i=0; h1_i < n1; h1_i++){
            h1[h1_i] = in.nextInt();
            sum1 += h1[h1_i];
        }
        int h2[] = new int[n2];
        int sum2 = 0;
        for(int h2_i=0; h2_i < n2; h2_i++){
            h2[h2_i] = in.nextInt();
            sum2 += h2[h2_i];
        }
        int h3[] = new int[n3];
        int sum3 = 0;
        for(int h3_i=0; h3_i < n3; h3_i++){
            h3[h3_i] = in.nextInt();
            sum3 += h3[h3_i];
        }
        
        int idx1 = 0, idx2 = 0, idx3 = 0;
        while (true) {
            if (sum1 < sum2 && idx2 < n2)
                sum2 -= h2[idx2++];
            else if (sum1 > sum2 && idx1 < n1)
                sum1 -= h1[idx1++];

            if (sum2 < sum3 && idx3 < n3)
                sum3 -= h3[idx3++];
            else if (sum2 > sum3 && idx2 < n2)
                sum2 -= h2[idx2++];

            if (sum1 == sum2 && sum2 == sum3)
                break;
        }
        System.out.println(sum1);
    }
}
