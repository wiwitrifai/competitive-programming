#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int N = 3e5 + 5, LG = 21, INF = 1e7;

int p[N], a[N], lv[N];
vector<int> vc[N], g[N];
bitset<1024> ada[N][6];
int anc[N];
int par[LG][N];

void dfs(int v, int d = 0) {
    lv[v] = d;
    for (int i = 0; i+1 < LG; ++i) {
        par[i+1][v] = par[i][par[i][v]];
    }
    for (int u : g[v]) {
        par[0][u] = v;
        dfs(u, d+1);
    }
}

int lca(int u, int v) {
    if (lv[v] < lv[u]) swap(u, v);
    int d = lv[v] - lv[u];
    for (int i = 0; i < LG; ++i)
        if (d & (1 << i))
            v = par[i][v];
    if (u == v) return v;
    for (int i = LG-1; i >= 0; --i)
        if (par[i][u] != par[i][v])
            u = par[i][u], v = par[i][v];
    return par[0][v];
}

int best[N], bef[N];
vector<pair<int, int> > que[N];
int m;

void dfs2(int v) {
    bef[v] = best[a[v]];
    best[a[v]] = lv[v];
    for (auto it : que[v]) {
        int i = it.first, j = it.second;
        int batas = lv[anc[i]];
        for (int k = 0; k < m; ++k) {
            if (best[k] >= batas)
                ada[i][j][k] = 1;
        }
    }
    for (int u : g[v]) {
        dfs2(u);
    }
    best[a[v]] = bef[v];
}

int cnt[33], all[33];

// Complete the maximumDishes function below.
void maximumDishes(int n, int m, int q) {
    // Take the rest of the input from standard input and print the answers to the queries in the standard output
    ::m = m;
    for (int i = 1; i < n; ++i) {
        scanf("%d", p+i), --p[i];
        g[p[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i), --a[i];
    dfs(0);
    for (int i = 0; i < q; ++i) {
        int c;
        scanf("%d", &c);
        vc[i].clear();
        while (c--) {
            int x;
            scanf("%d", &x);
            --x;
            vc[i].push_back(x);
        }
        anc[i] = vc[i][0];
        for (int j = 1; j < vc[i].size(); ++j)
            anc[i] = lca(anc[i], vc[i][j]);
        for (int j = 0; j < vc[i].size(); ++j)
            que[vc[i][j]].emplace_back(i, j);
    }
    memset(best, -1, sizeof best);
    dfs2(0);
    for (int i = 0; i < q; ++i) {
        int c = vc[i].size();
        for (int j = 0; j < (1 << c); ++j)
            cnt[j] = all[j] = 0;
        for (int j = 0; j < m; ++j) {
            int mask = 0;
            for (int k = 0; k < c; ++k)
                if (ada[i][k][j])
                    mask ^= 1 << k;
            ++cnt[mask];
        }
        for (int j = 0; j < (1 << c); ++j)
            for (int k = 0; k < (1 << c); ++k)
                if (j & k)
                    all[k] += cnt[j];
        int ans = INF;
        for (int j = 1; j < (1 << c); ++j)
            ans = min(ans, all[j]/__builtin_popcount(j));
        printf("%d\n", ans * c);
    }
}

int main()
{
    string nmq_temp;
    getline(cin, nmq_temp);

    vector<string> nmq = split_string(nmq_temp);

    int n = stoi(nmq[0]);

    int m = stoi(nmq[1]);

    int q = stoi(nmq[2]);

    maximumDishes(n, m, q);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
