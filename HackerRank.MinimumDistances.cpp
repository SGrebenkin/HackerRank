#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        
        if (mp.find(x) == mp.end())
            mp[x] = make_pair(i, -1);
        else
            mp[x].second = i - mp[x].first;
    }
    
    int mn = -1;
    for (auto el: mp)
        if (mn == -1 || (el.second.second != -1 && el.second.second < mn))
            mn = el.second.second;
    
    cout << mn << endl;
    
    return 0;
}