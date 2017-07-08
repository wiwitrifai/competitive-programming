#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int bit[N];
int get(int x) {
  int ret = 0;
  for (; x; x -= x&-x)
    ret += bit[x];
  return ret;
}
void upd(int x, int val) {
  for (; x < N; x += x&-x)
    bit[x] += val;
}

vector< pair<pair< int, int >, int> > add[N], sub[N];

int p[N], a[N], ans[N];

int main() {
  for (int i = 2; i < N; i++) if (p[i] == 0) {
    for (int j = i; j < N; j += i)
      if (p[j] == 0)
        p[j] = i;
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a+i);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int x, y, l, r;
    scanf("%d %d %d %d", &l, &r, &x, &y);
    l--; x--;
    add[r].push_back(make_pair(make_pair(x, y), i));
    sub[l].push_back(make_pair(make_pair(x, y), i));
    ans[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    int c = a[i];
    while (c > 1) {
      int pp = p[c], e = 0;
      while ((c % pp) == 0) c /= pp, e++;
      upd(pp, e);
    }
    for (auto it : add[i]) {
      ans[it.second] += get(it.first.second) - get(it.first.first);
    }
    for (auto it : sub[i]) {
      ans[it.second] -= get(it.first.second) - get(it.first.first);
    }
  }
  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);
  return 0;
}