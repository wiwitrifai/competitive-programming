#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5, mod = 1e9 + 7, MAGIC = 50;
 
vector<int> fac[N];
vector<int> elem[N];
long long g[N];
int cnt[N];
 
long long solve(vector<int> & val) {
  vector<int> all;
  for (int x : val) {
    all.push_back(x);
    for (int z : fac[x])
      all.push_back(z);
  }
  all.push_back(1);
  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  for (int z : all) {
    cnt[z] = 0;
  }
  for (int x : val) {
    if (x > 1)
      ++cnt[x];
    ++cnt[1];
    for (int z : fac[x])
      ++cnt[z];
  }
  for (int x : all) {
    cnt[x] = 1LL * cnt[x] * cnt[x] % mod;
  }
  long long ans = 0;
  for (int x : all) {
    int cur = cnt[x];
    ans = (ans + 1LL * x * cur) % mod;
    for (int z : fac[x]) {
      cnt[z] -= cur;
      if (cnt[z] < 0)
        cnt[z] += mod;
    }
    if (x > 1) {
      cnt[1] -= cur;
      if (cnt[1] < 0)
        cnt[1] += mod;
    }
  }
  return ans;
}
 
int main() {
  for (int i = 2; i < N; ++i) {
    for (int j = i+i; j < N; j += i) {
      fac[j].push_back(i);
    }
  }
  int maxi = 0, s = 0;
  for (int i = 2; i < N; ++i) {
    maxi = max(maxi, (int)fac[i].size());
    s += fac[i].size();
  }
  int n;
  scanf("%d", &n);
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      elem[i].push_back(a[j]);
    }
  }
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    g[i] = solve(elem[i]);
    for (int j = i + i; j <= n; j += i) {
      g[i] -= g[j];
      if (g[i] < 0)
        g[i] += mod;
    }
    ans = (ans + g[i] * i) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
