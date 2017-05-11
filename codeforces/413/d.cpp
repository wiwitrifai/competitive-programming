#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
const long long inf = N;
vector< pair<long long, long long > > va[20], vb[20];
int x[N];
bool cek (long long a, long long b, long long w, long long h) {
  return (a <= w && b <= h) || (a <= h && b <= w);
}

int main() {
  int n, a, b, h, w;
  scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
  for (int i = 0; i < n; i++) 
    scanf("%d", x+i);
  sort(x, x+n);
  va[0].clear();
  va[0].emplace_back(1, 1);
  if (cek(a, b, h, w)) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= min(17, n); i++) {
    va[i].clear();
    long long now = x[n-i];
    for (auto it : va[i-1]) {
      va[i].emplace_back(min(inf, now * it.first), it.second);
      va[i].emplace_back(it.first, min(inf, now * it.second));
    }
    for (auto it : va[i]) {
      if (cek(a, b, it.first * h, it.second * w)) {
        printf("%d\n", i);
        return 0;
      }
    }
  }
  if (n > 17) {
    sort(va[17].begin(), va[17].end());
    long long cur = 0;
    for (int i = (int)va[17].size() - 1; i >= 0; i--) {
      cur = max(cur, va[17][i].second);
      va[17][i].second = cur;
    }
    vb[0].clear(); 
    vb[0].emplace_back(1, 1);
    for (int i = 1; i <= min(17, n-17); i++) {
      vb[i].clear();
      long long now = x[n-17-i];
      for (auto it : vb[i-1]) {
        vb[i].emplace_back(min(inf, now * it.first), it.second);
        vb[i].emplace_back(it.first, min(inf, now * it.second));
      }
      sort(vb[i].begin(), vb[i].end());
      for (int j = 0, k = (int)va[17].size(); j < vb[i].size(); j++) {
        while (k > 0 && va[17][k-1].first * vb[i][j].first * w >= a) k--;
        if (k < va[17].size()) {
          if (cek(a, b, va[17][k].first * vb[i][j].first * w, va[17][k].second * vb[i][j].second * h)) {
            printf("%d\n", i+17);
            return 0;
          }
        }
      }
      for (int j = 0, k = (int)va[17].size(); j < vb[i].size(); j++) {
        while (k > 0 && va[17][k-1].first * vb[i][j].first * w >= b) k--;
        if (k < va[17].size()) {
          if (cek(a, b, va[17][k].first * vb[i][j].first * w, va[17][k].second * vb[i][j].second * h)) {
            printf("%d\n", i+17);
            return 0;
          }
        }
      }
    }
  }
  puts("-1");
  return 0;
}