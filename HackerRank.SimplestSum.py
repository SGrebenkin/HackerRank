#!/bin/python3

# https://www.hackerrank.com/contests/hackerrank-hiring-contest/challenges/the-simplest-sum

import sys

def simplestSum(k, a, b):
    MOD_NUM = 1000000007

    i = 1
    p = k
    sm = 0
    absSum = 0
    fi = 0
    fiNext = 0

    a = a - 1
    while (1):
        fiNext += p
        if (fiNext > a or fiNext > 1000000000000000000):
            break

        fi = fiNext
        sm += i
        absSum += p * sm

        i = i * k + 1
        p *= k
        if (p > 1000000000000000000):
            break;

    sumA = 0
    if (fi == a):
        sumA = absSum
    else:
        sumA = absSum + (a - fi) * (sm + i)

    fiNext -= p;
    dfiNext = fiNext;

    while (1):
        fiNext += p
        if (fiNext > b or fiNext > 1000000000000000000):
            break

        fi = fiNext
        sm += i
        absSum += p * sm

        i = i * k + 1
        p *= k
        if (p > 1000000000000000000):
            break
    
    sumB = 0
    if (fi == b):
        sumB = absSum
    else:
        sumB = absSum + (b - fi) * (sm + i)

    return (sumB - sumA) % MOD_NUM


if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        k, a, b = input().strip().split(' ')
        k, a, b = [int(k), int(a), int(b)]
        result = simplestSum(k, a, b)
        print(result)

