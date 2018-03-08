#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
string s[55];
int b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<vector<int>, int> > sorted;
  for (int i = 0; i < k; ++i) {
    cin >> s[i];
    int len = s[i].size();
    fill(b, b+len, 0);
    for (int j = 1; j < len; ++j) {
      int z = b[j-1];
      while (z > 0 && s[i][z] != s[i][j]) z = b[z-1];
      if (s[i][z] == s[i][j]) {
        b[j] = z+1;
      }
    }
    vector<int> res;
    int z = b[len-1];
    while (z > 0 && 2 * len - z <= n) {
      res.push_back(z);
      z = b[z-1];
    }
    sorted.emplace_back(res, i);
  }
  sort(sorted.begin(), sorted.end());
  for (int i = 0; i < k; ++i)
    cout << s[sorted[i].second] << "\n";
  return 0;
}