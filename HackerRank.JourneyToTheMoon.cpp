// https://www.hackerrank.com/challenges/journey-to-the-moon/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> vvi(n, vector<int>());
    while (k--) {
        int from, to;
        cin >> from >> to;

        vvi[from].push_back(to);
        vvi[to].push_back(from);
    }

    std::function<void(const vector<vector<int>>&, vector<int>&, int, int, int&)> DFS;
    DFS = [&DFS](const vector<vector<int>>& _v, vector<int>& _m, int _idx, int _idxToSet, int& cnt) {
        if (_m[_idx] != -1)
            return;

        _m[_idx] = _idxToSet;
        cnt++;

        for (int i = 0; i < _v[_idx].size(); ++i)
            DFS(_v, _m, _v[_idx][i], _idxToSet, cnt);
    };

    vector<int> masks(n, -1);
    vector<int> cntrs;
    for (int i = 0; i < masks.size(); ++i) {
        int cnt = 0;
        DFS(vvi, masks, i, i, cnt);
        if (cnt)
            cntrs.push_back(cnt);
    }
    
    long long result = 0;
    long long sum = 0;
    for (int i = 0; i < cntrs.size(); ++i) {
        result += sum * cntrs[i];
        sum += cntrs[i];
    }

    cout << result;
    
    return 0;
}
