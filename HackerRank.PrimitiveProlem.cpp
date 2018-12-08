#include <bits/stdc++.h>
#include <numeric>

using namespace std;

template <class F>
void factors(long long int n, F f) {
    // Print the number of 2s that divide n
    while (n%2 == 0) {
        f(2);
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2) {
        // While i divides n, print i and divide n
        while (n%i == 0) {
            f(i);
            n = n/i;
        }
    }

    if (n > 2)
        f(n);
}

long long int gcd(long long int a, long long int b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long int pw(long long int a, long long int b) {
    long long res = a;
    for (int k = 1; k < b; ++k)
        res *= a;
    
    return res;
}

long long int pw(long long int a, long long int b, long long int p) {
    long long res = a;
    for (int k = 1; k < b; ++k) {
        res *= a;
        res = res % p;
    }
    
    return res;
}

int main()
{
    long long int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // s factorization
    long long int s = p - 1; // p - prime
    map<long long int, int> primes;
    int cnt = 0;
    factors(s, [&](long long int i){
        if (primes.find(i) == primes.end())
            primes[i] = 1;
        else
            primes[i]++;
    });
    
    // finding a^(s/p_i)
    vector<long long int> arr;
    long long int firstPrimitive = -1;
    for (long long int a = 2; a < p; ++a) {
        bool is_primitive_root = true;
        for (auto& _p_i: primes) {
            long long int p_i = _p_i.first;
            if (pw(a, s/p_i, p) % p == 1) {
                is_primitive_root = false;
                break;
            }
        }

        if (is_primitive_root) {
            firstPrimitive = a;
            break;
        }
    }

    set<long long int> roots;
    roots.insert(firstPrimitive);
    
    // Generate all the other primitive roots
    // cout << firstPrimitive << endl;
    for (int i = 1; i < p; ++i) {
        // check m and s are coprime
        if (gcd(i, s) == 1)
            roots.insert(pw(firstPrimitive, i, p));
    }
 
    cout << firstPrimitive << " " << roots.size() << endl;
    
    return 0;
}
