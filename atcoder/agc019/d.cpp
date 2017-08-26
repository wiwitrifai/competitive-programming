#include <bits/stdc++.h>

using namespace std;

const int N = 2017;

char a[N], b[N];
char x[N];
pair<int, int > ve[N];

int main() {
  scanf("%s", a);
  scanf("%s", b);
  int n = strlen(a);
  int ans = 1e8;
  for (int sl = -n; sl <= n; sl++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      x[i] = a[(i+n-sl) % n];
      cnt += x[i] != b[i];
      ve[i] = make_pair(-1e8, 1e8);
    }
    if (cnt == 0)
      ans = min(ans, abs(sl));
    int last = -1;
    for (int i = 0; i < 3 * n; i++) {
      if (b[i % n] == '1')
        last = i;
      if (x[i % n] != b[i % n]) {
        if (last == -1) continue;
        ve[i % n].first = max(min(last - i + sl, 0), ve[i % n].first);
      }
    }

    last = -1;
    for (int i = 3 * n; i >= 0; i--) {
      if (b[i % n] == '1')
        last = i;
      if (x[i % n] != b[i % n]) {
        if (last == -1) continue;
        ve[i % n].second = min(max(last - i + sl, 0), ve[i % n].second);
      }
    }
    vector<pair<int, int > > vv;
    for (int i = 0; i < n; i++) if (b[i] != x[i])
      vv.push_back(ve[i]);
    sort(vv.begin(), vv.end());
    int ri = max(0, sl);
    for (int le = -n, j = 0; le <= min(sl, 0); le++) {
      while (j < vv.size() && vv[j].first < le) ri = max(ri, vv[j].second), j++;
      ans = min(ans, cnt + ri-le + ri - le -abs(sl));
    }
  }
  if (ans >= 1e8)
    ans = -1;
  printf("%d\n", ans);
  return 0;
}