#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], pos[N];
long long cnt[N];

int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    --a[i];
    pos[a[i]] = i;
  }
  for (int i = 0; i + 1 < n; ++i) {
    int l = pos[i], r = pos[i+1];
    if (l > r)
      swap(l, r);
    ++cnt[l];
    --cnt[r];
  }
  for (int i = 0; i < n; ++i) {
    cnt[i+1] += cnt[i];
  }
  sort(cnt, cnt+n-1);
  long long sum = 0;
  int ans = -1;
  for (int i = n-2; i >= 0; --i) {
    sum += cnt[i];
    if (sum >= k) {
      ans = n-1-i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}