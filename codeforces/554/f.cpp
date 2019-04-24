#include <bits/stdc++.h>

using namespace std;

const int N = 337;
const int mod = 1e9 + 7;

#define MM 2305842993ll // MM = 2^61/mod
inline int rem(long long a){return a-mod*((a>>29)*MM>>32);}

struct matrix {
  int n, m;
  int a[N][N];
  matrix(int n, int m) : n(n), m(m) {
    memset(a, 0, sizeof a);
  }
  void reset() {
    memset(a, 0, sizeof a);
    for(int i = 0; i<n; ++i)
      a[i][i] = 1;
  }
  const int * operator[](const int id) const {
    return a[id];
  }
  int * operator[](const int id) {
    return a[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i < this->n; ++i) {
      for(int j = 0; j < mat.m; ++j) {
        long long now = 0;
        for(int k = 0; k<this->m; ++k) {
          now = rem(now + (long long)this->a[i][k] * mat[k][j]);
        }
        now %= mod;
        if (now < 0)
          now += mod;
        ret[i][j] = now;
      }
    }
    return ret;
  }
  matrix operator^(long long pw) const {
    matrix ret(n, m), base = *this;
    ret.reset();
    while(pw) {
      if(pw & 1)
        ret = ret*base;
      base = base*base;
      pw >>= 1;
    }
    return ret;
  }
};

ostream& operator<<(ostream& os, const matrix & mat) {
  for(int i = 0; i < mat.n; ++i) {
    for(int j = 0; j < mat.m; ++j)
      os << mat.a[i][j] << " ";
    os << endl;
  }
  return os;
}
vector<tuple<int, int, int> > valid;

int enc(int n, int mask, int last) {
  auto it = lower_bound(valid.begin(), valid.end(), make_tuple(n, mask, last));
  assert(it != valid.end() && *it == make_tuple(n, mask, last));
  return it - valid.begin();
}

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 0; i <= k; ++i) {
    int nmask = 1 << m;
    for (int mask = 0; mask < nmask; ++mask) {
      for (int last = 0; last <= 1; ++last) {
        if (__builtin_popcount(mask) + last > i) continue;
        valid.emplace_back(i, mask, last);
      }
    }
  }
  cerr << valid.size() << endl;
  matrix x(valid.size(), valid.size());
  int add = 1 << (m-1);
  for (auto it : valid) {
    int s, mask, last;
    tie(s, mask, last) = it;
    int now = enc(s, mask, last);
    if (last == 0) {
      x[enc(s, mask >> 1, mask & 1)][now] += 1;
      if (s + 1 <= k) {
        x[enc(s+1, (mask >> 1) | add, mask & 1)][now] += 1;
        x[enc(s+1, (mask >> 1), mask & 1)][now] += __builtin_popcount(mask);
      }
    }
    else if ((mask & 1) == 0) {
      x[enc(s, mask >> 1, last)][now] += 1;
      if (s + 1 <= k) {
        x[enc(s+1, (mask >> 1) | add, last)][now] += 1;
        x[enc(s+1, (mask >> 1), last)][now] += __builtin_popcount(mask) + last;
      }
    }
    if (s + 1 <= k) {
      for (int i = 0; i < m; ++i) {
        if (mask & (1 << i)) {
          int cur = mask ^ (1 << i);
          if (last) {
            if ((cur & 1) == 0) {
              x[enc(s+1, (cur >> 1) | add, last)][now] += 1;
              x[enc(s+1, (cur >> 1), last)][now] += __builtin_popcount(cur) + last;
            }
          }
          else {
            x[enc(s+1, (cur >> 1) | add, cur & 1)][now] += 1;
            x[enc(s+1, (cur >> 1), cur & 1)][now] += __builtin_popcount(cur);
          }
        }
      }
    }
  }
  matrix result(valid.size(), 1);
  result[enc(0, 0, 0)][0] = 1;
  for (; n; n >>= 1, x = x * x)
    if (n & 1)
      result = x * result;
  int ans = result[enc(k, 0, 1)][0];
  for (int i = 0; i < m; ++i) {
    ans = (ans + result[enc(k, 1 << i, 0)][0]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
