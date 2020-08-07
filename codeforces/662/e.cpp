#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

char buffer[N];

void upd(int & var, int add) {
  var += add;
  if (var >= mod)
    var -= mod;
}

vector<int> calc(const string & pre, const string & cur, const vector<int> & dp) {
  vector<int> ndp(cur.size() + 1, 0);
  vector<int> mem_up[3], mem_down;
  for (int i = 0; i < 3; ++i) {
    mem_up[i].resize(cur.size(), -2);
  }
  function<int(int, int)> cmp_up = [&](int i, int j) {
    if (i >= (int)pre.size() && j >= (int)cur.size()) return 0;
    if (i >= (int)pre.size()) return 1;
    if (j >= (int)cur.size()) return -1;
    assert(abs(i-j) <= 1);
    int & ret = mem_up[1+i-j][j];
    if (ret != -2)
      return ret;
    if (pre[i] != cur[j]) {
      return ret = (pre[i] < cur[j] ? 1 : -1);
    }
    return ret = cmp_up(i+1, j+1);
  };
  mem_down.resize(cur.size(), -2);
  function<int(int)> cmp_down = [&](int i) {
    if (i < 0)
      return 0;
    int & ret = mem_down[i];
    if (ret != -2)
      return ret;
    ret = cmp_down(i-1);
    if (ret == 0) {
      if (i >= (int)pre.size())
        ret = 1;
      else if (pre[i] != cur[i]) {
        ret = (pre[i] < cur[i] ? 1 : -1);
      }
    }
    return ret;
  };

  vector<int> val(3, 0);
  int state = 0;
  upd(val[1], dp[0]);
  for (int i = 0; i < (int)cur.size(); ++i) {
    if (state > 0 || (state == 0 && cmp_up(i, i+1) >= 0)) {
      upd(ndp[i], dp.back());
    }
    upd(ndp[i], val[2]);
    if (cmp_up(i+1, i+1) >= 0) {
      upd(ndp[i], val[1]);
    }
    if (state == 0) {
      if (i >= (int)pre.size())
        state = 1;
      else if (pre[i] != cur[i])
        state = pre[i] < cur[i] ? 1 : -1;
    }
    if (i+1 >= (int)pre.size()) {
      upd(val[2], val[1]);
      val[1] = 0;
    } else if (pre[i+1] != cur[i]) {
      if (pre[i+1] < cur[i])
        upd(val[2], val[1]);
      else
        upd(val[0], val[1]);
      val[1] = 0;
    }
    if (i + 1 < (int)pre.size())
      upd(val[1 + state], dp[i+1]);
  }
  if (cmp_up(cur.size()+1, cur.size()) >= 0)
    upd(ndp.back(), val[1]);
  upd(ndp.back(), val[2]);
  if (state > 0) {
    for (int i = min(cur.size()+1, dp.size()-1); i < (int)dp.size(); ++i)
      upd(ndp.back(), dp[i]);
  } else if (state == 0 && cmp_up(cur.size(), cur.size()) >= 0) {
    upd(ndp.back(), dp.back());
  }
  fill(val.begin(), val.end(), 0);
  for (int i = (int)cur.size(); i < (int)pre.size(); ++i)
    upd(val[0], dp[i]);
  for (int i = (int)cur.size()-1; i >= 0; --i) {
    if (cmp_down(i-1) > 0) {
      for (int j = 0; j < 3; ++j)
        upd(ndp[i], val[j]);
    } else if (cmp_down(i-1) == 0) {
      for (int j = 1; j < 3; ++j) {
        upd(ndp[i], val[j]);
      }
    }
    if (i < (int)pre.size())
      upd(val[1 + cmp_up(i+1, i+1)], dp[i]);
    if (i > 0 && i-1 < (int)pre.size()) {
      if (pre[i-1] < cur[i]){
        upd(val[2], val[0]);
        upd(val[2], val[1]);
        val[0] = val[1] = 0;
      } else if (pre[i-1] > cur[i]) {
        upd(val[0], val[1]);
        upd(val[0], val[2]);
        val[2] = val[1] = 0;
      }
    }
  }
  return ndp;
}


void solve() {
  int n;
  scanf("%d", &n);
  string last;
  vector<int> dp;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    string cur = buffer;
    if (i) {
      dp = calc(last, cur, dp);
    } else {
      dp.resize(cur.size()+1, 1);
    }
    last = cur;
  }
  int ans = 0;
  for (int x : dp) {
    ans = (ans + x) % mod;
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
