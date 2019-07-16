#include <bits/stdc++.h>

using namespace std;

const int N = 4040;

string s[N];

bool cek(string & a, string &b) {
  for (int i = 0, j = 0; i < a.size(); ++i, ++j) {
    while (j < b.size() && a[i] != b[j]) ++j;
    if (j == b.size()) return false;
  }
  return true;
}
int dp[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cin >> s[n+1];
  s[0] = "";
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  sort(s+1, s+n+1, [](string & a, string & b) { return (a.size() == b.size()) ? a < b : a.size() < b.size(); });
  int a = 0, b = 0;
  memset(dp, -1, sizeof dp);
  dp[1][0] = 0;
  for (int i = 1; i < n; ++i) {
    if (a == b) {
      bool ca = cek(s[a], s[i+1]), cc  = cek(s[i], s[i+1]);
      if (!ca && !cc) {
        cout << "impossible\n";
        return 0;
      }
      if (cc && ca) {
        dp[i+1][i] = a;
        dp[i+1][a] = i;
        b = i;
      } else if (ca) {
        dp[i+1][i] = a;
        a = b = i;
      } else {
        dp[i+1][a] = i;
      }
    }
    else {
      bool ca = cek(s[a], s[i+1]), cb = cek(s[b], s[i+1]), cc = cek(s[i], s[i+1]);
      if (!ca && !cb && !cc) {
        cout << "impossible\n";
        return 0;
      }
      if (cc) {
        dp[i+1][a] = i;
        dp[i+1][b] = i;
      }
      else if (ca) {
        dp[i+1][i] = a;
        a = b = i;
      } else {
        dp[i+1][i] = b;
        a = b = i;
      }
    }
  }
  int u = n, v = a;
  if (!cek(s[u], s[n+1]) || !cek(s[v], s[n+1])) {
    cout << "impossible\n";
    return 0;
  }
  vector<int> pa, pb;
  while (u > 0  || v > 0) {
    if (u > v) {
      pa.push_back(u);
      u = dp[u][v];
    }
    else {
      pb.push_back(v);
      v = dp[v][u];
    }
  }
  cout << pa.size() << " " << pb.size() << "\n";
  reverse(pa.begin(), pa.end());
  reverse(pb.begin(), pb.end());
  for (int x : pa)
    cout << s[x] << "\n";
  for (int x : pb)
    cout << s[x] << "\n";
  return 0;
}