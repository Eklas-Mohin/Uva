/**
 *    author: mohin    
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n{}, l{}, s{}, d{};
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin >> l;
        vector<int> adj_matrix[200];
        for (int i = 0; i < l; ++i) {
            cin >> s >> d;
            adj_matrix[s].push_back(d);
            adj_matrix[d].push_back(s);
        }
        bool flag{true};
        int color[200] = {};
        color[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty() and flag) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < adj_matrix[x].size(); ++i) {
                int k = adj_matrix[x][i];
                if (color[k] == 0) {
                    q.push(k);
                    if (color[x] == 1) {
                        color[k] = 2;
                    } else {
                        color[k] = 1;
                    }
                } else if (color[x] == color[k]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
    return 0;
}
