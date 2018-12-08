#include <bits/stdc++.h>
#include <set>
#include <unordered_map>

using namespace std;

vector<string> split_string(string);


// Complete the beautifulPairs function below.
int beautifulPairs(vector<int> A, vector<int> B) {
    unordered_map<int, int> sA;
    for (auto x: A)
        sA[x]++;
    
    unordered_map<int, int> sB;
    for (auto x: B)
        sB[x]++;
    
    int sum = 0;
    for (auto x: sB)
        sum += min(sA[x.first], x.second);

    if (A.size() > sum)
        return sum + 1;

    // !!! If all the elements are equal you MUST
    // !!! change one element in B and thus you
    // !!! make the number of pairs less than optimal.
    return B.size() - 1;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> A;
    vector<int> B;
    
    int t = n;
    while (t--) {
        A.push_back(0);
        cin >> A.back();
    }
    
    t = n;
    while (t--) {
        B.push_back(0);
        cin >> B.back();
    }
    
    cout << beautifulPairs(A, B) << endl;
    
    return 0;
}

