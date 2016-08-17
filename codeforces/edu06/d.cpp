#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 6;

int a[N], b[N];
pair<long long, pair<int, int> > c[N];

int main() {
  long long suma = 0, sumb = 0;
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    suma += a[i];
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", b+i);
    sumb += b[i];
  }
  long long ans = abs(suma - sumb);
  int k = 0, p, q, r, s;
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j++) {
      long long cur = abs(suma - sumb + 2LL * ((long long)b[j] - (long long)a[i]));
      if (cur < ans) {
        ans = cur;
        k = 1;
        p = i+1, q = j+1;
      }
    }
  }
  int z = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      c[z++] = {2LL * ((long long)a[i] + (long long)a[j]), {i+1, j+1}};
    }
  }
  sort(c, c+z);
  for (int i = 0; i < m; i++) {
    for (int j = i+1; j < m; j++) {
      long long cur = suma - sumb + 2LL * ((long long)b[i]+(long long)b[j]);
      auto it = lower_bound(c, c+z, make_pair(cur, make_pair(-1, -1)));
      if (it != c+z) {
        // cerr << i << " " << j << " " << cur << " " << it->first << " " << ans << endl; 
        if (abs(cur - it->first) < ans) {
          ans = abs(cur - it->first);
          k = 2;
          p = it->second.first; q = i+1;
          r = it->second.second; s = j+1;
        }
      }
      if (it != c) {
        it--;
        // cerr << i << " " << j << " " << abs(cur - 2LL*it->first) << " " << ans << endl;
        if (abs(cur - it->first) < ans) {
          ans = abs(cur - it->first);
          k = 2;
          p = it->second.first; q = i+1;
          r = it->second.second; s = j+1;
        }
      }
    }
  }
  cout << ans << endl;
  cout << k << endl;
  if (k)
    cout << p << " " << q << endl;
  if (k > 1)
    cout << r << " " << s << endl;
  return 0; 
}