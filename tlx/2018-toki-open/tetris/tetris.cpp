#include "tetris.h"

#include <bits/stdc++.h>

using namespace std;

const int N = 222;

int dp[N][N][5][5][2];
vector<int> ans;
string s;

int add(int bef, int now, char ch) {
  if (ch == 'T') {
    if (now == 0 && (bef == 4 || (bef & 1) == 0)) return 1;
    if (now == 3 && (bef == 4 || (bef & 1) == 1)) return 3;
    return -1;
  }
  else if (ch == 'J') {
    if (now == 0 && (bef == 4 || (bef & 1) == 0)) return 1;
    if (now == 3) return 3;
    return -1;
  }
  else if (ch == 'L') {
    if (now == 0) return 1;
    if (now == 3 && (bef == 4 || (bef & 1) == 1)) return 3;
    return -1;
  }
  else if (ch == 'S') {
    if (now == 2 && (bef == 4 || (bef & 1) == 1)) return 1;
    return -1;
  }
  else if (ch == 'Z') {
    if (now == 1 && (bef == 4 || (bef & 1) == 0)) return 1;
    return -1;
  }
  return -1;
}

int hapus(int now, char ch) {
  if (ch == 'L') {
    if (now == 0) return 3;
    return -1;
  }
  if (ch == 'J') {
    if (now == 3) return 1;
    return -1;
  }
  return -1;
}
int change(int & now, char ch) {
  if (ch == 'T') {
    now ^= 1;
    if (now & 1)
      return 3;
    else
      return 1;
  }
  else if (ch == 'J') {
    if (now == 1) {
      now ^= 1;
      return 1;
    }
    return -1;
  }
  else if (ch == 'L') {
    if (now == 2) {
      now ^= 1;
      return 3;
    }
    return -1;
  }
  else if (ch == 'S') {
    if ((now & 1) == 0) {
      return 1;
    }
    return -1;
  }
  else if (ch == 'Z') {
    if ((now & 1) == 1) {
      return 1;
    }
    return -1;
  }
  return -1;
}

int solve(int l, int r, int mask, int pre, int isi) {
  if (l > r) return !isi;
  if (dp[l][r][mask][pre][isi] != -1) return dp[l][r][mask][pre][isi];
  int & res = dp[l][r][mask][pre][isi];
  res = 0;
  if (s[l] == 'O') return res = solve(l+1, r, mask, pre, isi);
  if (s[r] == 'O') return res = solve(l, r-1, mask, pre, isi);
  // kurang
  if (isi && hapus(mask, s[l]) >= 0) {
    res = solve(l+1, r, 4, pre, 0);
    if (res) return res;
  }
  // ubah
  int now = mask;
  if (isi && change(now, s[l]) >= 0) {
    res = solve(l+1, r, now, pre, isi);
    now = mask;
    if (res) return res;
  }
  // tambah
  if (isi) {
    for (int i = l; i <= r; ++i) {
      if (solve(l, i, 4, mask, 0) && solve(i+1, r, mask, pre, 1)) {
        return res = 1;
      }
    }
  }
  else {
    for (int cur = 0; cur < 4; ++cur) {
      if (add(pre, cur, s[l]) >= 0 && solve(l+1, r, cur, pre, 1)) {
        return res = 1;
      }
    }
  }
  return res = 0;
}

int check(int l, int r, int mask, int pre, int isi) {
  if (l > r) return !isi;
  return dp[l][r][mask][pre][isi] > 0;
}

void dfs(int l, int r, int mask, int pre, int isi) {
  assert(check(l, r, mask, pre, isi));
  if (l > r) return;
  if (s[l] == 'O') {
    dfs(l+1, r, mask, pre, isi);
    return;
  }
  if (s[r] == 'O') {
    dfs(l, r-1, mask, pre, isi);
    return;
  }
  // kurang
  if (isi && (ans[l] = hapus(mask, s[l])) >= 0) {
    if (check(l+1, r, 4, pre, 0)) {
      dfs(l+1, r, 4, pre, 0);
      return;
    }
  }
  // ubah
  int now = mask;
  if (isi && (ans[l] = change(now, s[l])) >= 0) {
    if (check(l+1, r, now, pre, isi)) {
      dfs(l+1, r, now, pre, isi);
      return;
    }
  }
  // tambah
  if (isi) {
    for (int i = l; i <= r; ++i) {
      if (check(l, i, 4, mask, 0) && check(i+1, r, mask, pre, 1)) {
        dfs(l, i, 4, mask, 0);
        dfs(i+1, r, mask, pre, 1);
        return;
      }
    }
  }
  else {
    for (int cur = 0; cur < 4; ++cur) {
      if ((ans[l] = add(mask, cur, s[l])) >= 0 && check(l+1, r, cur, pre, 1)) {
        dfs(l+1, r, cur, pre, 1);
        return;
      }
    }
  }
  return;
}

vector<int> arrangeTetrominoes(int N, std::string S, int Q) {
  s = S;
  ans.clear();
  memset(dp, -1, sizeof dp);
  int res = solve(0, N-1, 4, 4, 0);
  if (!res)
    return ans;
  ans.assign(N, 0);
  dfs(0, N-1, 4, 4, 0);
  return ans;
}