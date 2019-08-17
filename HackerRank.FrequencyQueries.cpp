#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int main()
{
    int n = readInt();

    unordered_map<int, int> mp;
    unordered_map<int, int> freq;
    while (n--) {
        int op = readInt();
        int arg = readInt();
        if (op == 1)
        {
            auto it = mp.find(arg);
            if (it != mp.end())
            {
                int f = it->second;
                freq[f]--;
                mp[arg]++;
                freq[f + 1]++;
            }
            else
            {
                mp[arg] = 1;
                freq[1]++;
            }
        }
        else if (op == 2)
        {
            auto it = mp.find(arg);
            if (it != mp.end())
            {
                int f = it->second;
                freq[f]--;
                mp[arg]--;

                f = mp[arg];
                if (f == 0)
                    mp.erase(arg);
                else
                    freq[f]++;
            }
        }
        else if (op == 3)
            printf("%d\n", freq[arg] ? 1 : 0);
    }

    return 0;
}
