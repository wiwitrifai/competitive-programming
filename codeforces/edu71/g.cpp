#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, LG = 21;

char h[N];
int par[LG][N], lv[N];
int len;

int sa[N], temp[N], temp2[N], pos[N], rnk[LG][N];

int que[N], sum[N];

// counting sort for suffix array
void counting_sort() {
  int ma = 0;
  for (int i = 0; i < len; ++i)
    ma = max(ma, pos[i]);
  fill(temp, temp+ma+1, 0);
  for (int i = 0; i < len; ++i)
    ++temp[pos[i]];
  for (int i = 0, now = 0; i <= ma; ++i) {
    int bef = now;
    now += temp[i];
    temp[i] = bef;
  }
  for (int i = 0; i < len; ++i) {
    int now = sa[i], v = pos[now];
    temp2[temp[v]++] = now;
  }
  for (int i = 0; i < len; ++i)
    sa[i] = temp2[i];
}

int sp[LG][N];

// get minimum lcp [l..r]
int get(int l, int r) {
  if (r < l) return 0;
  int len = r-l+1;
  int lg = 31 - __builtin_clz(len);
  return min(sp[lg][l], sp[lg][r-(1<<lg)+1]);
}

// calculate longest common prefix(LCP) from node u dan v
int lcp(int u, int v) {
  int ret = 0, mi = min(lv[u], lv[v]);
  for (int i = LG-1; i >= 0; --i) {
    if (rnk[i][u] == rnk[i][v]) {
      u = par[i][u];
      v = par[i][v];
      ret += 1 << i;
    }
  }
  if (u != v)
    assert(h[u] != h[v]);
  else
    assert(u == 0);
  return min(ret, mi);
}

vector<int> process[N];
vector<int> child[N];
int bit[N], lef[N], rig[N];
int get(int x) {
  int ret = 0;
  for (++x; x; x -= x&-x)
    ret += bit[x];
  return ret;
}

void update(int x, int v) {
  for (++x; x < N; x += x&-x)
    bit[x] += v;
}

int ans[N];

void dfs(int v) {
  update(pos[v], +1);
  for (int id : process[v]) {
    ans[id] = get(rig[id]) - get(lef[id]-1);
  }
  for (int u : child[v]) {
    dfs(u);
  }
  update(pos[v], -1);
}

int main() {
  int n;
  scanf("%d", &n);
  h[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%s", h+i);
      par[0][i] = 0;
    }
    else {
      scanf("%d %s", par[0]+i, h+i);
    }
  }

  int q;
  scanf("%d", &q);

  // add query string to tree
  len = n+1;
  que[0] = len-1;
  for (int i = 1; i <= q; ++i) {
    int v;
    scanf("%d", &v);
    process[v].push_back(i);
    scanf("%s", h+len);
    int clen = strlen(h+len);
    for (int j = 0, now = 0; j < clen; ++j) {
      par[0][len+j] = now;
      now = len+j;
    }
    len += clen;
    que[i] = len-1;
  }

  // build suffix array
  for (int i = 0; i < len; ++i) {
    lv[i] = i ? lv[par[0][i]] + 1 : 0;
    for (int j = 0; j+1 < LG; ++j)
      par[j+1][i] = par[j][par[j][i]];
    rnk[0][i] = h[i];
  }
  for (int i = 0; i < len; ++i)
    sa[i] = i;
  for (int i = 0; i < LG; ++i) {
    for (int j = 0; j < len; ++j)
      pos[j] = rnk[i][par[i][j]];
    counting_sort();
    for (int j = 0; j < len; ++j)
      pos[j] = rnk[i][j];
    counting_sort();
    if (i+1 < LG) {
      for (int j = 0, now = 0; j < len; ++j) {
        int cur = sa[j];
        if (j > 0) {
          int pre = sa[j-1];
          now += (rnk[i][cur] != rnk[i][pre]) || (rnk[i][par[i][cur]] != rnk[i][par[i][pre]]);
        }
        rnk[i+1][cur] = now;
      }
    }
  }
  for (int i = 0; i < len; ++i)
    pos[sa[i]] = i;

  // build lcp + sparse table
  for (int i = 0; i+1 < len; ++i) {
    sp[0][i] = lcp(sa[i], sa[i+1]);
  }
  for (int i = 0; i+1 < LG; ++i)
    for (int j = 0; j + (1 << (i+1)) < len; ++j)
      sp[i+1][j] = min(sp[i][j], sp[i][j+(1<<i)]);

  // ready to answer queries
  for (int i = 1; i <= q; ++i) {
    int v = que[i];
    int le = 0, ri = pos[v];
    while (le < ri) {
      int mid = (le + ri) >> 1;
      if (get(mid, pos[v]-1) >= lv[v])
        ri = mid;
      else
        le = mid + 1;
    }
    lef[i] = le;
    le = pos[v], ri = len-1;
    while (le < ri) {
      int mid = (le + ri + 1) >> 1;
      if (get(pos[v], mid-1) >= lv[v])
        le = mid;
      else
        ri = mid - 1;
    }
    rig[i] = ri;
  }
  for (int i = 1; i < len; ++i) {
    child[par[0][i]].push_back(i);
  }
  dfs(0);
  for (int i = 1; i <= q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
