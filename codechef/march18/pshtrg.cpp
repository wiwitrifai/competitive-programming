#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, MAGIC = 1500, SZ = (N + MAGIC - 1) / MAGIC;

int a[N], b[N];
int t[N], x[N], y[N];
long long ans[N];
bool upd[N];
vector<int> que[SZ];

multiset<int> st;

long long calc(long long p, long long r, long long s) {
  if (p + r + s <= 2 * max(max(p, r), s)) return 0;
  return p + r + s;
}

long long add(int x) {
  auto it = st.upper_bound(x);
  auto cur = it;
  long long ret = 0;
  for (int i = 0; i < 3; ++i) {
    if (cur == st.end()) break;
    int bef = *cur;
    ++cur;
    if (cur == st.end()) break;
    ret = max(ret, calc(x, bef, *cur));
  }
  cur = it;
  for (int i = 0; i < 3; ++i) {
    if (cur == st.begin()) break;
    int bef = *cur;
    --cur;
    ret = max(ret, calc(x, bef, *cur));
  }
  st.insert(x);
  return ret;
}
void remove(int x) {
  auto it = st.find(x);
  if (it == st.end()) return;
  st.erase(it);
}


int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  for (int i = 0; i < q; ++i)
    scanf("%d %d %d", t+i, x+i, y+i), x[i]--;
  for (int i = 0; i < q; i += MAGIC) {
    int til = min(i+MAGIC, q);
    for (int j = 0; j * MAGIC < n; ++j)
      que[j].clear();
    vector<int> qupd, ux;
    for (int j = i; j < til; ++j)
      if (t[j] == 2)
        que[x[j]/MAGIC].push_back(j);
      else
        qupd.push_back(j), upd[x[j]] = 1, ux.push_back(x[j]);
    sort(ux.begin(), ux.end());
    ux.erase(unique(ux.begin(), ux.end()), ux.end());
    for (int j = 0; j * MAGIC < n; ++j) {
      if (que[j].empty()) continue;
      st.clear();
      sort(que[j].begin(), que[j].end(), [&](int l, int r) { return y[l] < y[r]; });
      long long best = 0;
      int r = j * MAGIC;
      for (int id : que[j]) {
        while (r < y[id]) {
          if (!upd[r])
            best = max(best, add(a[r]));
          ++r;
        }
        long long res = best;
        for (int k = min(j * MAGIC, y[id]) - 1; k >= x[id]; --k)
          if (!upd[k])
            res = max(res, add(a[k]));
        for (int u : ux)
          b[u] = a[u];
        for (int u : qupd)
          if (u < id)
            b[x[u]] = y[u];
        for (int u : ux)
          if (x[id] <= u && u < y[id])
            res = max(res, add(b[u]));
        ans[id] = res;
        for (int k = min(j * MAGIC, y[id]) - 1; k >= x[id]; --k)
          if (!upd[k])
            remove(a[k]);
        for (int u : ux)
          if (x[id] <= u && u < y[id])
            remove(b[u]);
      }
    }
    for (int u : qupd)
      upd[x[u]] = 0, a[x[u]] = y[u];
  }
  for (int i = 0; i < q; ++i)
    if (t[i] == 2)
      printf("%lld\n", ans[i]);
  return 0;
}