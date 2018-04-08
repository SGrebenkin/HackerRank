#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


template <class T>
void factors(long long n, T f) {
    for(long long i=2;i<=(long long)sqrt(n);i++) {
        while(n % i == 0) {
            f(i);
            n /= i;
        }
    }
    if (n > 1)
        f(n);
}

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int num;
        cin >> num;
        
        const int NMAX = 41;
        vector<int> divs(NMAX, 0);
        for (int i = 2; i <= num; ++i) {
            vector<int> temp(NMAX, 0);
            factors(i, [&](int d) { temp[d]++; });
            for (int i = 2; i < NMAX; ++i)
                if (temp[i] > divs[i])
                    divs[i] = temp[i];
        }

        int mlt = 1;
        for (int i = 2; i < NMAX; ++i)
            mlt *= divs[i] ? pow(i, divs[i]) : 1;
        
        cout << mlt << endl;
    }

    return 0;
}
