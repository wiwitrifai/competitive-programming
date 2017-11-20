#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
vector<string> vs;

char c[26];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int ans = 0;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vs.push_back(s);
    for (int j = 0, z = m-1; j < z; j++, z--) {
      ans += s[j] != s[z];
    }
  }
  for (int i = 0, j = m-1; i < j; i++, j--) {
    int now = 0;
    for (int p = 0, q = n-1; p < q; p++, q--) {
      memset(c, 0, sizeof c);
      c[vs[p][i]-'a']++;
      c[vs[p][j]-'a']++;
      c[vs[q][i]-'a']++;
      c[vs[q][j]-'a']++;
      int cur = 3;
      for (int z = 0; z < 26; z++)
        cur = min(cur, 4-c[z]);
      cur -= vs[p][i] != vs[p][j];
      cur -= vs[q][i] != vs[q][j];
      now += cur;
    }
    pq.push(-now);
  }
  int now = 0;
  while (now + 2 <= k) {
    now += 2;
    ans -= pq.top();
    pq.pop();
  }
  int add = inf;
  if (now < k && !pq.empty()) {
    add = min(add, -pq.top());
  }
  if (now < k && (m & 1)) {
    int mid = m/2;
    int cur = 0;
    for (int i = 0, j = n-1; i < j; i++, j--)
      cur += vs[i][mid] != vs[j][mid];
    add = min(add, cur);
  }
  if (now < k) {
    ans += add;
  }
  cout << ans << endl;
  return 0;
}