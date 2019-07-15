#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int bit[N];

void upd(int x, int v) {
  for (++x; x < N; x += x&-x)
    bit[x] += v;
}
int get(int x) {
  int ret = 0;
  for (++x; x; x -= x&-x)
    ret += bit[x];
  return ret;
}


int main() {
  int n;
  vector<tuple<int, int, int>> hor, ver;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int xa, ya, xb, yb;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    if (xa > xb)
      swap(xa, xb);
    if (ya > yb)
      swap(ya, yb);
    xa += N/2;
    xb += N/2;
    ya += N/2;
    yb += N/2;
    if (xa == xb) {
      ver.emplace_back(xa, ya, yb);
    }
    else {
      hor.emplace_back(xa, xb, ya);
    }
  }
  sort(ver.begin(), ver.end());
  sort(hor.begin(), hor.end());
  long long ans = 0;
  for (int r = 0; r < (int)ver.size(); ++r) {
    memset(bit, 0, sizeof bit);
    int xa, ya, yb;
    tie(xa, ya, yb) = ver[r];
    for (int l = 0, j = 0; l < r; ++l) {
      while (j < (int)hor.size() && get<0>(hor[j]) <= get<0>(ver[l])) {
        int xp, xq, yp;
        tie(xp, xq, yp) = hor[j];
        ++j;
        if (xq < xa || yp < ya || yp > yb) continue;
        upd(yp, +1);
      }
      int yp, yq;
      tie(ignore, yp, yq) = ver[l];
      int cnt = get(yq) - get(yp-1);
      ans += 1LL * cnt * (cnt - 1) / 2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
