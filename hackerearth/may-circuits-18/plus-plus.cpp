#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 101, inf = 1e9 + 7;
 
int v[N][N];
bool used[N][N];
int dx[] = {0, -1, 0, 1, 0}, dy[] = {0, 0, -1, 0, 1};
 
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", v[i]+j);
    int ans = -inf;
    for (int a = 1; a+1 < n; ++a) {
        for (int b = 1; b+1 < m; ++b) {
            for (int i = 0; i < 5; ++i) {
                used[a+dx[i]][b+dy[i]] = 1;
            }
            for (int x = 1; x+1 < n; ++x) {
                for (int y = 1; y+1 < m; ++y) {
                    bool ok = 1;
                    for (int i = 0; i < 5; ++i)
                        if (used[x+dx[i]][y+dy[i]]) {
                            ok = 0;
                            break;
                        }
                    if (!ok) continue;
                    int cur = 0;
                    for (int i = 0; i < 5; ++i) {
                        cur += v[a+dx[i]][b+dy[i]] * v[x+dx[i]][y+dy[i]];
                    }
                    ans = max(ans, cur);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}