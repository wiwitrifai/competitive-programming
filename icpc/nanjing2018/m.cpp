#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, K = 2;

int b[N];
int cnt[N];
char s[N], t[N];

int mod[] = {int(1e9 + 7), int(1e9 + 9)};
int p[] = {29, 37};
int pp[K][N];

struct hashh {
  int h[K];
  hashh(int x = 0) {
    for (int i = 0; i < K; ++i)
      h[i] = x;
  }
  hashh operator+(hashh s) {
    hashh ret;
    for (int i = 0; i < K; ++i) {
      ret.h[i] = h[i] + s.h[i];
      if (ret.h[i] >= mod[i])
        ret.h[i] -= mod[i];
    }
    return ret;
  }
  hashh operator-(hashh s) {
    hashh ret;
    for (int i = 0; i < K; ++i) {
      ret.h[i] = h[i] - s.h[i];
      if (ret.h[i] < 0)
        ret.h[i] += mod[i];
    }
    return ret;
  }
  hashh operator<<(int k) {
    hashh ret;
    for (int i = 0; i < K; ++i) {
      ret.h[i] = 1LL * h[i] * pp[i][k] % mod[i];
    }
    return ret;
  }
  bool operator==(hashh s) {
    for (int i = 0; i < K; ++i)
      if (h[i] != s.h[i])
        return false;
    return true;
  }
};

hashh sh[N], th[N];

int main() {
  for (int i = 0; i < K; ++i) {
    pp[i][0] = 1;
    for (int j = 1; j < N; ++j) {
      pp[i][j] = 1LL * pp[i][j-1] * p[i] % mod[i];
    }
  }
  scanf("%s %s", s, t);
  int n = strlen(s), m = strlen(t);
  reverse(s, s+n);
  int l = 0, r = -1;
  vector<int> d1(n);
  for (int i = 0; i < n; ++i) {
    int k = (i>r ? 0 : min (d1[l+r-i], r-i)) + 1;
    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
    d1[i] = k--;
    if (i+k > r)
      l = i-k,  r = i+k;
    ++cnt[i+1];
    --cnt[i+d1[i]+1];
  }
  vector<int> d2 (n);
  l = 0, r = -1;
  for (int i = 0; i < n; ++i) {
    int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
    while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k])  ++k;
    d2[i] = --k;
    if (i+k-1 > r)
      l = i-k,  r = i+k-1;
    ++cnt[i+1];
    --cnt[i+d2[i]+1];
  }
  for (int i = 0; i < n; ++i) {
    sh[i+1] = (sh[i] << 1) + hashh(s[i] - 'a');
  }
  for (int i = 0; i < m; ++i) {
    th[i+1] = (th[i] << 1) + hashh(t[i] - 'a');
  }
  int sum = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    sum += cnt[i];
    int l = 0, r = min(n-i, m);
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      hashh now = sh[i+mid] - (sh[i] << mid);
      if (now == th[mid])
        l = mid;
      else
        r = mid - 1;
    }
    ans += 1LL * sum * l;
  }
  printf("%lld\n", ans);
  return 0;
}