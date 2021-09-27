#include <bits/stdc++.h>

using namespace std;

struct SegTree {
  int n;
  vector<int> mini, lazy;
  SegTree(int _n) : n(_n), mini(2 * n, 0), lazy(2 * n, 0) {
  }

  inline void upd(int id, int x) {
    mini[id] += x;
    lazy[id] += x;
  }

  void push(int id, int il, int ir) {
    if (lazy[id] == 0) return;
    upd(il, lazy[id]);
    upd(ir, lazy[id]);
    lazy[id] = 0;
  }

  void update(int x, int y, int val, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      upd(id, val);
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + 2 * (mid - l);
    push(id, il, ir);
    update(x, y, val, il, l, mid);
    update(x, y, val, ir, mid, r);
    mini[id] = min(mini[il], mini[ir]);
  }

  void update(int x, int y, int val) {
    update(x, y, val, 0, 0, n);
  }
};


void solve() {
  int r, c, k, s;
  cin >> r >> c >> k >> s;
  vector<string> g(r + 2);
  g[0] = g[r+1] = string(c, '.');
  for (int i = 1; i <= r; ++i) {
    cin >> g[i];
  }
  for (int i = 0; i <= r + 1; ++i) {
    assert((int)g[i].size() == c);
    for (int j = 0; j < c; ++j) {
      g[i][j] = (g[i][j] == 'X');
    }
  }
  SegTree ans(r+2);
  for (int i = 0; i <= r+1; ++i) {
    ans.update(i, i+1, abs(i - k));
  }
  {
    int cnt = 0;
    for (int j = 0; j < c; ++j) {
      cnt += g[k][j];
    }
    ans.update(k, k+1, cnt);
  }
  vector<int> sum(c, 0);
  auto add = [&](int x) {
    for (int i = 0; i < c; ++i) {
      sum[i] += g[x][i];
    }
  };
  int limit_up = r - k + 1, limit_down = k;
  vector<int> pos_up(c, -1), pos_down(c, r + 2);
  for (int i = 1; i <= r+1; ++i) {
    add(i);
    for (int j = 0; j < c; ++j) {
      if (sum[j] >= limit_down) {
        pos_down[j] = min(i, pos_down[j]);
      }
    }
    if (i <= k) continue;
    int cnt = 0;
    for (int j = 0; j < c; ++j) {
      if (sum[j] < limit_down) {
        cnt += g[i][j];
      }
    }
    if (cnt > 0)
      ans.update(i, i+1, cnt);
  }
  sum.assign(c, 0);
  for (int i = r; i >= 0; --i) {
    add(i);
    for (int j = 0; j < c; ++j) {
      if (sum[j] >= limit_up) {
        pos_up[j] = max(i, pos_up[j]);
      }
    }
    if (i >= k) continue;
    int cnt = 0;
    for (int j = 0; j < c; ++j) {
      if (sum[j] < limit_up) {
        cnt += g[i][j];
      }
    }
    ans.update(i, i+1, cnt);
  }
  for (int j = 0; j < c; ++j) {
    ans.update(max(pos_down[j], k+1), r+2, +1);
    ans.update(0, min(pos_up[j], k-1)+1, +1);
  }
  vector<set<int>> vpos(c);
  for (int i = 0; i <= r+1; ++i) {
    for (int j = 0; j < c; ++j) {
      if (g[i][j]) {
        vpos[j].insert(i);
      }
    }
  }
  long long tot = 0;
  while (s--) {
    int a, b;
    cin >> a >> b;
    --b;
    ans.update(max(pos_down[b], k+1), r+2, -1);
    ans.update(0, min(pos_up[b], k-1)+1, -1);
    if (g[a][b]) {
      int old_up = pos_up[b], old_down = pos_down[b];

      auto it = vpos[b].find(a);
      assert(it != vpos[b].end());
      vpos[b].erase(it);
      if (k == a) {
        ans.update(a, a+1, -1);
      } else if (a < k) {
        if (a > pos_up[b])
          ans.update(a, a+1, -1);
      } else {
        if (a < pos_down[b])
          ans.update(a, a+1, -1);
      }

      if ((int)vpos[b].size() < limit_up) {
        pos_up[b] = -1;
      } else if (a >= pos_up[b]) {
        pos_up[b] = *(--vpos[b].lower_bound(pos_up[b]));
      }
      if ((int)vpos[b].size() < limit_down) {
        pos_down[b] = r + 2;
      } else if (a <= pos_down[b]) {
        pos_down[b] = *vpos[b].upper_bound(pos_down[b]);
      }

      if (old_up != pos_up[b] && old_up != a && old_up < k) {
        ans.update(old_up, old_up+1, 1);
      }

      if (old_down != pos_down[b] && old_down != a && old_down > k) {
        ans.update(old_down, old_down+1, 1);
      }

    } else {
      int old_up = pos_up[b], old_down = pos_down[b];

      auto it = vpos[b].find(a);
      assert(it == vpos[b].end());
      vpos[b].insert(a);

      if ((int)vpos[b].size() < limit_up) {
        pos_up[b] = -1;
      } else if (a >= pos_up[b]) {
        pos_up[b] = *(vpos[b].upper_bound(pos_up[b]));
      }
      if ((int)vpos[b].size() < limit_down) {
        pos_down[b] = r + 2;
      } else if (a <= pos_down[b]) {
        pos_down[b] = *(--vpos[b].lower_bound(pos_down[b]));
      }

      if (k == a) {
        ans.update(a, a+1, +1);
      } else if (a < k) {
        if (a > pos_up[b])
          ans.update(a, a+1, +1);
      } else {
        if (a < pos_down[b])
          ans.update(a, a+1, +1);
      }


      if (old_up != pos_up[b] && pos_up[b] != a && pos_up[b] < k) {
        ans.update(pos_up[b], pos_up[b]+1, -1);
      }

      if (old_down != pos_down[b] && pos_down[b] != a && pos_down[b] > k) {
        ans.update(pos_down[b], pos_down[b]+1, -1);
      }
    }
    g[a][b] ^= 1;

    ans.update(max(pos_down[b], k+1), r+2, +1);
    ans.update(0, min(pos_up[b], k-1)+1, +1);

    assert(ans.mini[0] >= 0);
    tot += ans.mini[0];
  }
  cout << tot << endl;
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
