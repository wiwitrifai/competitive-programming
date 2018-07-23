#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> dv[N];
int le[512][8], ri[512][8];
int vmask[512];

vector<pair<int, int> > v[8];

bool cek(int a, int b, int c) {
  if (a == 0 || b == 0 || c == 0) return 0;
  if ((a | b | c) != 7) return 0;
  if (__builtin_popcount(a | b) < 2) return 0; 
  if (__builtin_popcount(b | c) < 2) return 0; 
  if (__builtin_popcount(c | a) < 2) return 0; 
  return 1;
}

int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i)
      dv[j].push_back(i);
  }
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      for (int k = 0; k < 8; ++k) {
        if (cek(i, j, k)) {
          v[j].emplace_back(i, k);
        }
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int a[3];
    scanf("%d %d %d", a, a+1, a+2);
    int id = 0;
    int it[3];
    memset(it, 0, sizeof it);
    while (1) {
      int now = N+1;
      for (int i = 0; i < 3; ++i) {
        if (it[i] < dv[a[i]].size())
          now = min(now, dv[a[i]][it[i]]);
      }
      if (now >= N) break;
      int mask = 0;
      for (int i = 0; i < 3; ++i) {
        if (it[i] < dv[a[i]].size() && dv[a[i]][it[i]] == now) {
          mask |= 1 << i;
          ++it[i];
        }
      }
      vmask[id] = mask;
      for (int j = 0; j < 8; ++j)
        le[id][j] = ri[id][j] = 0;
      ++le[id][mask];
      ++ri[id][mask];
      ++id;
    }
    for (int i = 0; i < id; ++i)
      for (int j = 0; j < 8; ++j)
        le[i+1][j] += le[i][j];
    for (int i = (int)id-1; i > 0; --i)
      for (int j = 0; j < 8; ++j)
        ri[i-1][j] += ri[i][j];
    long long ans = 0;
    for (int i = 0; i < id; ++i) {
      int now = vmask[i];
      for (auto it : v[now]) {
        ans += le[i][it.first] * ri[i][it.second];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}