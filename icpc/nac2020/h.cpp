#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5, inf = 1e9 + 7;

char buffer[N];

string cek(string & a, string & b) {
  string res = string(a.size(), 'A');
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] == b[i])
      return "";
    res[i] = 'D' - ((a[i] - 'A') + (b[i] - 'A'));
  }
  return res;
}

int n;
int calc(int x, int y) {
  if (x * y >= 0) {
    return max(abs(x), abs(y));
  }
  return abs(x) + abs(y);
}

int try_all(int x, int y) {
  return min(min(calc(x, y), calc(x, -(n-y))), min(calc(-(n-x), y), calc(-(n-x), -(n-y))));
}

int main() {
  scanf("%s", buffer);
  string a = buffer;
  scanf("%s", buffer);
  string b = buffer;
  scanf("%s", buffer);
  string c = buffer;
  n = a.size();
  vector<pair<string, int>> va;
  for (int i = 0; i < n; ++i) {
    string cur = a.substr(i, n - i) + a.substr(0, i);
    string res = cek(cur, b);
    if (res.empty()) continue;
    va.emplace_back(res, i);
  }
  vector<pair<string, int>> vb;
  for (int i = 0; i < n; ++i) {
    string cur = c.substr(i, n-i) + c.substr(0, i);
    vb.emplace_back(cur, i);
  }
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  int l = 0, r = 0;
  int ans = inf;
  for (auto it : va) {
    while (r < (int)vb.size() && vb[r].first <= it.first) ++r;
    while (l < r && vb[l].first < it.first) ++l;
    for (int i = l; i < r; ++i) {
      ans = min(ans, try_all(it.second, vb[i].second));
    }
  }
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}
