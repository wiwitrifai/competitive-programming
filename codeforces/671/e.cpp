#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

void solve() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> fp;
  for (int i = 2; 1LL * i * i <= n; ++i) {
    if (n % i) continue;
    n /= i;
    int cnt = 1;
    while ((n % i) == 0) {
      ++cnt;
      n /= i;
    }
    fp.emplace_back(i, cnt);
  }
  if (n > 1)
    fp.emplace_back(n, 1);
  vector<int> ans;
  ans.push_back(1);
  for (int j = 0; j < (int)fp.size(); ++j) {
    int p = fp[j].first, c = fp[j].second;
    int sz = ans.size();
    int nowp = 1;
    while (c--) {
      nowp *= p;
      for (int i = 0; i < sz; ++i) {
        ans.push_back(ans[i] * nowp);
      }
    }
    if (j > 0) {
      for (int k = sz; k < (int)ans.size(); ++k) {
        if (ans[k] % fp[j-1].first) continue;
        swap(ans[sz], ans[k]);
        break;
      }
    }
  }
  if (fp.size() > 1) {
    for (int k = (int)ans.size()-1; k >= 0; --k) {
      if (ans[k] % fp[0].first) continue;
      swap(ans[k], ans.back());
      break;
    }
  }
  reverse(ans.begin(), ans.end());
  ans.pop_back();
  for (int i = 0; i < (int)ans.size(); ++i)
    printf("%d%c", ans[i], i+1 == (int)ans.size() ? '\n' : ' ');
  int cans = gcd(ans[0], ans.back()) == 1;
  for (int i = 0; i + 1 < (int)ans.size(); ++i)
    cans += gcd(ans[i], ans[i+1]) == 1;
  printf("%d\n", cans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
