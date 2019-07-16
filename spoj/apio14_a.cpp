#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];
int sa[N], pos[N], lcp[N], tmp[N], gap, n;

bool cmp_sa(int a, int b) {
  if (pos[a] - pos[b]) return pos[a] < pos[b];
  a += gap, b += gap;
  return (a < n && b < n) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    sa[i] = i, pos[i] = s[i];
  }
  for (gap = 1;; gap <<= 1) {
    sort(sa, sa+n, cmp_sa);
    for (int i = 1; i < n; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for (int i = 0; i < n; i++) pos[sa[i]] = tmp[i];
    if (tmp[n-1] == n-1) break;
  }
}

void build_lcp() {
  for (int i = 0, k = 0; i < n; i++) if (pos[i] - n + 1) {
    for (int j = sa[pos[i] + 1]; s[j+k] == s[i+k]; k++);
    lcp[pos[i]] = k;
    if (k) k--;
  }
}

const int LG = 20;
int sp[LG][N];

int get(int l, int r) { // [l, r)
  if (l > r) swap(l, r);
  int len = r - l;
  int lg = 31 - __builtin_clz(len);
  return min(sp[lg][l], sp[lg][r-(1 << lg)]);
}

int p[2][N];
int si[N], len[N];

bool cmp_mod(int a, int b) {
  int common = get(pos[a], pos[b]);
  if (len[a] < min(len[b], common)) return true;
  if (len[b] < min(len[a], common)) return false;
  // if (min(len[a], common) == min(len[b], common)) return false;
  return pos[a] < pos[b];
}


int main() {
  scanf("%s", s);
  build_sa();
  build_lcp();
  // build sparse table
  for (int i = 0; i < n - 1; i++)
    sp[0][i] = lcp[i];
  for (int i = 0; i + 1 < LG; i++) {
    for (int j = 0; j + (1 << (i+1)) <= n-1; j++)
      sp[i+1][j] = min(sp[i][j], sp[i][j + (1 << i)]);
  }
  memset(p, 0, sizeof p);
  int l = 0, r = -1;
  for (int z = 0, l = 0, r = 0; z < 2; z++, l = 0, r = 0) {
    for (int i = 0; i < n; i++) {
      if (i < r) p[z][i] = min(r-i+!z, p[z][l+r-i+!z]);
      int L = i-p[z][i], R = i+p[z][i] - !z;
      while (L-1 >= 0 && R+1 < n && s[L-1] == s[R+1]) p[z][i]++, L--, R++;
      if (R > r) l = L, r = R;
      // cerr << " " << z << " " << i << " " << p[z][i] << endl;
    }
  }
  // odd palindrom
  for (int i = 0; i < n; i++)
    si[i] = i;
  for (int i = 0; i < n; i++) {
    len[i] = p[1][i] + 1;
  }
  sort(si, si+n, cmp_mod);
  long long ans = 0;
  vector<pair<int, int> > st;
  for (int i = 0; i < n; i++) {
    int now = si[i];
    pair<int, int > val = {len[now], i};
    if (i)
      val.first = min(val.first, get(pos[si[i-1]], pos[si[i]]));
    while (!st.empty()) {
      if (st.back() > val) {
        ans = max(ans, (2 * st.back().first - 1) * 1LL * (i - st.back().second));
        st.pop_back();
      }
      else break;
    }
    if (st.empty() || (st.back().first < len[now]))
      st.push_back({len[now], i});
  }
  while (!st.empty()) {
    ans = max(ans, (2 * st.back().first - 1) * 1LL * (n - st.back().second));
    st.pop_back();
  }
  for (int i = 0; i < n; i++)
    len[i] = p[0][i];
  sort(si, si+n, cmp_mod);
  for (int i = 0; i < n; i++) {
    int now = si[i];
    pair<int, int > val = {len[now], i};
    if (i)
      val.first = min(val.first, get(pos[si[i-1]], pos[si[i]]));
    while (!st.empty()) {
      if (st.back() > val) {
        ans = max(ans, (2 * st.back().first) * 1LL * (i - st.back().second));
        st.pop_back();
      }
      else break;
    }
    if (st.empty() || (st.back().first < len[now]))
      st.push_back({len[now], i});
  }
  while (!st.empty()) {
    ans = max(ans, (2 * st.back().first) * 1LL * (n - st.back().second));
    st.pop_back();
  }
  printf("%lld\n", ans);
  return 0;
}