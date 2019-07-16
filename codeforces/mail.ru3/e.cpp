#include <bits/stdc++.h>

using namespace std;

int p[] = {29, 31, 37, 41, 43, 47};
const int mod[] = {int(1e9+7), int(1e9+9)};
const int K = 2;
const int N = 1e6 + 6;

int pp[2][N];

struct hashh {
  int h[K];
  hashh(int x = 0) {
    fill(h, h+K, x);
  }
  hashh operator+(hashh vh) {
    hashh ret;
    for (int i = 0; i < K; ++i) {
      ret.h[i] = (h[i] + vh.h[i]);
      if (ret.h[i] >= mod[i])
        ret.h[i] -= mod[i];
    }
    return ret;
  }
  hashh operator-(hashh vh) {
    hashh ret;
    for (int i = 0; i < K; ++i) {
      ret.h[i] = (h[i] - vh.h[i]);
      if (ret.h[i] < 0)
        ret.h[i] += mod[i];
    }
    return ret;
  }
  hashh operator<<(int x) {
    hashh ret;
    for (int i = 0; i < K; ++i) {
      ret.h[i] = 1LL * h[i] * pp[i][x] % mod[i];
    }
    return ret;
  }
  bool operator==(hashh vh) {
    for (int i = 0; i < K; ++i)
      if (h[i] != vh.h[i])
        return false;
    return true;
  }
};


char s[N], t[N];
hashh sum[N];

int main() {
  srand(time(0));
  random_shuffle(p, p+6);
  for (int j = 0; j < K; ++j) {
    pp[j][0] = 1;
    for (int i = 1; i < N; ++i) {
      pp[j][i] = pp[j][i-1] * 1LL * p[j] % mod[j];
    }
  }
  scanf("%s %s", s, t);
  int n = strlen(s), m = strlen(t);
  int z = 0, o = 0;
  for (int i = 0; i < n; ++i) {
    s[i] -= '0';
    if (s[i])
      ++o;
    else
      ++z;
  }
  if (o == 0 || z == 0) {
    if (m % n) {
      puts("0");
      return 0;
    }
    int ans = 1;
    for (int i = n; i < m; ++i) {
      if (t[i] != t[i-n])
        ans = 0;
    }
    printf("%d\n", ans);
    return 0;
  }
  sum[0] = hashh();
  for (int i = 0; i < m; ++i) {
    t[i] -= 'a';
    sum[i+1] = (sum[i] << 1) + hashh(t[i]);
  }
  int ans = 0;
  for (int x = 1; x <= m; ++x) {
    long long y = m - 1LL * z * x;
    if (y <= 0) continue;
    if (y % o) continue;
    y /= o;
    hashh ho, hz;
    bool fo, fz;
    fo = fz = 0;
    bool ok = 1;
    for (int i = 0, j = 0; i < n; ++i) {
      hashh now;
      if (s[i]) {
        now = sum[j+y] - (sum[j] << y);
        j += y;
        if (fo) {
          if (!(ho == now)) {
            ok = 0;
            break;
          }
        }
        else {
          fo = 1;
          ho = now;
        }
      }
      else {
        now = sum[j+x] - (sum[j] << x);
        j += x;
        if (fz) {
          if (!(hz == now)) {
            ok = 0;
            break;
          }
        }
        else {
          fz = 1;
          hz = now;
        }
      }
    }
    if (hz == ho && x == y)
      ok = 0;
    ans += ok;
  }
  printf("%d\n", ans);
  return 0;
}