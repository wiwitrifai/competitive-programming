#include <bits/stdc++.h>
using namespace std;

const long long p = 29, p2 = 37;
const long long mod = 1e9 + 7, mod2 = 1e9 + 9;
const long long inf = 1e18;

const int N = 4e4 + 5;

long long dp[N];
char s[N];

int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        long long a, b;
        int n;
        scanf("%d%lld%lld", &n, &a, &b);
        scanf("%s", s);
        set< long long > st[n];
        for(int i = 0; i<n; i++)
            dp[i] = inf;
        dp[0] = a;
        for(int i = 0; i<n; i++) {
            long long now, pp;
            now = 0;
            pp = 1;
            if(i > 0)
                dp[i] = min(dp[i], dp[i-1] + a);
            for(int j = i; j<n; j++) {
                now = (now + pp*(s[j]-'a')) % mod;
                if(now < 0) now += mod;
                if(st[j-i].count(now))
                    dp[j] = min(dp[j], (i>0) ? dp[i-1] + b : 0LL);
                else
                    break;
                pp = (pp*p) % mod;
            }
            now = 0;
            for(int j = i; j>=0; j--) {
                now = (now*p + (s[j]-'a')) % mod;
                if(now < 0) now += mod;
                st[i-j].insert(now);
            }
        }
        cout << dp[n-1] << endl;
    }
    return 0;
}
