// https://www.hackerrank.com/challenges/closest-number/problem

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    static int closestNumber(int a, int b, int x) {
        return (int) Math.round(Math.pow(a, b) / x)*x;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(scanner.nextLine().trim());

        for (int tItr = 0; tItr < t; tItr++) {
            String[] abx = scanner.nextLine().split(" ");

            int a = Integer.parseInt(abx[0].trim());

            int b = Integer.parseInt(abx[1].trim());

            int x = Integer.parseInt(abx[2].trim());

            int result = closestNumber(a, b, x);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();
    }
}
