#include <bits/stdc++.h>

using namespace std;

#define INF 10000000
#define MAXD 20

int n, m;
int grid[MAXD+5][MAXD+5], vis[MAXD+5][MAXD+5], bb[MAXD+5][MAXD+5];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
vector <pair<int, int > > dd;
vector< bool > bd;
       
pair<int, int> DFS(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m) return make_pair(0, 0);
    if (vis[r][c] || grid[r][c] == 'X') return make_pair(0, 0);
    vis[r][c] = 1;
    int p = grid[r][c] == '.', d = grid[r][c] == 'D';
    if (d) {
        dd.push_back({r, c});
    }
    for (int i = 0; i < 4; ++i) {
        pair<int,int> ret = DFS(r+dr[i], c+dc[i]);
        p += ret.first; d += ret.second;
    }
    return make_pair(p, d);
}
int dfs2(int r, int c, int v) {
    if (r < 0 || c < 0 || r >= n || c >= m) return 0;
    if (vis[r][c] == v || grid[r][c] != '.') return 0;
    vis[r][c] = v;
    int ret = grid[r][c] == '.';
    for (int i = 0; i < 4; i++)
        ret += dfs2(r+dr[i], c + dc[i], v);
    return ret;
}
void upd(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m) return;
    if (grid[r][c] != '.') return;
    grid[r][c] == 'X';
    for (int i = 0; i < 4; i++)
        upd(r+dr[i], c + dc[i]);
}

int main()
{
    int ntc;
    scanf("%d", &ntc);
    while (ntc--) {
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof(vis));
        memset(bb, 0, sizeof bb);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                grid[i][j] = s[j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] != 'X') {
                    dd.clear();
                    pair<int, int> ret = DFS(i, j);
                    if (ret.second == 0) goto end;
                    int cnt = 2;
                    int now = (ret.first+ret.second-1)/ret.second;
                    bool ok = true;
                    bd.assign(dd.size(), true);
                    while (ok) {
                        ok = false;
                        memset(bb, 0, sizeof bb);
                        for (int k = 0; k < dd.size(); k++) {
                            int r = dd[k].first , c = dd[k].second;
                            for (int z = 0; z < 4; z++) {
                                int x = r + dr[z], y = c + dc[z];
                                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' || grid[x][y] == 'B') {
                                    grid[x][y] = 'B';
                                    bb[x][y]++;
                                }
                            }
                        }
                        for (int k = 0; k < dd.size(); k++) {
                            if (!bd[k])
                                continue;
                            int r = dd[k].first , c = dd[k].second;
                            int sum = 0;
                            for (int z = 0; z < 4; z++) {
                                int x = r + dr[z], y = c + dc[z];
                                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 'B' && bb[x][y] == 1) {
                                    grid[x][y] = '.';
                                    sum += dfs2(x, y, cnt);
                                }
                            }
                            for (int z = 0; z < 4; z++) {
                                int x = r + dr[z], y = c + dc[z];
                                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' || grid[x][y] == 'B') {
                                    grid[x][y] = 'B';
                                    bb[x][y]--;
                                }
                            }
                            if (ret.second == 1)
                                break;
                            if (now > sum) {
                                cerr << now << " " << sum << endl;
                                ok = true;
                                ret.first -= sum;
                                ret.second--;
                                bd[k] = false;
                                now = max(sum , (ret.first + ret.second-1)/ret.second);
                                for (int z = 0; z < 4; z++) {
                                    int x = r + dr[z], y = c + dc[z];
                                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 'B' && bb[x][y] == 1) {
                                        grid[x][y] = '.';
                                        upd(x, y);
                                    }
                                }
                            }
                            if (ret.second == 1)
                                break;
                            cnt++;
                        }
                    }
                    ans = max(ans, now);
                }
            }
        }

        printf("%d\n", ans);
        continue;

end:
        puts("impossible");
    }
    return 0;
}