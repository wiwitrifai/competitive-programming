#include <bits/stdc++.h>

using namespace std;

const int A = 5032107 + 5, N = 194598 + 5, Q = 1049658 + 5, inf = 1e9;

int a[N];
vector<int> last[A];
int ganjil[A], lp[A];

int l[Q], r[Q], ans[Q];

int pr[10];

int idx;

void upd(int id, int now = 1, int cost = 0) {
  if (id < 0) {
    if (last[now].size() < cost + 1)
      last[now].resize(cost+1, -1);
    last[now][cost] = idx;
    return;
  }
  upd(id-1, now * pr[id], cost);
  upd(id-1, now, cost + 1);
}

int best[20];

void get(int id, int now = 1, int cost = 0) {
  if (id < 0) {
    for (int j = 0; j < last[now].size(); ++j)
      best[cost + j] = max(best[cost+j], last[now][j]);
    return;
  }
  get(id-1, now * pr[id], cost);
  get(id-1, now, cost + 1);
}
vector<int> que[N];

int bit[N];

int get_bit(int x) {
  int ret = inf;
  for (++x; x < N; x += x&-x)
    ret = min(ret, bit[x]);
  return ret;
}

void upd_bit(int x, int v) {
  for (++x; x; x -= x&-x)
    bit[x] = min(bit[x], v);
}

int main() {
  lp[1] = 1;
  for (int i = 2; i < A; ++i) {
    if (lp[i]) continue;
    for (int j = i; j < A; j += i)
      if (lp[j] == 0)
        lp[j] = i;
  }
  ganjil[1] = 1;
  for (int i = 2; i < A; ++i) {
    int now = i;
    int p = lp[i], cnt = 0;
    while ((now % p) == 0) {
      now /= p;
      cnt ^= 1;
    }
    if (cnt)
      ganjil[i] = ganjil[now] * p;
    else
      ganjil[i] = ganjil[now];
  }
  int all = 0;
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    a[i] = ganjil[a[i]];
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", l+i, r+i);
    --l[i], --r[i];
    que[r[i]].push_back(i);
  }
  fill(bit, bit+N, inf);
  for (int i = 0; i < n; ++i) {
    int x = 0;
    int now = a[i];
    while (now > 1) {
      pr[x++] = lp[now];
      now /= lp[now];
    }
    memset(best, -1, sizeof best);
    idx = i;
    get(x-1);
    for (int j = 0; j < 20; ++j) {
      if (best[j] == -1) continue;
      upd_bit(best[j], j);
    }
    upd(x-1);
    for (int it : que[i]) {
      ans[it] = get_bit(l[it]);
    }
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}