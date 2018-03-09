#include <bits/stdc++.h>

using namespace std;

const int N = 17;

int dp[4][1 << N], pos[22];
bool can[4][1 << N];
int status[4][N];
vector<int> val;
vector<int> cek[4];
int siz[4] = {5, 5, 4, 4};
bool pernah[22];

void dfs(int id, int mask, int cur) {
  if (__builtin_popcount(cur) == siz[id]) {
    if (!can[id][cur]) return;
    dp[id][mask|cur] = 1;
    return;
  }
  int last = 0;
  while ((1 << last) <= cur) ++last;
  for (int i = last; i < 16; ++i) {
    if (cur & (1 << i)) continue;
    if (mask & (1 <<i)) continue;
    if (status[id][i] == -1) continue;
    if (status[id][i] == 1) {
      dfs(id, mask, cur|(1<<i));
      return;
    }
    dfs(id, mask, cur|(1<<i));
  }
}

int main() {
  int n;
  scanf("%d", &n);
  set<int> st;
  for (int i = 0; i < siz[0]; ++i) {
    char c;
    scanf(" %c", &c);
    st.insert(c-'A');
  }
  for (int i = 0; i < 21; ++i) {
    if (!st.count(i)) {
      pos[i] = val.size();
      val.push_back(i);
    }
    else
      pos[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    char p, w, r;
    scanf(" %c %c %c", &p, &w, &r);
    bool ok = 1;
    vector<int> tebak = {p-'A', w-'A', r-'A'};
    int mask = 0;
    for (int t : tebak) if (pos[t] != -1)
      mask |= 1 << pos[t];
    for (int j = 1; j <= 3; ++j) {
      int cur = (i+j) % 4;
      char c;
      scanf(" %c", &c);
      if (c == '-') {
        for (int t : tebak)
          if (pos[t] != -1) {
            status[cur][pos[t]] = -1;
          }
      }
      else if (c == '*') {
        if (mask != 0)
          cek[cur].push_back(mask);
        break;
      }
      else {
        int now = c-'A';
        if (pos[now] != -1) {
          for (int k = 0; k < 4; ++k)
            status[k][pos[now]] = -1;
          status[cur][pos[now]] = 1;
        }
        break;
      }
    }
  }
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 1; i < 4; ++i) {
    int harus = 0, larang = 0;
    for (int j = 0; j < 16; ++j)
      if (status[i][j] == 1)
        harus |= 1 << j;
      else if (status[i][j] == -1)
        larang |= 1 << j;
    int cnt = 0;
    for (int mask = 0; mask < (1 << 16); ++mask) {
      if (__builtin_popcount(mask) != siz[i]) continue;
      bool ok = 1;
      if ((harus & mask) != harus) ok = 0;
      if ((larang & mask) != 0) ok = 0;
      for (int c : cek[i]) {
        ok &= (c & mask) > 0;
        if (!ok) break;
      }
      cnt += ok;
      can[i][mask] = ok;
    }
  }
  for (int i = 0; i + 1 < 4; ++i) {
    for (int mask = 0; mask < (1 << 16); ++mask) {
      if (!dp[i][mask]) continue;
      dfs(i+1, mask, 0);
    }
  }
  for (int i = 0; i < (1 << 16); ++i) {
    if (!dp[3][i]) continue;
    if (__builtin_popcount(i) != 13) continue;
    int p, w, r;
    p = w = r = -1;
    for (int j = 0; j < 16; ++j) {
      if (i & (1 << j)) continue;
      if (val[j] < 6) p = val[j];
      else if (val[j] < 12) w = val[j];
      else r = val[j];
    }
    if (p != -1 & w != -1 & r != -1) {
      pernah[p] = 1;
      pernah[w] = 1;
      pernah[r] = 1;
    }
  }
  vector<char> p, w, r;
  for (int i = 0; i < 21; ++i) {
    if (!pernah[i]) continue;
    if (i < 6)
      p.push_back('A' + i);
    else if (i < 12)
      w.push_back('A' + i);
    else
      r.push_back('A' + i);
  }
  printf("%c%c%c\n", p.size() == 1 ? p[0] : '?', w.size() == 1 ? w[0] : '?', r.size() == 1 ? r[0] : '?');
  return 0;
}