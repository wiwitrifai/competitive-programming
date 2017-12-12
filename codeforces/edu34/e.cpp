#include <bits/stdc++.h>

using namespace std;

const int N = 5050;


bool cek(string& a, string& b, bool sama) {
  int cnt = 0;
  int fi = -1, se = -1;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == b[i]) continue;
    if (cnt)
      se = i;
    else
      fi = i;
    ++cnt;
  }
  if (cnt == 0)
    return sama;
  if (cnt == 2)
    return (a[fi] == b[se] && a[se] == b[fi]);
  return false;
}

string s[N];
int cnt[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k, n;
  cin >> k >> n;
  for (int i = 0; i < k; ++i)
    cin >> s[i];
  s[k] = s[0];
  vector<int> id;
  string p;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] != s[i+1][j])
        id.push_back(j);
    }
    if (!id.empty()) {
      p = s[i];
      break;
    }
  }
  if (id.empty()) {
    swap(s[0][0], s[0][1]);
    cout << s[0] << endl;
    return 0;
  }
  if (id.size() > 4) {
    cout << -1 << endl;
    return 0;
  }
  bool same = 0;
  for (int i = 0; i < n; ++i)
    cnt[s[0][i]]++;
  for (int i = 0; i < 256; ++i)
    same |= cnt[i] > 1;
  for (int x : id) {
    for (int i = 0; i < n; ++i) {
      if (x == i) continue;
      swap(p[x], p[i]);
      bool ok = 1;
      for (int j = 0; j < k && ok; j++) {
        ok &= cek(p, s[j], same);
      }
      if (ok) {
        cout << p << endl;
        return 0;
      }
      swap(p[x], p[i]);
    }
  }
  puts("-1");
  return 0;
}