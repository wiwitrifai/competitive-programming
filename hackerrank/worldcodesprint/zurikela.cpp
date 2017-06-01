#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

vector< int > adj[N];
int val[N];

pair<int, int > dfs(int v) {
    pair<int, int > ret = make_pair(val[v], 0);
    val[v] = -1;
    for(int i = 0; i<adj[v].size(); i++) {
        int u = adj[v][i];
        if(val[u] == -1)
            continue;
        pair<int, int > res = dfs(u);
        ret.first += res.second;
        ret.second += res.first;
    }
    ret.first = max(ret.first, ret.second);
    return ret;
}

int main() {
    int k = 0, q;
    scanf("%d", &q);
    while(q--) {
        char c;
        int a, b;
        scanf("%*c%c%d", &c, &a);
        if(c == 'A') {
            val[k++] = a;
        }
        else if(c == 'B') {
            scanf("%d", &b);
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        else {
            val[k++] = dfs(a-1).first;
        }
    }
    int ans = 0;
    for(int i = 0; i<k; i++) if(val[i] != -1) {
        ans += dfs(i).first;
    }
    cout << ans << endl;
    return 0;
}
