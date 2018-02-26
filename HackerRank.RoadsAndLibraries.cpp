/*
https://www.hackerrank.com/challenges/torque-and-development/problem

The Ruler of HackerLand believes that every citizen of the country should have access to a library. Unfortunately, HackerLand was hit by a tornado that destroyed all of its libraries and obstructed its roads! As you are the greatest programmer of HackerLand, the ruler wants your help to repair the roads and build some new libraries efficiently.

HackerLand has  cities numbered from  to . The cities are connected by  bidirectional roads. A citizen has access to a library if:

Their city contains a library.
They can travel by road from their city to a city containing a library.
The following figure is a sample map of HackerLand where the dotted lines denote obstructed roads:

The cost of repairing any road is  dollars, and the cost to build a library in any city is  dollars.

You are given  queries, where each query consists of a map of HackerLand and value of  and .

For each query, find the minimum cost of making libraries accessible to all the citizens and print it on a new line.

Input Format

The first line contains a single integer, , denoting the number of queries. The subsequent lines describe each query in the following format:

The first line contains four space-separated integers describing the respective values of  (the number of cities),  (the number of roads),  (the cost to build a library), and  (the cost to repair a road).
Each line  of the  subsequent lines contains two space-separated integers,  and , describing a bidirectional road connecting cities  and .
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <set>
#include <map>
#include <fstream>
using namespace std;

vector<long long> CC(const map<int, set<int>>& mtx, int n)
{
  unordered_set<int> passed;
  vector<long long> result;

  for (int i = 0; i < n; ++i)
  {
    // If we have already checked the cluster, then continue
    if (passed.find(i) != passed.end())
      continue;

    if (mtx.find(i) == mtx.end())
    {
      result.push_back(1);
      continue;
    }

    long long sum = 0;

    // start DFS for the given city i
    stack<int> st;
    st.push(i);
    while (!st.empty())
    {
      int k = st.top();
      if (passed.find(k) != passed.end())
      {
        st.pop();
        continue;
      }

      sum++;
      passed.insert(k);
      st.pop();

      auto it = mtx.find(k);
      if (it != mtx.end())
        for (auto child: it->second)
          st.push(child);
    }

    result.push_back(sum);
  }

  return result;
}

int main() {
  int q;
  cin >> q;

  long long sum = 0;
  vector<long long> res;
  for (int a0 = 0; a0 < q; a0++) {
    int n; // number of cities
    int m; // number of roads
    int x; // cost of lib
    int y; // cost of road
    cin >> n;
    cin >> m;
    cin >> x;
    cin >> y;
    map<int, set<int>> con;
    for (int a1 = 0; a1 < m; a1++) {
      int city_1;
      int city_2;
      cin >> city_1;
      cin >> city_2;
      city_1--;
      city_2--;
      auto it = con.find(city_1);
      if (con.find(city_1) == con.end())
        con.insert({ city_1, set<int>({city_2}) });
      else
        con[city_1].insert(city_2);

      if (con.find(city_2) == con.end())
        con.insert({ city_2, set<int>({city_1}) });
      else
        con[city_2].insert(city_1);
    }

    vector<long long> ccs = CC(con, n);
    //cout << "DONE DFS" << endl;
    long long sum = 0;
    for (int i = 0; i < ccs.size(); ++i)
    {
      long long libCost = ccs[i] * x;
      long long roadCost = (ccs[i] - 1) * y + x;

      sum += min(libCost, roadCost);
    }
    res.push_back(sum);
  }

  for (int a0 = 0; a0 < q; a0++)
    cout << res[a0] << endl;

  return 0;
}
