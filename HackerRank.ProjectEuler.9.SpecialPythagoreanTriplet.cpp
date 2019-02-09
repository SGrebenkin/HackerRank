#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int res = 0;
        for (int a = 1; a < n/3; ++a) {
            int b1 = n*n - 2*a*n;
            int b2 = 2*n - 2*a;
            if (b1 % b2 == 0) {
                int b = b1/b2;
                if (b >= n)
                    continue;
                int c = n - b - a;
                if (c >= n)
                    continue;
                int tmp = a*b*c;
                if (tmp > res)
                    res = tmp;
            }
        }
        if (res == 0)
            cout << -1 << endl;
        else
            cout << res << endl;
    }

    return 0;
}
