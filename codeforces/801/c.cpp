#include <bits/stdc++.h>

using namespace std;
const int N = 1002;

bitset<N> bs[N];
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  int len = n + m - 1;
  if (len & 1) {
    cout << "NO\n";
    return;
  }
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    bs[i].reset();
    cnt += (a[0][i] == 1);
    bs[i][cnt] = 1;

  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 1) {
        bs[j] = bs[j] << 1;
      }
      if (j < m) {
        bs[j+1] = bs[j+1] | bs[j];
      }
    }
  }
  cout << (bs[m-1][len/2] ? "YES\n" : "NO\n");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
