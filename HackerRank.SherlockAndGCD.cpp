#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        int g = 0;
        while (n--) {
            int x;
            cin >> x;
            
            if (g != 1)
                g = gcd(g, x);
        }
        
        if (g == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
