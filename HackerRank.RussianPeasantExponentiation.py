#!/bin/python3

import os
import sys

def mult(a, b, c, d):
    res = []
    return [a * c - b * d, b * c + a * d]

# Complete the solve function below.
def solve(a, b, k, m):
    # k - order
    # m - mod
    resr = 1
    resi = 0
    curr = a
    curi = b
    while k > 0:
        if k & 1:
            resr, resi = mult(resr, resi, curr, curi)
            resr = resr % m
            resi = resi % m
        k = k >> 1
        curr, curi = mult(curr, curi, curr, curi)
        curr = curr % m
        curi = curi % m

    return [resr, resi]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        abkm = input().split()

        a = int(abkm[0])

        b = int(abkm[1])

        k = int(abkm[2])

        m = int(abkm[3])

        result = solve(a, b, k, m)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()

