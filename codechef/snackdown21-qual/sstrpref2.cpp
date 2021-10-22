#include <bits/stdc++.h>

using namespace std;

// b[i] = max len so that b[i] < i+1 and s[0..len-1] = s[i-len+1..i]
vector<int> prekmp(const string& s) {
  int n = s.size();
  vector<int> b(n, 0);
  for (int i = 1; i < n; ++i) {
    int j = b[i-1];
    while (j > 0 && s[i] != s[j]) j = b[j - 1];
    if (s[i] == s[j])
      ++j;
    b[i] = j;
  }
  return b;
}

vector<int> kmp(const string& s, const string& p, const vector<int>& b) {
  int n = s.size(), m = p.size();
  vector<int> ans(n);
  int len = 0;
  for (int i = 0; i < n; ++i) {
    while (len > 0 && p[len] != s[i]) len = b[len-1];
    if (s[i] == p[len])
      ++len;
    ans[i] = len;
    if (len == m) {
      len = b[len-1];
    }
  }
  return ans;
}

// z[i] = max len so that s[0..len-1] = s[i..i+len-1]
vector<int> zstring(const string& s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (r <= i) {
      l = r = i;
      while (r < n && s[r] == s[r-l]) ++r;
      z[i] = r-l;
    } else {
      if (i + z[i-l] < r)
        z[i] = z[i-l];
      else {
        l = i;
        while (r < n && s[r] == s[r-l]) ++r;
        z[i] = r-l;
      }
    }
  }
  z[0] = n;
  return z;
}

void solve() {
  string a, b, x;
  cin >> a >> b >> x;
  auto p = prekmp(a);
  auto suf = kmp(x, a, p);
  auto z = zstring(b + x);
  int m = b.size();
  vector<int> best(a.size()+1, -1);
  for (int i = -1; i < (int)x.size(); ++i) {
    int lef = (i >= 0) ? suf[i] : 0;
    int rig = (i + 1 < (int)x.size()) ? min(z[i+1+m], m) : 0;
    best[lef] = max(best[lef], rig);
  }
  long long ans = 0;
  for (int i = (int)a.size(); i >= 0; --i) {
    ans += best[i] + 1;
    if (i > 0) {
      best[p[i-1]] = max(best[p[i-1]], best[i]);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
