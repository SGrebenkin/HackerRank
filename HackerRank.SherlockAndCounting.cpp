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
        long long n, k;
        cin >> n >> k;
        
        long long discr = n - 4 * k;
        if (discr <= 0) {
            cout << n - 1 << endl;
            continue;
        }

        discr *= n;
        double discrSqrt = sqrt(discr);
    
        double x0 = (n - discrSqrt)/2;
        double x1 = (n + discrSqrt)/2;

        cout << (long long) (floor(x0) + floor(n - x1)) << endl;
    }

    return 0;
}
