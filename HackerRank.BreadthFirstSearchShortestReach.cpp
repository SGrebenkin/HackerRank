#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(vector<vector<int>> edgs, int s) {
    int n = edgs.size();

    vector<int> result(n, -1);
    vector<int> v[2];
    int idx = 1;
    v[idx % 2].push_back(s);
    while (!v[idx % 2].empty()) {
        auto& a = v[idx % 2];
        auto& b = v[(idx + 1) % 2];
        b.clear();

        for (auto p: a) {
            for (auto c: edgs[p]) {
                if (result[c] != -1)
                    continue;
                b.push_back(c);
                result[c] = idx * 6;
            }
        }
        
        idx++;
    }

    return result;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edgs(n + 1, vector<int>());
        while (m--) {
            int a, b;
            cin >> a >> b;

            edgs[a].push_back(b);
            edgs[b].push_back(a);
        }

        int s;
        cin >> s;
        vector<int> result = bfs(edgs, s);
        for (int i = 1; i < result.size(); ++i)
            if (i != s)
                cout << result[i] << " ";
        cout << endl;
    }

    return 0;
}
