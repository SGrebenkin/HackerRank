// https://www.hackerrank.com/challenges/candies/problem 

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> data;
    while (n--) {
        int x;
        cin >> x;
        
        data.push_back(x);
    }

    vector<int> res(data.size(), 1);

    int curCnt = 1;
    for (int i = 1; i < data.size(); ++i)
        if (data[i - 1] < data[i])
            res[i] = ++curCnt;
        else
            curCnt = 1;
    
    curCnt = 1;
    for (int i = data.size() - 2; i >= 0; --i)
        if (data[i] > data[i + 1] && res[i] <= res[i+1])
            res[i] = ++curCnt;
        else
            curCnt = 1;

    long long int sum = 0;
    for (int i = 0; i < res.size(); ++i)
        sum += res[i];

    cout << sum << endl;
    
    return 0;
}
