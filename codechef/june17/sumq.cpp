#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;
long long a[N], b[N], c[N], sa[N], sc[N];
int ca[N], cc[N];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int p, q, r;
        scanf("%d %d %d", &p, &q, &r);
        for (int i = 0; i < p; i++)
            scanf("%lld", a+i);
        for (int i = 0; i < q; i++)
            scanf("%lld", b+i);
        for (int i = 0; i < r; i++)
            scanf("%lld", c+i);
        sort(b, b+q);
        fill(sa, sa+q, 0);
        fill(sc, sc+q, 0);
        fill(ca, ca+q, 0);
        fill(cc, cc+q, 0);
        for (int i = 0; i < p; i++) {
            int x = lower_bound(b, b+q, a[i]) - b;
            sa[x] += a[i];
            ca[x]++;
        }
        for (int i = 0; i < r; i++) {
            int x = lower_bound(b, b+q, c[i]) - b;
            sc[x] += c[i];
            cc[x]++;
        }
        long long ans = 0;
        for (int i = 0; i < q; i++) {
            sa[i+1] += sa[i];
            sc[i+1] += sc[i];
            ca[i+1] += ca[i];
            cc[i+1] += cc[i];
            sa[i] = (sa[i] + 1LL * b[i] * ca[i]) % mod;
            sc[i] = (sc[i] + 1LL * b[i] * cc[i]) % mod;
            ans = (ans + sa[i] * sc[i]) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}