#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    sort(a, a+n);
    long long ans = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += a[i] == a[2];
    if (a[0] == a[1] && a[1] == a[2]) {
        ans = 1LL * cnt * (cnt - 1) * (cnt - 2) / 6;
    }
    else if (a[0] == a[1] && a[1] != a[2]) {
        ans = cnt;
    }
    else if (a[0] != a[1] && a[1] == a[2]) {
        ans = 1LL * cnt * (cnt - 1) / 2;
    }
    else
        ans = cnt;
    cout << ans << endl;
    return 0;
}