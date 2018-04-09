// https://www.hackerrank.com/contests/hackerrank-hiring-contest/challenges/winning-lottery-ticket/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    const int m = 1024;
    int arr[m];
    memset(arr, 0, sizeof(arr));
    
    unordered_set<string> st;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        int res = 0;
        for (auto c: s)
            res |= (1 << static_cast<int>(c - '0'));
        
        arr[res]++;
    }

    unsigned long long int cnt = 0;
    for (int i = 0; i < m - 1; ++i)
        for (int j = i + 1; j < m; ++j)
            if ((i | j) == 1023)
                cnt += arr[i] * arr[j];

    cnt += (static_cast<unsigned long long int>(arr[m - 1]) * static_cast<unsigned long long int>(arr[m - 1] - 1)) / 2;
    
    cout << cnt << endl;

    return 0;
}
