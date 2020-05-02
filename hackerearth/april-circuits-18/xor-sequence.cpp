#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 3, S = 100, M = (N + S - 1) / S;
const int SNODE = 32 * 32 * N, SROLL = S * 32 * 2;

struct node {
  int l, r, id;
  node() : l(0), r(0), id(-1) {}
} t[SNODE];

int nodes = 1;
pair<int *, int> roll[SROLL];
int nroll = 0;

void upd(int * var, int val, bool persist) {
  if (!persist)
    roll[nroll++] = make_pair(var, *var);
  assert (nroll < SROLL);
  *var = val;
}

void add(int now, int v, int id, bool persist = true) {
  for (int i = 30; i >= 0; --i) {
    if (v & (1 << i)) {
      if (t[now].r == 0) {
        upd(&t[now].r, nodes, persist);
        upd(&nodes, nodes+1, persist);
      }
      now = t[now].r;
    }
    else {
      if (t[now].l == 0) {
        upd(&t[now].l, nodes, persist);
        upd(&nodes, nodes+1, persist);
      }
      now = t[now].l;
    }
    if (t[now].id < id)
      upd(&t[now].id, id, persist);
    assert(nodes < SNODE);
  }
}

int get(int now, int v, int id) {
  int ans = 0;
  for (int i = 30; i >= 0; --i) {
    if (v & (1 << i)) {
      if (t[t[now].l].id >= id)
        now = t[now].l, ans |= 1 << i;
      else
        now = t[now].r;
    }
    else {
      if (t[t[now].r].id >= id)
        now = t[now].r, ans |= 1 << i;
      else
        now = t[now].l;
    }
  }
  return ans;
}

void rollback() {
  for (int i = nroll-1; i >= 0; --i)
    *roll[i].first = roll[i].second;
  nroll = 0;
}

int root[S], a[N];
int pre[S][N];

int main() {
  int n, q, z;
  scanf("%d %d %d", &n, &q, &z);
  a[0] = 0;
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i), a[i] ^= a[i-1];
  int ns = 0;
  nodes = 1;
  for (;; ++ns) {
    int r = ns * M;
    if (r > n) break;
    root[ns] = nodes++;
    for (int i = r-1; i >= 0; --i) {
      add(root[ns], a[i], i, 1);
      pre[ns][i] = get(root[ns], a[i], 0);
    }
  }
  int ans = 0;
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    x = (x + ans * z) % n, y = (y + ans * z) % n;
    if (x > y) swap(x, y);
    ++y;
    int g = (y + 1) / M;
    ans = pre[g][x];
    for (int j = g * M; j <= y; ++j) {
      add(root[g], a[j], j, 0);
      ans = max(ans, get(root[g], a[j], x));
    }
    rollback();
    printf("%d\n", ans);
  }
  return 0;
}