package com.company;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {

    static final long MOD = 1000000007;

    static long countArray(int n, int k, int x) {
        long[] dpNext = new long[2];
        long[] dp = new long[2];

        dp[0] = 1;
        dp[1] = 0;
        for (int i = 0; i < n - 1; ++i) {
            dpNext[0] = (dp[1] * (k - 1)) % MOD;
            dpNext[1] = (dp[0] + dp[1] * (k - 2)) % MOD;
            dp[0] = dpNext[0];
            dp[1] = dpNext[1];
        }

        if (x == 1)
            return dpNext[0];

        return dpNext[1];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int x = in.nextInt();
        long answer = countArray(n, k, x);
        System.out.println(answer);
        in.close();
    }
}

