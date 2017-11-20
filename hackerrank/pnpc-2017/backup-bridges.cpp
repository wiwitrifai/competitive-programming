#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

int d[N][2];

vector<int> g[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        for (int i = 1; i <= n; i++)
            d[i][0] = d[i][1] = inf;
        int a, b;
        scanf("%d %d", &a, &b);
        d[a][0] = 0;
        queue<pair<int, int> > que;
        que.push(make_pair(a, 0));
        while (!que.empty()) {
            auto it = que.front();
            int v = it.first, c = it.second, now = d[v][c];
            c ^= 1;
            que.pop();;
            for (int u : g[v]) {
                if (d[u][c] > now + 1) {
                    d[u][c] = now + 1;
                    que.push(make_pair(u, c));
                }
            }
        }
        if (d[b][0] >= inf)
            puts("NO");
        else
            printf("%d\n", d[b][0]/2);
    }
    return 0;
}
