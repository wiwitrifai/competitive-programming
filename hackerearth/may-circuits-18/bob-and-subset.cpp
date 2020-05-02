#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1 << 11;
 
int dp[N];
 
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < N; ++i)
        dp[i] = k+1;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        dp[x] = 1;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j)
            dp[i|j] = min(dp[i|j], dp[i]+dp[j]);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
        ans += dp[i] <= k;
    printf("%d\n", ans);
    return 0;
}