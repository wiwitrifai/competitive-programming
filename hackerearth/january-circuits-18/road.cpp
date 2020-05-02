#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5, K = 55;
 
int dp[N][K], a[N];
map<int, int> mp;
 
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 1;
            for (int z = -j; z <= +j; ++z) {
                auto it = mp.find(a[i]+z);
                if (it == mp.end()) continue;
                dp[i][j] = max(dp[i][j], dp[it->second][j-abs(z)]+1);
            }
        }
        mp[a[i]] = i;
    }
    printf("%d\n", dp[0][k]);
    return 0;
}