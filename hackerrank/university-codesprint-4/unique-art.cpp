#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int bit[N], n;
int get(int x) {
  int ret = 0;
  for (; x; x -= x&-x)
    ret += bit[x];
  return ret;
}

void upd(int x, int v) {
  for (; x <= n; x += x&-x)
    bit[x] += v;
}

int q, l[N], r[N], a[N], ans[N];
vector<int> que[N];
int add[N], sub[N];

int main() {
  scanf("%d", &n);
  vector<int> va;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), va.push_back(a[i]);
  sort(va.begin(), va.end());
  va.erase(unique(va.begin(), va.end()), va.end());
  for (int i = 0; i < n; ++i)
    a[i] = lower_bound(va.begin(), va.end(), a[i]) - va.begin();
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", l+i, r+i);
    --l[i];
    que[l[i]].push_back(i);
  }
  for (int i = 0; i < va.size(); ++i)
    add[i] = sub[i] = n;
  for (int i = n-1; i >= 0; --i) {
    upd(sub[a[i]]+1, +1);
    upd(add[a[i]]+1, -2);
    upd(i+1, +1);
    sub[a[i]] = add[a[i]];
    add[a[i]] = i;
    for (int j : que[i])
      ans[j] = get(r[j]) - get(l[j]);
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}