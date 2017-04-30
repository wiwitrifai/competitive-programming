#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

int p[5050], u[N], v[N], w[N], id[N], n, m, k, no[N];
long long mst, mst_now;
bool ok[N], sh[N], ans[N];
set < int > st[5050];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool merge(int x, int y) {
  if ((x = find(x)) == (y = find(y)))
    return false;
  if (-p[x] > -p[y])
    swap(x, y);
  p[y] += p[x];
  p[x] = y;
  return true;
}
int get(int v, int par, int tar, int now = inf) {
  if (v == tar) return now;
  for (int u : st[v]) if (u != par) {
    int res = get(::u[id[u]]^::v[id[u]]^v, u, tar, min(u, now));
    if (res != -1) return res;
  }
  return inf;
}

int main() {
  time_t startt = clock();
  scanf("%d %d %d", &n, &m, &k);
  memset(p, -1, sizeof p);
  for (int i = 0; i < m; i++)
    scanf("%d %d %d", u+i, v+i, w+i), u[i]--, v[i]--, id[i] = i;
  sort(id, id+m, [](int x, int y) { return w[x] > w[y];});
  for (int i = 0; i < m; i++)
    sh[id[i]] = merge(u[id[i]], v[id[i]]);
  for (int i = 0; i < m; i++) ans[i] = 1;
  srand(time(0));
  mst = 0;
  int acak = 0;
  while (1) {
    fill(ok, ok+m, 0);
    if (acak) {
      int mod = (rand() % max(m-k, 1)) + 1;
      int live = rand() % mod;
      for (int i = 0; i < live; i++) {
        ok[rand() % m] = 1;
      }
    }
    else
      acak = 1;
    int kill = 0;
    for (int i = m-1; i >= 0; i--) {
      if (!sh[id[i]] && !ok[id[i]] && kill < k) {
        ok[id[i]] = 0;
        kill++;
      }
      else
        ok[id[i]] = 1;
    }
    fill(p, p+n, -1);
    for (int i = 0; i < n; i++) st[i].clear();
    vector< int > used;
    mst_now = 0;
    for (int i = m-1; i >= 0; i--)
      if (ok[id[i]] && merge(u[id[i]], v[id[i]])) {
        mst_now += w[id[i]];
        no[id[i]] = used.size(), used.push_back(id[i]);
        st[u[id[i]]].insert(i);
        st[v[id[i]]].insert(i);
      }
      else
        no[id[i]] = -1;
    if (mst_now > mst) {
        mst = mst_now;
        for (int i = 0; i < m; i++)
          ans[i] = ok[i];
    }
    for (int i = m-1; i >= 0; i--) {
      if (sh[id[i]]) continue;
      if (ok[id[i]]) {
        if (kill >= k) continue;
        if (no[id[i]] < 0) continue;
        int z = no[id[i]];
        no[id[i]] = -1;
        st[u[id[i]]].erase(i);
        st[v[id[i]]].erase(i);
        fill(p, p+n, -1);
        for (int j = 0; j < n-1; j++)
          if (j != z)
            merge(u[used[j]], v[used[j]]);
        for (int j = i-1; j >= 0; j--) if (ok[id[j]] && merge(u[id[j]], v[id[j]])) {
          st[u[id[j]]].insert(j);
          st[v[id[j]]].insert(j);
          no[id[j]] = z;
          used[z] = id[j];
          break;
        }
        ok[id[i]] = 0;
        kill++;
      }
      else {
        int res = get(u[id[i]], -1, v[id[i]], -1);
        if (res < i) {
          kill--;
          ok[id[i]] = 1;
        }
      }
    }
    fill(p, p+n, -1);
    mst_now = 0;
    for (int i = m-1; i >= 0; i--)
      if (ok[id[i]] && merge(u[id[i]], v[id[i]]))
        mst_now += w[id[i]];
    if (mst_now > mst) {
      mst = mst_now;
      for (int i = 0; i < m; i++) ans[i] = ok[i];
    }
    if ((double)(clock()-startt) * 1000 / CLOCKS_PER_SEC > 4900) break; 
  }
  int cnt = 0;
  for (int i = 0; i < m; i++)
    cnt += ans[i];
  printf("%d\n", cnt);
  for (int i = 0; i < m; i++)
    if (ans[i])
      printf("%d ", i+1);
  printf("\n");
  return 0;
}