#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Fenwick {
  int n;
  vector<T> bit;
  Fenwick(int _n) : n(_n) {
    bit.assign(n+1, 0);
  }
  void update(int x, T v) {
    for (++x; x <= n; x += x&-x)
      bit[x] += v;
  }
  T get(int x) {
    T r = 0;
    for (++x; x; x -= x&-x)
      r += bit[x];
    return r;
  }
};

vector<int> zalgo(string s) {
  int L = 0, R = 0;
  int n = s.size();
  vector<int> Z(n, 0);
  for (int i = 1; i < n; ++i) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R] == s[R-L]) ++R;
      Z[i] = R-L; --R;
    }
    else {
      int k = i-L;
      if (Z[k] < R-i+1) Z[i] = Z[k];
      else {
        L = i;
        while (R < n && s[R] == s[R-L]) ++R;
        Z[i] = R-L; --R;
      }
    }
  }
  return Z;
}

const int N = 1e6 + 7;

char buffer[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", buffer);
  string a = buffer;
  scanf("%s", buffer);
  string b = buffer;
  scanf("%s", buffer);
  string s = buffer;
  vector<int> za = zalgo(s + a);
  string rs = s, rb = b;
  reverse(rs.begin(), rs.end());
  reverse(rb.begin(), rb.end());
  vector<int> zb = zalgo(rs + rb);
  vector<int> lena(n, 0), lenb(n, 0);
  vector<pair<int, int>> eventa;
  for (int i = 0; i < n; ++i) {
    lena[i] = min(za[m+i], m-1);
    eventa.emplace_back(lena[i], i);
  }
  vector<pair<int, int>> eventb;
  for (int i = 0; i < n; ++i) {
    lenb[i] = min(zb[n+m-1-i], m-1);
    eventb.emplace_back(lenb[i], i);
  }
  sort(eventa.begin(), eventa.end());
  sort(eventb.begin(), eventb.end());
  reverse(eventb.begin(), eventb.end());
  Fenwick<long long> sum(n+1), cnt(n+1);
  int p = 0;
  long long ans = 0;
  for (auto it : eventa) {
    while (p < (int)eventb.size() && eventb[p].first + it.first >= m) {
      sum.update(eventb[p].second, eventb[p].first);
      cnt.update(eventb[p].second, +1);
      ++p;
    }
    int l = it.second, r = min(l + m-2, n-1);
    long long res1 = sum.get(r) - sum.get(l-1), res2 = cnt.get(r) - cnt.get(l-1);
    ans += 1LL * (it.first - m + 1) * res2 + res1;
  }
  printf("%lld\n", ans);
  return 0;
}
