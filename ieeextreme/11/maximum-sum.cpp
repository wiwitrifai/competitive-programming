#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], id[N], n, mid, cnt[N];

int main() {
  int t;
  scanf("%d",&t);
  while (t--){
    scanf("%d",&n);
    long long ans = 0;
    for (int i = 0;i < n; i++)
      scanf("%d", a+i);
    int l = 0, r = n-1;
    sort(a, a+n);
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++)
      cnt[a[i]]++;
    while (cnt[0]) a[l++] = 0, cnt[0]--;
    bool le = 1;
    for (int i = 1; i < N; i++) {
      if (cnt[i] > 1) {
        cnt[i]--;
        a[r--] = i;
        while (cnt[i] > 0) a[l++] = i, cnt[i]--;
        le = 1;
      }
      else if (cnt[i] == 1) {
        if (le)
          a[l++] = i;
        else
          a[r--] = i;
        le ^= 1;
      }
    }
    for (int i= 0; i + 1 < n; i++) {
      ans += 1LL * a[i] * a[i+1];
    }
    printf("%lld\n", ans);
    for (int i = 0; i < n; i++)
      printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}