#include <bits/stdc++.h>

using namespace std;

const int N = 52, inf = 1e8;

int dp[N][1 << 15];

vector<pair<int, int>> mask[4];
int to[4][1 << 15];

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
int bx[N][N];

int main() {
    memset(to, -1, sizeof to);
    for (int n = 1; n <= 3; n++) {
        for (int j = 0; j < 5; j++) {
            for (int i = 0; i < n; i++) {
                int cur = 1 << (j * n + i);
                for (int k = 0; k < 8; k++) {
                    int x = j + dx[k], y = i + dy[k];
                    if (x < 0 || x >= 5 || y < 0 || y >= n) continue;
                    cur |= 1 << (x * n + y);
                }
                mask[n].emplace_back(j+1, cur);
            }
        }
        for (int b = 0; b < (1 << (n * 5)); b++) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < n; j++) {
                    int cur = i * n + j;
                    if (b & (1 << cur))
                        bx[i][j] = 1;
                    else
                        bx[i][j] = 0;
                }
            }
            bool ok = 1;
            for (int i = 0; i < n; i++) {
                ok &= bx[0][i];
            }
            if (ok) {
                int cur = 0;
                for (int i = 1; i < 5; i++) {
                    for (int j = 0; j < n; j++) {
                        if (bx[i][j])
                            cur |= 1 << ((i-1) * n + j);
                    }
                }
                to[n][cur] = b;
            }
        }
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int nn = 1 << (n*5);
        for (int i = 1; i < nn; i++)
            dp[0][i] = inf;
        dp[0][0] = 0;
        for (int i = 0; i < nn; i++) {
            for (auto x : mask[n]) if (x.first <= m)
                dp[0][x.second | i] = min(dp[0][x.second|i], dp[0][i]+1);
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < nn; j++)
                if (to[n][j] != -1)
                    dp[i][j] = dp[i-1][to[n][j]];
                else
                    dp[i][j] = inf;
            for (int j = 0; j < nn; j++) {
                for (auto x : mask[n]) if (x.first + i <= m)
                    dp[i][x.second | j] = min(dp[i][x.second|j], dp[i][j]+1);
            }
        }
        int ans = inf;
        for (int i = 0; i < nn; i++)
            ans = min(ans, dp[m][i]);
        printf("%d\n", ans);
    }
    return 0;
}