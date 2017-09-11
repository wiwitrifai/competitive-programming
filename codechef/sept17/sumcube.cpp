#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7, MAGIC = 260;

set<int> st[N];
vector<pair<int, int> > ed;
long long pw[N];

int n, m, k;
long long calc1() {
  return 1LL * m * pw[n-2] % mod;
}

long long calc2() {
  long long all = 1LL * m * (m-1) / 2, common = 0;
  for (int v = 0; v < n; v++) {
    long long cur = st[v].size();
    common += cur * (cur - 1) / 2;
  }
  long long diff = all - common;
  diff %= mod;
  common %= mod;
  long long ans = 0;
  if (n >= 3)
    ans = (ans + common * pw[n-3]) % mod;
  if (n >= 4)
    ans = (ans + diff * pw[n-4]) % mod;
  return ans;
}

long long calc3() {
  long long all = 1LL * m * (m-1) * (m-2) / 6;
  long long tri = 0, yfour = 0, ufour = 0, five = 0, six = 0;
  for (auto e : ed) {
    int u = e.first, v = e.second;
    if (st[u].size() < st[v].size()) swap(u, v);
    for (int x : st[v])
      tri += st[u].count(x);
    ufour += 1LL * ((int)st[u].size() - 1) * ((int)st[v].size() - 1);    
  }
  ufour -= tri;
  tri /= 3;
  for (int v = 0; v < n; v++) {
    int cur = st[v].size();
    yfour += 1LL * cur * (cur - 1) * (cur - 2) / 6;
    five += 1LL * cur * (cur - 1) / 2 * (m - cur);
  }
  five -= 3 * tri + 2 * ufour;
  six = all - tri - yfour - ufour - five;
  tri %= mod;
  long long four = (yfour + ufour) % mod;
  five %= mod;
  six %= mod;
  long long ans = 0;
  if (n >= 3)
    ans = (ans + tri * pw[n-3]) % mod;
  if (n >= 4)
    ans = (ans + four * pw[n-4]) % mod;
  if (n >= 5)
    ans = (ans + five * pw[n-5]) % mod;
  if (n >= 6)
    ans = (ans + six * pw[n-6]) % mod;
  return ans;
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < N; i++)
    pw[i] = (pw[i-1] * 2) % mod;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    ed.clear();
    for (int i = 0; i < n; i++)
      st[i].clear();
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--; v--;
      ed.emplace_back(u, v);
      st[u].insert(v);
      st[v].insert(u);
    }
    long long ans = 0;
    if (k == 1) {
      ans = calc1();
    }
    else if (k == 2) {
      ans = (calc1() + 2LL * calc2()) % mod;
    }
    else {
      ans = (calc1() + 6LL * calc2() + 6LL * calc3()) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}