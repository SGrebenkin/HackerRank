#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    long long int tmp = s[0] - '0';
    long long int sum = tmp;
    const long long int MOD = 1000000007;
    for (int i = 1; i < s.size(); ++i) {
        tmp = (tmp * 10 + (s[i] - '0')*(i + 1)) % MOD;
        sum = (sum + tmp) % MOD;
    }
    
    cout << sum << endl;
    
    return 0;
}