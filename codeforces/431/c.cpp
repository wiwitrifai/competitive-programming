#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 2154, N = 1e5 + 2 * MAGIC + 6;

int cnt[N];
int a[N], b[N], n, m;
int x[N], y[N], t[N], ll[N], rr[N];
int ql[N], qr[N];
int le[N], ri[N];
set<int> st[N];
vector< int > que;
vector<pair<int, pair<int,int> > > upd;
long long ans[N], cur = 0;

bool cmp(int lz, int rz) {
  int gl = lz/ MAGIC, gr = rz/MAGIC;
  if (gl != gr)
    return gl < gr;
  gl = x[lz]/MAGIC, gr = x[rz]/MAGIC;
  if (gl != gr)
    return gl < gr;
  return y[lz] < y[rz];
}

void change(int it, int bl, int br) {
  int c = a[x[it]];
  // cerr << c << " | " << le[c] << " " << ri[c] << " " << x[it] << endl;
  if (le[c] == x[it] && ri[c] == x[it])
    le[c] = ri[c] = -1;
  else if (le[c] == x[it])
    cur -= rr[x[it]] - le[c], le[c] = rr[x[it]];
  else if (ri[c] == x[it])
    cur -= ri[c] - ll[x[it]], ri[c] = ll[x[it]];
  // cerr << c << " | " << le[c] << " " << ri[c] << " " << x[it] << endl;
  swap(a[x[it]], y[it]);
  swap(ql[it], ll[x[it]]);
  swap(qr[it], rr[x[it]]);
  if (x[it] < bl || x[it] >= br) return;
  c = a[x[it]];
  cur -= ri[c] - le[c];
  if (le[c] == -1)
    le[c] = ri[c] = x[it];
  le[c] = min(le[c], x[it]);
  ri[c] = max(ri[c], x[it]);
  cur += ri[c] - le[c];
}

int main() {
  scanf("%d %d", &n, &m);
  memset(ql, -1, sizeof ql);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    b[i] = a[i];
    ll[i] = ql[a[i]];
    ql[a[i]] = i;
    st[a[i]].insert(i);
  }
  memset(qr, -1, sizeof qr);
  for (int i = n-1; i >= 0; i--) {
    rr[i] = qr[a[i]];
    qr[a[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", t+i, x+i, y+i);
    x[i]--;
    if (t[i] == 2)
      que.push_back(i);
    else {
      st[b[x[i]]].erase(x[i]);
      b[x[i]] = y[i];
      auto it = st[b[x[i]]].lower_bound(x[i]);
      ql[i] = -1, qr[i] = -1;
      if (it != st[y[i]].end())
        qr[i] = *it;
      if (it != st[y[i]].begin()) {
        it--;
        ql[i] = *it;
      }
      st[b[x[i]]].insert(x[i]);
    }
  }
  sort(que.begin(), que.end(), cmp);
  int gu = -1, gl = -1, nl = -1, nr = -1;
  for (auto it : que) {
    int ngu = it/MAGIC, ngl = x[it]/MAGIC;
    if (ngu != gu || ngl != gl) {
      if (ngu != gu) {
        for (int i = max(gu * MAGIC, 0); i < ngu * MAGIC; i++) {
          if (t[i] == 1) {
            a[x[i]] = y[i];
            ll[x[i]] = ql[i];
            rr[x[i]] = qr[i];
          }
        }
      }
      memset(le, -1, sizeof le);
      memset(ri, -1, sizeof ri);
      cur = 0;
      nr = (ngl + 1) * MAGIC;
      gu = ngu;
      gl = ngl;
    }
    while (nr < y[it]) {
      cur -= ri[a[nr]] - le[a[nr]];
      if (le[a[nr]] == -1)
        le[a[nr]] = nr;
      else
        le[a[nr]] = min(le[a[nr]], nr);
      ri[a[nr]] = max(ri[a[nr]], nr);
      cur += ri[a[nr]] - le[a[nr]];
      nr++;
    }
    nl = min((gl+1) * MAGIC, y[it]);
    while (nl > x[it]) {
      nl--;
      upd.push_back({a[nl], {le[a[nl]], ri[a[nl]]}});
      cur -= ri[a[nl]] - le[a[nl]];
      if (le[a[nl]] == -1)
        le[a[nl]] = nl;
      else
        le[a[nl]] = min(le[a[nl]], nl);
      ri[a[nl]] = max(ri[a[nl]], nl);
      cur += ri[a[nl]] - le[a[nl]];
    }
    for (int i = gu * MAGIC; i <= it; i++) {
      if (t[i] == 2) continue;
      change(i, x[it], y[it]);
    }
    // for (int i = 0; i <= n; i++)
    //   cerr << i << " " << le[i] << " " << ri[i] << endl;
    // cerr << it << " = " << cur << endl;
    ans[it] = cur;
    for (int i = it; i >= gu * MAGIC; i--) {
      if (t[i] == 2) continue;
      change(i, x[it], y[it]);
    }
    for (int i = (int)upd.size() - 1; i >= 0; i--) {
      int val = upd[i].first;
      cur -= ri[val] - le[val];
      ri[val] = upd[i].second.second;
      le[val] = upd[i].second.first;
      cur += ri[val] - le[val];
      // cerr << " rev " << val << " " << le[val] << " " << ri[val] << endl;
    }
    upd.clear();
  }
  for (int i = 0; i < m; i++)
    if (t[i] == 2)
      printf("%I64d\n", ans[i]);
  return 0;
}