#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char buff[N];
string p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buff);
    p[i] = buff;
  }
  int le = 0, ri = 0, ans = 0;
  char cl = p[n-1][0], cr = p[n-1].back();
  bool eq = 1;
  for (int i = n-1; i >= 0; --i) {
    if (eq) {
      bool same = 1;
      for (int j = 0; j < p[i].size(); ++j) {
        if (p[i][j] != cl) {
          same = 0;
        }
      }
      if (same) {
        le = ri = ans = ans * (p[i].size() + 1) + p[i].size();
      }
      else {
        int len = ans;
        for (int j = 0; j < p[i].size(); ++j) {
          if (p[i][j] != cl) break;
          le += len + 1;
        }
        for (int j = (int)p[i].size()-1; j >= 0; --j) {
          if (p[i][j] != cr) break;
          ri += len + 1;
        }
        int best = 0, cnt = 0;
        char last = 0;
        for (int j = 0; j < p[i].size(); ++j) {
          if (p[i][j] != last) {
            if (last == cl || len == 0) {
              best = max(best, cnt);
            }
            last = p[i][j];
            cnt = 0;
          }
          ++cnt;
        }
        if (last == cl || len == 0)
          best = max(best, cnt);
        ans = max(ans, len * (best + 1) + best);
        eq = 0;
      }
    }
    else if (cl == cr) {
      for (int j = 0; j < p[i].size(); ++j) {
        if (p[i][j] == cl)
          ans = max(ans, le + ri + 1);
      }
    }
    else {
      for (int j = 0; j < p[i].size(); ++j) {
        if (p[i][j] == cl)
          ans = max(ans, le + 1);
        if (p[i][j] == cr) {
          ans = max(ans, ri + 1);
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}