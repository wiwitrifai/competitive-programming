#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9;

int ans[N];
int bit[N];

void upd(int x, int v) {
  for (; x < N; x += x&-x)
    bit[x] = min(bit[x], v);
}

int get(int x) {
  int r = 1e9;
  for (; x; x -= x&-x)
    r = min(r, bit[x]);
  return r;
}

vector<tuple<int, int, int, int> > ev[8];

int main() {
  int xm[3], n, m, k;
  scanf("%d %d %d %d %d %d", xm, xm+1, xm+2, &n, &m, &k);
  int xa[3], xb[3];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      int z;
      scanf("%d", &z);
      xa[j] = i ? min(xa[j], z) : z;
      xb[j] = i ? max(xb[j], z) : z;
    }
  }
  bool ok = 1;
  for (int i = 0; i < m; ++i) {
    int y[3];
    bool found = 1;
    int mark = 0;
    for (int j = 0; j < 3; ++j) {
      scanf("%d", y+j);
      bool inside = y[j] >= xa[j] && y[j] <= xb[j];
      found &= inside;
      if (inside)
        y[j] = xb[j];
      if (y[j] >= xb[j])
        mark |= 1 << j;
      else
        y[j] = -y[j];
    }
    ev[mark].emplace_back(y[0], y[1], y[2], -1);
    if (found)
      ok = 0;
  }
  if (!ok) {
    puts("INCORRECT");
    return 0;
  }
  else
    puts("CORRECT");
  for (int i = 0; i < k; ++i) {
    int y[3];
    bool found = 1;
    int mark = 0;
    for (int j = 0; j < 3; ++j) {
      scanf("%d", y+j);
      bool inside = y[j] >= xa[j] && y[j] <= xb[j];
      found &= inside;
      if (inside)
        y[j] = xb[j];
      if (y[j] >= xb[j])
        mark |= 1 << j;
      else
        y[j] = -y[j];
    }
    if (found)
      ans[i] = 1;
    else {
      ans[i] = 0;
      ev[mark].emplace_back(y[0], y[1], y[2], i);
    }
  }
  for (int mask = 0; mask < 8; ++mask) {
    vector<int> vx[3];
    fill(bit, bit+N, inf);
    for (int j = 0; j < ev[mask].size(); ++j) {
      int y[3], d;
      tie(y[0], y[1], y[2], d) = ev[mask][j];
      for (int i = 0; i < 3; ++i)
        vx[i].push_back(y[i]);
    }
    for (int i = 0; i < 3; ++i) {
      sort(vx[i].begin(), vx[i].end());
      vx[i].erase(unique(vx[i].begin(), vx[i].end()), vx[i].end());
    }
    for (int i = 0; i < ev[mask].size(); ++i) {
      int y[3], d;
      tie(y[0], y[1], y[2], d) = ev[mask][i];
      for (int j = 0; j < 3; ++j) {
        y[j] = lower_bound(vx[j].begin(), vx[j].end(), y[j]) - vx[j].begin();
      }
      ev[mask][i] = make_tuple(y[0], y[1], y[2], d);
    }
    sort(ev[mask].begin(), ev[mask].end());
    for (auto it : ev[mask]) {
      int a, b, c, d;
      tie(a, b, c, d) = it;
      ++c;
      if (d == -1) {
        upd(b+1, c);
      }
      else {
        int val = get(b+1);
        if (c >= val)
          ans[d] = -1;
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    puts(ans[i] == 1 ? "OPEN" : ans[i] == 0 ? "UNKNOWN" : "CLOSED");
  }
  return 0;
}