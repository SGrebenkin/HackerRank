#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
    long n, r;
    cin >> n >> r;

    long res = 0;
    map<long, long> m0;
    map<long, long> m1;
    while (n--) {
        long x;
        cin >> x;

        if (x % r == 0 && m1.count(x / r))
            res += m1[x / r];

        if (x % r == 0 && m0.count(x / r))
            m1[x] += m0[x / r];

        m0[x]++;
    }

    cout << res;

    return 0;
}