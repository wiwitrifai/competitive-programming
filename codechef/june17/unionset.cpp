#include <bits/stdc++.h>

using namespace std;

const int N = 2501;

bitset< N > bs[N];
vector< int > id[N];
int cnt[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i <= k; i++)
            id[i].clear();
        for (int i = 0; i < n; i++) {
            int len;
            bs[i].reset();
            scanf("%d", &len);
            while (len--) {
                int x;
                scanf("%d", &x);
                x--;
                id[x].push_back(i);
                bs[i][x] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            memset(cnt, 0, sizeof cnt);
            int tot = 0;
            for (int j = 0; j < k; j++) if (!bs[i][j]) {
                tot++;
                for (int x : id[j])
                    cnt[x]++;
            }
            for (int j = i+1; j < n; j++)
                ans += cnt[j] == tot;
        }
        printf("%d\n", ans);
    }
    return 0;
}