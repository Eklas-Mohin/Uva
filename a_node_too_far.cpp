/**
 *    author: mohin    
**/

#include <bits/stdc++.h>

using namespace std;

int caseno = 0;

void print(int x, int y, int r) {
    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caseno, r, x, y);
}

void solve(int nc) {
    int s{}, d{}, x{}, y{}, nodes{};
    bool present[100000];
    memset(present, false, sizeof(present));
    vector<int> adj_matrix[100000];
    for (int i = 0; i < nc; ++i) {
        cin >> s >> d;
        if (!present[s]) {
            nodes += 1;
            present[s] = true;
        }
        if (!present[d]) {
            nodes += 1;
            present[d] = true;
        }
        adj_matrix[s].push_back(d);
        adj_matrix[d].push_back(s);
    }
    while (cin >> x >> y) {
        if (x == 0 and y == 0) {
            break;
        }
        bool visited[100000];
        memset(visited, false, sizeof(visited));
        int distance[100000] = {};
        int reachable{1};
        queue<int> q;
        q.push(x);
        visited[x] = true;
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            for (int i = 0; i < adj_matrix[k].size(); ++i) {
                if (!visited[adj_matrix[k][i]]) {
                    visited[adj_matrix[k][i]] = true;
                    distance[adj_matrix[k][i]] = distance[k] + 1;
                    if (distance[adj_matrix[k][i]] <= y) {
                        reachable += 1;
                    }
                    q.push(adj_matrix[k][i]);
                }
            }
        }
        caseno += 1;
        print(x, y, nodes - reachable);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nc{};
    while (cin >> nc) {
        if (nc) {
            solve(nc);
        } else {
            break;
        }
    }
    return 0;
}
