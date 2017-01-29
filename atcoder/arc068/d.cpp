#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5 + 6;
int cnt[N];
 
int main() {
  int n;
  scanf("%d", &n);
  vector< int > v;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  bool ok = 0;
  int ans = n;
  for (int i = 0; i < v.size(); i++) {
    int x = v[i];
    // cerr << x << " " << cnt[x] << endl;
    while (cnt[x] >= 3) {
      cnt[x] -= 2;
      ans -= 2;
    }
    if (cnt[x] > 1) {
      if (ok) {
        ok = 0;
        ans -= 2;
      }
      else
        ok = 1;
    }
    // cerr << ans << endl;
  }
  if (ok)
    ans -= 2;
  printf("%d\n", ans);
  return 0;
}