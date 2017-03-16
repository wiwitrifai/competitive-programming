#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair<int, int> p[N];
int bit[N];
vector<pair<int, int>> all;
int a[N];

void update(int i, int val) {
  for (; i < N; i |= i + 1) {
    bit[i] = max(bit[i], val);
  }
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret = max(ret, bit[i]);
  }
  return ret;
}

int id(pair<int, int> v) {
  return lower_bound(all.begin(), all.end(), v) - all.begin();
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    p[i] = {l, r};
    all.push_back(p[i]);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  for (int i = 0; i < n; i++) {
    a[i] = id(p[i]);
  }
  for (int i = 0; i < n; i++) {
    int now = find(a[i] - 1) + p[i].second - p[i].first + 1;
    update(a[i], now);
  }
  cout << find(N - 1) << endl;
  return 0;
}