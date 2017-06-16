#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int a[N], n, b[N], le[N], ri[N];

long long get() {
    long long ans = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int l = -1, r = m-1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (a[b[mid]] <= a[i])
                r = mid-1;
            else
                l = mid;
        }
        le[i] = l < 0 ? i : i-b[l]-1;
        while (m > 0 && a[b[m-1]] <= a[i]) m--;
        b[m++] = i;
    }
    m = 0;
    for (int i = n-1; i >= 0; i--) {
        int l = -1, r = m-1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (a[b[mid]] < a[i])
                r = mid-1;
            else
                l = mid;
        }
        ri[i] = l < 0 ? n-1-i : b[l]-i-1;
        while (m > 0 && a[b[m-1]] < a[i]) m--;
        b[m++] = i;
    }
    for (int i = 0; i < n; i++)
        ans += 1LL * (le[i]+1) * (ri[i]+1) * a[i];
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
    long long ans = get();
    for (int i = 0; i < n; i++) {
        a[i] = -a[i];
    }
    ans += get();
    cout << ans << endl;
    return 0;
}