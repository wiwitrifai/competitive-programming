#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char a[N], b[N];

vector<pair<char, int>> compress(int n, char x[N]) {
  char last = x[0];
  int cnt = 0;
  vector<pair<char, int> > res;
  for (int i = 0; i < n; ++i) {
    if (last != x[i]) {
      res.emplace_back(last, cnt);
      last = x[i];
      cnt = 0;
    }
    ++cnt;
  }
  if (cnt) {
    res.emplace_back(last, cnt);
  }
  return res;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", a, b);
    int n = strlen(a), m = strlen(b);
    vector<pair<char, int>> va = compress(n, a), vb = compress(m, b);
    if (va.size() != vb.size()) {
      puts("NO");
      continue;
    }
    bool ok = 1;
    for (int i = 0; i < (int)va.size(); ++i) {
      if (va[i].first != vb[i].first) {
        ok = 0;
        break;
      }
      if (va[i].second > vb[i].second) {
        ok = 0;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
