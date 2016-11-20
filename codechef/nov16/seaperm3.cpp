#include <bits/stdc++.h>

using namespace std;

const long long mod = 2e9 + 11;

struct matrix {
  long long a[4][4];
  long long * operator[](int id) {
    return a[id];
  }
  matrix operator* (matrix m) {
    matrix ret;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        long long & now = ret[i][j];
        now = 0;
        for (int k = 0; k < 4; k++) {
          now = (now + a[i][k] * m[k][j]) % mod;
        }
      }
    }
    return ret;
  }
  matrix operator^(long long p) {
    matrix ret;
    ret[0][0] = ret[1][1] = 1;
    ret[0][1] = ret[1][0] = 0;
    if (p <= 0)
      return ret;
    matrix b = *this;
    while (p) {
      if (p & 1)
        ret = ret * b;
      b = b * b;
      p >>= 1;
    }
    return ret;
  }
};

long long powmod(long long b, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    p >>= 1;
  }
  return ret;
}

long long fac(long long n) {
  long long ret = 1;
  for (int i = 2; i <= n; i++) {
    ret = (ret * i) % mod;
  }
  return ret;
}

matrix a, b, c, d, e;
void upd(matrix & mat, long long & now, int & block, long long to) {
  while (now < to && block) {
    if (block == 3)
      mat = c * mat;
    else if (block == 2)
      mat = e * mat;
    else if (block == 1)
      mat = b * mat;
    else
      assert(false);
    // cerr << now << " " << to << " " << block << " :" << mat[0][0] << endl;
    now++;
    block >>= 1;
  }
  if (now < to) {
    mat = (a ^ (to-now)) * mat;
    now = to;
  }
}

int main() {
  a[0][0] = 2; a[0][1] = 1; a[1][0] = 1; a[1][1] = 0; // dp[n] = 2 * dp[n-1] + dp[n-2]
  b[0][0] = 1; b[0][1] = 1; b[1][0] = 1; b[1][1] = 0; // dp[n] = dp[n-1] + dp[n-2]
  c[0][0] = 1; c[0][1] = 0; c[1][0] = 1; c[1][1] = 0; // dp[n] = dp[n-1]
  d[0][0] = 0; d[0][1] = 1; d[1][0] = 1; d[1][1] = 0; // dp[n] = dp[n-2]
  e[0][0] = 2; e[0][1] = 0; e[1][0] = 1; e[1][1] = 0; // dp[n] = 2 * dp[n-1]
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    bool ok = true;
    vector< pair<int, int > > fix;
    set < int > st;
    for (int i = 0; i < m; i++) {
      int x, v;
      scanf("%d %d", &x, &v);
      fix.emplace_back(v, x);
      if (st.count(v)) {
        ok = false;
      }
      st.insert(v);
    }
    sort(fix.begin(), fix.end());
    long long ans = fac(n-m);
    int up = -1;
    for (int i = 0; i < m; i++) {
      if (fix[i].first > up)
        up = -1;
      if (fix[i].second > fix[i].first) {
        if (up > fix[i].first) {
          ok = false;
          break;
        }
        up = fix[i].second;
      }
      else {
        if (fix[i].second == fix[i].first) {
          if (up > -1) {
            ok = false;
            break;
          }
          continue;
        }
        if (fix[i].second+1 == fix[i].first)
          continue;
        if (fix[i].second+2 == fix[i].first) {
          if (i > 0 && fix[i].first == fix[i-1].first + 1 && fix[i-1].second > fix[i-1].first)
            continue;
          if (up > -1) {
            ok = false;
            break;
          }
          if (i > 0 && fix[i].first == fix[i-1].first + 1) {
            ok = false;
            break;
          }
          continue;
        }
        ok = false;
        break;
      }
    }
    if (!ok)
      printf("%lld\n", ans);
    else {
      matrix res;
      res[0][0] = 1; res[1][0] = res[0][1] = res[1][1] = 0;// { {dp[n], 0}, {dp[n-1], 0} }
      long long now = 1;
      int block = 0;
      up = -1;
      for (int i = 0; i < m; i++) {
        if (fix[i].first == fix[i].second) {
          upd(res, now, block, fix[i].first - 1);
          block |= 3;
          upd(res, now, block, fix[i].first);
          block |= 3;
          continue;
        }
        else if (fix[i].first < fix[i].second) {
          upd(res, now, block, fix[i].first-1);
          block = 3;
          // cerr << now << endl;
          upd(res, now, block, fix[i].first);
          res = (c ^ (fix[i].second - now)) * res;
          block >>= (fix[i].second - now);
          now = fix[i].second;
          block |= 2;
          int prev = i;
          while (i < m && fix[i].first < now) i++;
          if (i < m && fix[i].first == now && fix[i].first > fix[i].second) i++;
          i--;
          if (i < prev) i = prev;
        }
        else {
          upd(res, now, block, fix[i].second);
          if (fix[i].second + 1 == fix[i].first) {
            block |= 3;
            upd(res, now, block, fix[i].first);
          }
          else if (fix[i].second + 2 == fix[i].first) {
            block |= 3;
            upd(res, now, block, fix[i].first-1);
            res = d * res;
            now = fix[i].first;
            block >>= 1;
            block |= 1;
          }
          else
            assert(false);
        }
        // cerr << res[0][0] << " " << block<< " "  << now << endl;
      }
      upd(res, now, block, n);
      // cerr << res[0][0] << endl;
      ans -= res[0][0];
      ans %= mod;
      if (ans < 0)
        ans += mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}