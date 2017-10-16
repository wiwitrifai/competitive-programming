/**
  IEEExtreme Programming Contest 10
  Problem : Safety
  Solver  : Wiwit Rifa'i
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int mod = 1e9 + 7, p = 37;
char s[N];
int n;

// hash
long long pp[N], ip[N];
long long hh[N][26];

long long powmod(long long b, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    pw >>= 1;
  }
  return ret;
}

// seg tree
long long hs[N << 2];
long long ss[N << 2][26];
int beg[N << 2], add[N << 2]; 
void build(int id = 1, int l = 0, int r = n) {
  beg[id] = -1;
  add[id] = 0;
  if (r-l < 2) {
    for (int i = 0; i < 26; i++)
      ss[id][i] = 0;
    int c = s[l] - 'a';
    ss[id][c] = pp[l];
    hs[id] = pp[l] * c % mod;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  hs[id] = hs[il] + hs[ir];
  if (hs[id] >= mod)
    hs[id] -= mod;
  for (int i = 0; i < 26; i++) {
    ss[id][i] = ss[il][i] + ss[ir][i];
    if (ss[id][i] >= mod)
      ss[id][i] -= mod;
  }
}

long long tmp[26];
void upd(int id, int l, int r, int k, int d) {
  if (k >= 0) {
    int len = r-l;
    long long norm = (ip[k] * pp[l]) % mod;
    hs[id] = 0;
    for (int i = 0; i < 26; i++) {
      int j = j = i + d;
      if (j >= 26)
        j -= 26;
      ss[id][j] = (hh[k+len-1][i] - (k > 0 ? hh[k-1][i] : 0)) * norm % mod;
      if (ss[id][j] < 0)
        ss[id][j] += mod;
      hs[id] += ss[id][j] * j;
    }
    hs[id] %= mod;
    if (hs[id] < 0)
      hs[id] += mod;
    beg[id] = k;
    add[id] = d;
  }
  else if (d > 0) {
    for (int i = 0; i < 26; i++)
      tmp[i] = ss[id][i];
    hs[id] = 0;
    for (int i = 0; i < 26; i++) {
      int j = i + d;
      if (j >= 26)
        j -= 26;
      ss[id][j] = tmp[i];
      hs[id] += ss[id][j] * j;
    }
    hs[id] %= mod;
    if (hs[id] < 0) hs[id] += mod;
    add[id] += d;
    if (add[id] >= 26)
      add[id] -= 26;
  }
}

void shift(int id, int l, int r) {
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  upd(il, l, mid, beg[id], add[id]);
  upd(ir, mid, r, beg[id] < 0 ? -1 : beg[id] + mid - l, add[id]);
  beg[id] = -1;
  add[id] = 0;
}
void update(int x, int y, int k, int d, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    upd(id, l, r, k < 0 ? -1 : k + (l-x), d);
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id, l, r);
  update(x, y, k, d, il, l, mid);
  update(x, y, k, d, ir, mid, r);
  hs[id] = hs[il] + hs[ir];
  if (hs[id] >= mod)
    hs[id] -= mod;
  for (int i = 0; i < 26; i++) {
    ss[id][i] = ss[il][i] + ss[ir][i];
    if (ss[id][i] >= mod)
      ss[id][i] -= mod;
  }
}
long long get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || y <= l) return 0;
  if (x <= l && r <= y) {
    long long ret = hs[id];
    return ret;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  shift(id, l, r);
  long long ret = get(x, y, il, l, mid) + get(x, y, ir, mid, r);
  if (ret >= mod)
    ret -= mod;
  return ret;
}

int main() {
  long long ii = powmod(p, mod-2);
  pp[0] = ip[0] = 1;
  for (int i = 1; i < N; i++) {
    pp[i] = (pp[i-1] * p) % mod;
    ip[i] = (ip[i-1] * ii) % mod;
  }
  scanf("%s", s);
  n = strlen(s);
  for (int j = 0; j < 26; j++) {
    hh[0][j] = 0;
  }
  hh[0][s[0] - 'a']++;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      hh[i][j] = hh[i-1][j];
    }
    int c = s[i] - 'a';
    hh[i][c] = (hh[i][c] + pp[i]) % mod;
  }
  build();
  int q;
  scanf("%d", &q);
  while (q--) {
    int ty, l, r, k;
    scanf("%d %d %d", &ty, &l, &r);
    l--;
    if (ty == 1) {
      scanf("%d", &k);
      k--;
      long long res1 = get(l, r) * ip[l] % mod;
      long long res2 = get(k, k + r-l) * ip[k] % mod;
      if (res1 < 0) res1 += mod;
      if (res2 < 0) res2 += mod;
      puts(res1 == res2 ? "Y" : "N");
    }
    else if (ty == 2) {
      scanf("%d", &k);
      k--;
      update(l, r, k, 0);
    }
    else {
      update(l, r, -1, 1);
    }
  }
  return 0;
}