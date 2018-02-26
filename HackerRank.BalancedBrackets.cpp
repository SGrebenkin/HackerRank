// https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        stack<char> st;
        bool isOk = true;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '{')
                st.push('{');
            else if (s[j] == '(')
                st.push('(');
            else if (s[j] == '[')
                st.push('[');
            else {
                if (st.empty()) {
                    isOk = false;
                    break;
                }

                if (s[j] == '}') {
                    if (st.top() != '{') {
                        isOk = false;
                        break;
                    }
                    st.pop();
                }
                else if (s[j] == ')') {
                    if (st.top() != '(') {
                        isOk = false;
                        break;
                    }
                    st.pop();
                }
                else if (s[j] == ']') {
                    if (st.top() != '[') {
                        isOk = false;
                        break;
                    }
                    st.pop();
                }
            }
        }
        if (isOk && st.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
