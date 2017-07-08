#include <bits/stdc++.h>

using namespace std;

const int N =1e5 + 5;

int a[N], n;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        long long sum = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", a+i), sum += a[i];
        sort(a, a+n);
        reverse(a, a+n);
        long long ans = sum, cur = 0;
        for (int i = 0; i < n; i++) {
            sum -= a[i];
            cur += a[i];
            long long now = cur * (i+1) + sum;
            if (ans < now)
                ans = now;
        }
        cout << ans << endl;
    }
    return 0;
}