#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int bit[N];

void upd(int x, int v) {
  for (; x < N; x += x&-x)
    bit[x] += v;
}
int get(int x) {
  int ret = 0;
  for (; x; x -= x &-x)
    ret += bit[x];
  return ret;
}
pair<int, int> p[N];
int live[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> vx;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    vx.push_back(x);
    p[i] = make_pair(-y, x);
  }
  sort(p, p+n);
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  for (int i = 0; i < n; ++i) {
    p[i].second = lower_bound(vx.begin(), vx.end(), p[i].second) - vx.begin() + 1;
  }
  long long ans = 0;
  for (int i = 0; i < n;) {
    int y = p[i].first;
    vector<int> xx;
    while (i < n && p[i].first == y) {
      xx.push_back(p[i].second);
      ++i;
    }
    sort(xx.begin(), xx.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());
    for (int x : xx) {
      if (!live[x]) {
        upd(x, +1);
        live[x] = 1;
      }
    }
    xx.push_back((int)vx.size() + 2);
    for (int j = 0; j + 1 < (int)xx.size(); ++j) {
      long long left = get(xx[j]), right = get(xx[j+1]-1);
      right = right - left + 1;
      ans += left * right;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
