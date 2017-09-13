#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int bit[N], n;

void upd(int x, int v) {
  for (; x < N; x += x&-x) {
    bit[x] += v;
    if (bit[x] >= mod)
      bit[x] -= mod;
  }
}

int get(int x) {
  int ret = 0;
  for (; x; x -= x&-x) {
    ret += bit[x];
    if (ret >= mod)
      ret -= mod;
  }
  return ret;
}

pair<int, int > p[N];

int main() {
  int n;
  vector<int> vx, vy;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].first, &p[i].second);
    vx.push_back(p[i].first);
    vy.push_back(p[i].second);
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  for (int i = 0; i < n; i++) {
    p[i].first = lower_bound(vx.begin(), vx.end(), p[i].first) - vx.begin() + 1;
    p[i].second = lower_bound(vy.begin(), vy.end(), p[i].second) - vy.begin() + 1;
  }
  sort(p, p+n);
  reverse(p, p+n);
  for (int i = 0; i < n; i++) {
    int cur = get(p[i].second) + 1;
    upd(p[i].second + 1, cur);
  }
  printf("%d\n", get(N-1));
  return 0;
}