#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> find(int r, int c) {
  vector<vector<int>> res(r, vector<int>(c));
  if (r == 1 && c == 1) {
    res[0][0] = 1;
    return res;
  }
  for (int i = 0; i < c; ++i) {
    int now = (c + i) % (c + 1);
    for (int j = 0; j < c; ++j) {
      res[i][j] = now;
      --now;
      if (now < 0)
        now = c;
    }
  }
  if (r > c) {
    int now = c-1;
    for (int j = 0; j < c; ++j) {
      res[c][j] = now;
      --now;
    }
  } else {
    res[0][0] = c-1;
  }
  for (int j = 0; j < c; ++j) {
    int now = 0;
    for (int k = 1; k < r-c; ++k) {
      if (now == j) {
        ++now;
      }
      res[c+k][j] = c + 1 + now;
      ++now;
    }
  }
  return res;
}

void solve() {
  int r, c;
  scanf("%d %d", &r, &c);
  vector<vector<int>> res =  find(max(r, c), min(r, c));
  if ((int)res.size() != r) {
    vector<vector<int>> tmp(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        tmp[i][j] = res[j][i];
      }
    res.swap(tmp);
  }
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      printf("%d%c", res[i][j], j+1 == c ? '\n' : ' ');
    }
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
