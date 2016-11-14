#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LN = 19;
const int G = sqrt(N);

vector< tuple< int, int, int, int > > que;
vector< int > adj[N];
int col[N];
long long ans[N];

// LCA
int sparse[LN][N], lv[N], node[N], pos[N], cntr = 0, par[N];

void dfs(int v, int p = -1) {
  pos[v] = cntr;
  node[cntr++] = v;
  lv[v] = p >= 0 ? lv[p] + 1 : 1;
  par[v] = p;
  for (int u : adj[v]) if (u != p) {
    dfs(u, v);
    node[cntr++] = v;
  }
}
int lca(int a, int b) {
  int pa = pos[a], pb = pos[b];
  if (pa > pb)
    swap(pa, pb);
  int len = pb - pa + 1;
  int ln = 31 - __builtin_clz(len);
  a = sparse[ln][pa];
  b = sparse[ln][pb - (1<<ln)+1];
  return lv[a] < lv[b] ? a : b;
}

int posl[N], posr[N];
void dfs2(int v) {
  node[cntr] = v;
  posl[v] = cntr++;
  for (int u : adj[v]) if (u != par[v])
    dfs2(u);
  node[cntr] = v;
  posr[v] = cntr++;
}
struct sqrtc {
  int cnt1[N], cnt2[N];
  long long ans;
  int l, r;
  sqrtc() : l(-1), r(-1), ans(0) {
  }
  void inc1() {
    l++;
    int v = node[l];
    int cc = col[v];
    if (l == posl[v]) {
      ans += cnt2[cc];
      cnt1[cc]++;
    }
    else {
      ans -= cnt2[cc];
      cnt1[cc]--;
    }
  }
  void dec1() {
    int v = node[l];
    int cc = col[v];
    if (l == posr[v]) {
      ans += cnt2[cc];
      cnt1[cc]++;
    }
    else {
      ans -= cnt2[cc];
      cnt1[cc]--;
    }
    l--;
  }
  void inc2() {
    r++;
    int v = node[r];
    int cc = col[v];
    if (r == posl[v]) {
      ans += cnt1[cc];
      cnt2[cc]++;
    }
    else {
      ans -= cnt1[cc];
      cnt2[cc]--;
    }
  }
  void dec2() {
    int v = node[r];
    int cc = col[v];
    if (r == posr[v]) {
      ans += cnt1[cc];
      cnt2[cc]++;
    }
    else {
      ans -= cnt1[cc];
      cnt2[cc]--;
    }
    r--;
  }
};

sqrtc sq;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector< int > vc;
  for (int i = 0; i < n; i++) {
    scanf("%d", col+i);
    vc.push_back(col[i]);
  }
  sort(vc.begin(), vc.end());
  vc.erase(unique(vc.begin(), vc.end()), vc.end());
  for (int i = 0; i < n; i++) {
    col[i] = lower_bound(vc.begin(), vc.end(), col[i]) - vc.begin() + 1;
    // cerr << i << " col:" << col[i] << endl;
  }
  for (int i = 1; i < n; i++) {
    int u,v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cntr = 0;
  dfs(0);
  for (int i = 0; i < cntr; i++) {
    sparse[0][i] = node[i];
  }
  for (int ln = 0; ln + 1 < LN; ln++) {
    for (int i = 0; i + (1<<(ln+1)) <= cntr; i++) {
      int a = sparse[ln][i], b = sparse[ln][i+(1<<ln)];
      sparse[ln+1][i] = lv[a] < lv[b] ? a : b;
    }
  }
  for (int i = 0; i < q; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    a--; b--; c--; d--;
    int ab = lca(a, b), cd = lca(c, d);
    que.emplace_back(a, c, 1, i);
    que.emplace_back(a, d, 1, i);
    que.emplace_back(a, cd, -1, i);

    que.emplace_back(b, c, 1, i);
    que.emplace_back(b, d, 1, i);
    que.emplace_back(b, cd, -1, i);
    
    que.emplace_back(ab, c, -1, i);
    que.emplace_back(ab, d, -1, i);
    que.emplace_back(ab, cd, 1, i);

    if (par[ab] >= 0) {
      que.emplace_back(par[ab], c, -1, i);
      que.emplace_back(par[ab], d, -1, i);
      que.emplace_back(par[ab], cd, 1, i);
    }
    if (par[cd] >= 0) {
      que.emplace_back(a, par[cd], -1, i);
      que.emplace_back(b, par[cd], -1, i);
      que.emplace_back(ab, par[cd], 1, i);
    }
    if (par[ab] >= 0 && par[cd] >= 0) {
      que.emplace_back(par[ab], par[cd], 1, i);
    }
    ans[i] = 0;
    int ac = lca(a, c), ad = lca(a, d), bc = lca(b, c), bd = lca(b, d);
    int ma = max(lv[ab], lv[cd]);
    if (lv[ac] < ma && lv[ad] < ma && lv[bc] < ma && lv[bd] < ma) 
      continue;
    int point [] = {ac, ad, bc, bd};
    vector< int > intersect(point, point+4);
    sort(intersect.begin(), intersect.end(), [](int x, int y) {
      return lv[x] > lv[y];
    }); 
    ans[i] -= lv[intersect[0]]+lv[intersect[1]] - 2 * lv[lca(intersect[0], intersect[1])] + 1;
  }
  cntr = 0;
  dfs2(0);

  sort(que.begin(), que.end(), [](tuple<int,int,int,int> t1, tuple<int,int,int,int> t2) {
    int a1, b1, c1, d1, a2, b2, c2, d2;
    tie(a1, b1, c1, d1) = t1;
    tie(a2, b2, c2, d2) = t2;
    a1 = posl[a1] / G; a2 = posl[a2] / G;
    if (a1 != a2)
      return a1 < a2;
    b1 = posl[b1]; b2 = posl[b2];
    return b1 < b2;
  });

  for (int i = 0; i < que.size(); i++) {
    int a, b, c, d;
    tie(a, b, c, d) = que[i];
    a = posl[a]; 
    b = posl[b];
    while (sq.l < a) sq.inc1();
    while (sq.l > a) sq.dec1();
    while (sq.r < b) sq.inc2();
    while (sq.r > b) sq.dec2();
    ans[d] += sq.ans * c;
  }
  for (int i = 0; i < q; i++)
    printf("%lld\n", ans[i]);
  return 0;
}