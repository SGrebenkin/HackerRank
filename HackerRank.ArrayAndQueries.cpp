#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


const unsigned long long int MOD_NUM = 1000000007;

int main() {
  int n;
  cin >> n;

  map<int, int> mp;
  vector<int> v;
  while (n--) {
    int x;
    cin >> x;

    mp[x]++;
    v.push_back(x);
  }

  auto prev = mp.begin();
  auto itm = mp.begin();
  itm++;

  // Pre calculate the cnt
  unsigned long long int cnt = 0;
  // Calculate the number of subsequences
  for (; itm != mp.end(); ++itm) {

    if (itm->first - prev->first == 1) {
      // if the difference between two neighbour elements == 1
      // do some bookkeeping with subsets
      int diff = itm->second - prev->second;
      if (diff < 0)
        cnt += -diff;
    }
    else
      // this means we shall reset the numbers
      // and add the number to cnt
      cnt += prev->second;

    prev = itm;
  }
  cnt += prev->second; // means we reset the numbers

  unsigned long long int sum = 0;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    // Read query
    int id, val;
    cin >> id >> val;

    // Check the map for existance of this
    auto it = mp.find(v[id - 1]);
    if (it != mp.end()) {

      // Before actual deleting let's do some book keeping
      {
        auto prev = it;
        auto next = it;
        next++;

        int curVal = it->first;
        int curCnt = it->second;

        int prevCnt = 0;
        int prevVal = 0;
        if (it == mp.begin())
          prevVal = curVal - 1;
        else {
          prev--; // if it's not beginning, we can shift
          prevVal = prev->first;
          prevCnt = (curVal - prevVal == 1) ? prev->second : 0;
        }

        int nextCnt = 0;
        int nextVal = 0;
        if (next == mp.end())
          nextVal = curVal + 1;
        else {
          nextVal = next->first;
          nextCnt = (nextVal - curVal == 1) ? next->second : 0;
        }

        // # #
        // #x#
        if (prevCnt >= curCnt  && curCnt <= nextCnt)
          // increase the number of subsequences by one,
          // since we are splitting one sequence into two
          cnt++;
        //  x
        // ###
        else if (prevCnt < curCnt && curCnt > nextCnt)
          cnt--;
      }

      if (it->second == 1)
        mp.erase(it);
      else
        it->second--;

      v[id - 1] = val;
      mp[val]++;
      auto itAdd = mp.find(val);

      // After adding do some book keeping
      {
        auto prev = itAdd;
        auto next = itAdd;
        next++;

        int curVal = itAdd->first;
        int curCnt = itAdd->second;

        int prevCnt = 0;
        int prevVal = 0;
        if (itAdd == mp.begin())
          prevVal = curVal - 1;
        else {
          prev--; // if it's not beginning, we can shift
          prevVal = prev->first;
          prevCnt = (curVal - prevVal == 1) ? prev->second : 0;
        }

        int nextCnt = 0;
        int nextVal = 0;
        if (next == mp.end())
          nextVal = curVal + 1;
        else {
          nextVal = next->first;
          nextCnt = (nextVal - curVal == 1) ? next->second : 0;
        }

        // ? ?
        // #x#
        if (prevCnt >= curCnt && curCnt <= nextCnt)
          // decrease the number of subsequences by one,
          // since we are joining two sequences into one
          cnt--;
        //  x
        // ###
        else if (prevCnt < curCnt && curCnt > nextCnt)
          cnt++;
      }
    }

    sum += (i + 1) * cnt;
  }

  cout << sum % MOD_NUM << endl;

  return 0;
}
