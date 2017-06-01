#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, k;
pair< int, int > p[N];
long long dp[N];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i<n; i++) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p+n, [](pair<int, int> a, pair<int, int> b) { 
        int vala = (100-a.second) * a.first, valb = (100-b.second) * b.first;
        return vala == valb ? a.second * a.first < b.first * b.second : vala > valb; 
    });
    set< pair<int, int> > s;
    long long sum = 0;
    dp[n] = 0;
    m -= k;
    for(int i = n-1; i>=0; i--) {
        int now = p[i].first * p[i].second;
        s.insert(make_pair(now, i));
        sum += now;
        if(s.size() > m) {
            auto it = s.begin();
            sum -= it->first;
            s.erase(it);
        }
        dp[i] = sum;
    }
    long long ans = dp[0];
    sum = 0;
    s.clear();
    for(int i = 0; i<n; i++) {
        int now = p[i].first * 100;
        s.insert(make_pair(now, i));
        sum += now;
        if(s.size() > k) {
            auto it = s.begin();
            sum -= it->first;
            s.erase(it);
        }
        ans = max(ans, sum+dp[i+1]);
    }
    printf("%lld\n", ans);
    return 0;
}
