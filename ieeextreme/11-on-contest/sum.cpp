#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], id[N], n, mid, b[N];

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
    bool satu = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
      cnt += a[i] == 1;
    bool le = cnt != 1;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0)
        b[l++] = 0;
      else if (a[i] == 1) {
        if (cnt > 1 && satu)
          b[r--] = a[i], satu = 0;
        else
          b[l++] = a[i];
      }
      else {
        if (le)
          b[l++] = a[i];
        else
          b[r--] = a[i];
        le ^= 1;
      }
    }
    for (int i = 0; i < n; i++)
      a[i] = b[i];
    for (int i = 0; i + 1 < n; i++) {
      ans += a[i] * 1LL * a[i+1];
    }
    printf("%lld\n", ans);
    for (int i = 0; i < n; i++)
      printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}