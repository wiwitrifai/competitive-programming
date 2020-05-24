#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, bit[N];

int get(int x) {
  int ret = 0;
  for (++x; x; x -= x &-x)
    ret += bit[x];
  return ret;
}

void update(int x, int v){
  for (++x; x <= n+1; x += x&-x)
    bit[x] += v;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; ++i) {
      a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    long long tot = 1LL * n * (n + 1) / 2, pos = (tot + 1) / 2;
    long long low = 0, hig = tot;
    while (low < hig) {
      long long mid = (low + hig) >> 1;
      long long cur = 0, ccnt = 0;
      fill(bit, bit+n+2, 0);
      for (int l = 0, r = 0; r < n; ++r) {
        cur += (r-l) - get(a[r]);
        update(a[r], +1);
        while (l < r && cur > mid) {
          cur -= get(a[l]-1);
          update(a[l], -1);
          ++l;
        }
        ccnt += r - l + 1;
      }
      if (ccnt < pos)
        low = mid + 1;
      else
        hig = mid;
    }
    printf("%lld\n", low);
  }
  return 0;
}
