#include <bits/stdc++.h>

using namespace std;

const int N = 55;

vector<int> a[N];
pair<int, int> p[N];

// length - colour
set<pair<int, int>> all;

void add(int c) {
  for (auto it : a[c]) {
    all.insert({it, c});
  }
}

void remove(int c) {
  for (auto it : a[c]) {
    all.erase({it, c});
  }
}

int main() {
  freopen("sticks.in", "r", stdin);
  freopen("sticks.out", "w", stdout);
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int n;
    scanf("%d", &n);
    while (n--) {
      int v;
      scanf("%d", &v);
      a[i].push_back(v);
    }
    sort(a[i].begin(), a[i].end());
    a[i].resize(distance(a[i].begin(), unique(a[i].begin(), a[i].end())));
    p[i] = {a[i].size(), i};
  }
  for (int i = 0; i < k; i++) add(i);
  for (int i = 0; i < k; i++) {
    int ci = p[i].second;
    remove(ci);
    for (int j = 0; j < k; j++) {
      if (i == j) continue;
      int cj = p[j].second;
      remove(cj);

      int r = a[cj].size() - 1;
      for (int q = a[ci].size() - 1; q >= 0; q--) {
        while (r >= 0 && a[ci][q] < a[cj][r]) r--;
        if (r < 0) break;
        int lc = a[ci][q];
        int lb = a[cj][r];
        auto it = all.upper_bound({lb, -1});
        if (it != all.begin()) {
          it--;
          int la = it->first;
          int ck = it->second;
          if (la + lb > lc) {
            printf("%d %d %d %d %d %d\n", ci+1, lc, cj+1, lb, ck+1, la);
            return 0;
          }
        }
      }

      add(cj);
    }
    add(ci);
  }
  puts("NIE");
  return 0;
}