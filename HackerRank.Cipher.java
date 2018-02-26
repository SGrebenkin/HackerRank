// https://www.hackerrank.com/challenges/cipher/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {

    static String cipher(int k, String s) {
        int[] res = new int[k + 1];
        int bnd = s.length() - k + 1;

        StringBuilder f = new StringBuilder();
        int prev = 0;
        for (int i = 0; i < Math.min(k, bnd); ++i) {
            int tmp = s.charAt(i) - '0';
            res[i] = tmp ^ prev;
            f.append((char) ('0' + res[i]));
            prev = tmp;
        }

        int md = k + 1;

        for (int i = Math.min(k, bnd); i < bnd; ++i) {
            int tmp = s.charAt(i) - '0';
            res[i % md] = tmp ^ prev ^ res[(i + 1) % md];
            f.append((char) ('0' + res[i % md]));
            prev = tmp;
        }

        return f.toString();
    }

    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new FileInputStream(new File(args[0])));
            int n = in.nextInt();
            int k = in.nextInt();
            String s = in.next();
            String result = cipher(k, s);
            System.out.println(result);
            in.close();
        } catch (Exception ex) {
            System.out.println(ex.toString());
        }
    }
}
