#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e17 + 5;

int  v[N], k[N], w[N], comp[N], up[N], pos[N], sz[N], szc[N], ncomp;

bool used[N];

vector< int > adj[N];

long long d[N];

struct seg_tree {
  int n;
  vector < set < pair<int, int> > > vs;
  seg_tree(int n) : n(n) {
    vs.assign(n << 2, set<pair<int, int> > ());
  }
  void insert(int x, int y, int val) {
    int id = 1, l = 0, r = this->n;
    pair<int, int> pp = make_pair(y, val);
    while (l + 1 < r) {
      vs[id].insert(pp);
      int mid = (l + r) >> 1;
      if (x < mid) {
        id <<= 1;
        r = mid;
      }
      else {
        id = (id << 1) | 1;
        l = mid;
      }
    }
    vs[id].insert(pp);
  }
  // void erase(pair<int, int>, int > pp) {
  //   int id = 1, l = 0, r = this->n;
  //   int x = pp.second;
  //   while (l + 1 < r) {
  //     vs[id].erase(pp);
  //     int mid = (l + r) >> 1;
  //     if (x < mid) {
  //       id <<= 1;
  //       r = mid;
  //     }
  //     else {
  //       id = (id << 1) | 1;
  //       l = mid;
  //     }
  //   }
  //   vs[id].erase(pp);
  // }
  vector< pair<int, int > > get(int x, int y) {
    vector< pair<int, int > > ret;
    int id = 1, l = 0, r = this->n;
    while (l + 1 < r) {
      int mid = (l + r) >> 1;
      if (mid - 1 <= x) {
        id <<= 1;
        auto low = vs[id].lower_bound(make_pair(y, -1));
        for (auto it = low; it != vs[id].end(); it++)
          ret.push_back(*it);
        vs[id].erase(low, vs[id].end());
        l = mid;
        id |= 1;
      }
      else {
        r = mid;
        id <<= 1;
      }
      if (l > x)
        return ret;
    }
    if (r -1 <= x) {
      auto low = vs[id].lower_bound(make_pair(y, -1));
      for (auto it = low; it != vs[id].end(); it++)
        ret.push_back(*it);
      vs[id].erase(low, vs[id].end());
    }
    return ret;
  }
};

void getsz(int u, int p = -1) {
  sz[u] = 1;
  for (int a : adj[u]) if (a != p) {
    getsz(a, u);
    sz[u] += sz[a];
  }
}

void hld(int u, int p = -1) {
  comp[u] = ncomp;
  pos[u] = szc[ncomp]++;
  int ch = -1, szch = 0;
  for (int a : adj[u]) if (a != p) {
    if (ch == -1 || szch < sz[a]) {
      ch = a;
      szch = sz[a];
    }
  }
  if (ch != -1) {
    hld(ch, u);
  }
  for (int a : adj[u]) if (a != ch && a != p) {
    ncomp++;
    szc[ncomp] = 0;
    up[ncomp] = u;
    hld(a, u);
  }
}

seg_tree * segl[N], * segr[N];

int main() {
  int n, m, q;
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  szc[0] = 0;
  up[0] = -1;
  getsz(0);
  ncomp = 0;
  hld(0);
  for (int i = 0; i <= ncomp; i++) {
    segl[i] = new seg_tree(szc[i]);
    segr[i] = new seg_tree(szc[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", v+i, k+i, w+i);
    v[i]--;
    int now = v[i], co = comp[now], range = k[i];
    while (now >= 0 && range >= 0) {
      co = comp[now];
      segl[co]->insert(pos[now], pos[now] + range, i);
      int nlp = szc[co] - pos[now] - 1;
      segr[co]->insert(nlp, nlp + range, i);
      range -= pos[now] + 1;
      now = up[co];
    }
  }
  for (int i = 0; i < n; i++)
    d[i] = inf;
  set< pair<long long, int > > st;
  d[0] = 0;
  st.insert(make_pair(0, 0));
  while (!st.empty()) {
    auto it = st.begin();
    int now = it->second;
    int cur = now;
    int range = 0;
    st.erase(it);
    while (now >= 0) {
      int co = comp[now];
      auto vv = segl[co]->get(pos[now], pos[now] + range);
      for (auto vit : vv) {
        int i = vit.second;
        if (d[v[i]] > d[cur] + w[i]) {
          st.erase(make_pair(d[v[i]], v[i]));
          d[v[i]] = d[cur] + w[i];
          st.insert(make_pair(d[v[i]], v[i]));
        }
      }
      int nlp = szc[co] - pos[now] - 1;
      vv = segr[co]->get(nlp, nlp + range);
      for (auto vit : vv) {
        int i = vit.second;
        if (d[v[i]] > d[cur] + w[i]) {
          st.erase(make_pair(d[v[i]], v[i]));
          d[v[i]] = d[cur] + w[i];
          st.insert(make_pair(d[v[i]], v[i]));
        }
      }
      range += pos[now] + 1;
      now = up[co];
    }
  }
  scanf("%d", &q);
  while (q--) {
    int h;
    scanf("%d", &h);
    h--;
    assert(d[h] < inf);
    printf("%lld\n", d[h]);
  }
  return 0;
}