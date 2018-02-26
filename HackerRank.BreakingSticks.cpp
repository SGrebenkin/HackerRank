// https://www.hackerrank.com/contests/world-codesprint-12/challenges/breaking-sticks

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
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
  
    vector <long long> data(n);
    for (int i = 0; i < n; i++)
        cin >> data[i];

    long long cnt = 0;
    for (auto a: data) {
        vector<long long> divisors;
        factors(a, [&](long long fct){
            divisors.push_back(fct);
        });

        cnt++;
        if (a == 1)
            continue;
        
        long long cur = 1;
        for (auto rit = divisors.rbegin(); rit != divisors.rend(); ++rit) {
            cur *= *rit;
            cnt += cur;
        }
    }

    cout << cnt << endl;    
 
    return 0;
}
