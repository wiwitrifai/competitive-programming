#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int s[N];
int sa[N], pos[N], lcp[N], tmp[N], gap, n;

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < n && b < n) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  vector<int> distinct(n);
  for (int i = 0; i < n; ++i)
    distinct[i] = s[i];
  sort(distinct.begin(), distinct.end());
  distinct.erase(unique(distinct.begin(), distinct.end()), distinct.end());
  for(int i = 0; i<n; i++)
    sa[i] = i, pos[i] = lower_bound(distinct.begin(), distinct.end(), s[i]) - distinct.begin();
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + n, cmp_sa);
    for(int i = 1; i<n; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<n; i++) pos[sa[i]] = tmp[i];
    if(tmp[n-1] == n-1) break;
  }
}

void build_lcp() {
  for(int i = 0, k = 0; i<n; i++) if(pos[i] - n + 1) {
    for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k]; k++);
    lcp[pos[i]] = k;
    if(k) k--;
  }
  lcp[n-1] = 0;
}

struct maksi {
  int maks;
  long long sum;
  int from;
};

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", s+i);
  build_sa();
  build_lcp();
  vector<maksi> vm;
  long long ans = 0;
  for (int i = n-1; i >= 0; --i) {
    while (!vm.empty() && vm.back().maks <= s[i]) {
      vm.pop_back();
    }
    maksi now = {s[i], 0LL, i};
    if (vm.empty())
      now.sum = 1LL * (n - i) * s[i];
    else
      now.sum = vm.back().sum + 1LL * (vm.back().from - i) * s[i];
    vm.push_back(now);
    int lo = 0, ri = (int)vm.size()-1;
    int from = i + lcp[pos[i]];
    while (lo < ri) {
      int mid = (lo + ri) >> 1;
      if (vm[mid].from <= from)
        ri = mid;
      else
        lo = mid + 1;
    }
    long long add = 0;
    if (lo)
      add = vm[lo-1].sum + 1LL * (vm[lo-1].from - from) * vm[lo].maks;
    else
      add = 1LL * (n - from) * vm[lo].maks;
    ans += add;
  }
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
