#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the divisors function below.
 */
int divisors(int n) {
    if (n % 2)
        return 0;
    
    int exp = 0;
    while (n % 2 == 0) {
        exp++;
        n /= 2;
    }
    
    int full = exp;
    for (int i = 3; i <= sqrt(n); i += 2) {
        exp = 0;
        while (n % i == 0) {
            n /= i;
            exp++;
        }
        full *= exp + 1;
    }

    if (n > 2)
        full *= 2;
    
    return full;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = divisors(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
