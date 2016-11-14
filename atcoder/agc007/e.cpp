#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 6;
 
char s[N], t[N];
 
int bit[N], m;
 
void upd(int x, int v) {
  for (; x <= m; x += x & (-x))
    bit[x] += v; 
}
int get(int x) {
  int ret = 0;
  for (; x; x -= x & (-x))
    ret += bit[x];
  return ret;
}
 
int main() {
  int n;
  scanf("%d %s %s", &n, s, t);
  vector< pair<int, int > > id;
  int j = n-1;
  bool ok = true;
  for (int i = n-1; i >= 0;) {
    // cerr << i << " " << endl;
    char now = t[i];
    int last = i;
    while (i >= 0 && t[i] == now) i--;
    j = min(i+1, j);
    // cerr << i << " " << j << endl;
    while (j >= 0 && now != s[j]) j--;
    // cerr << i << " " << j << endl;
    if (j < 0 || now != s[j]) { 
      ok = false;
      break;
    }
    id.push_back({j, last});
    // cerr << j << " | " << last << endl;
    j--;
  }
  m = id.size() + 2;
  if (!ok)
    puts("-1");
  else {
    reverse(id.begin(), id.end());
    int ans = 0;
    int last = id.size();
    for (int i = (int)id.size()-1; i >= 0; i--) {
      int l = i, r = last;
      int from = id[i].first, to = id[i].second;
      while (l < r) {
        int mid = (l + r) >> 1;
        int antre = id[mid].first - get(mid+1);
        if (antre >= to)
          r = mid;
        else
          l = mid + 1;
      }
      // cerr << i << " " << l << endl;
      ans = max(ans, l-i);
      last = l;
      upd(i+1, +1);
      upd(l+2, -1);
    }
    printf("%d\n", ans);
  }
  return 0;
}