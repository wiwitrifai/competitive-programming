#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

vector<int> le, ri;
vector<long long> r1, r2;

int main() {
  int n, l, w;
  scanf("%d %d %d", &n, &l, &w);
  for (int i = 0; i < n; ++i) {
    int x, v;
    scanf("%d %d", &x, &v);
    if (v == 1)
      ri.push_back(x + l);
    else
      le.push_back(x);
  }
  sort(ri.begin(), ri.end());
  r1.clear(); r2.clear();
  for (int x : ri) {
    r1.push_back(1LL * x * (w-1));
    r2.push_back(1LL * x * (w+1));
  }
  for (int x : r1)
    cerr << x << " w ";
  for (int x : r2)
    cerr << x << " y ";
  cerr << endl;
  long long ans = 0;
  for (int x : le) {
    int y = x + l;
    if (y < 0 && w == 1) continue;
    if (x > 0) {
      long long st = x * (w + 1) - 2 * x;
      cerr << x << " " << st << endl;
      ans += lower_bound(r2.begin(), r2.end(), st) - r2.begin();
    }
    else if (y < 0) {
      long long st = x * (w - 1) - 2 * -y;
      cerr << y << " " << st << endl;
      ans += lower_bound(r1.begin(), r1.end(), st) - r1.begin();
    }
    else
      ans += ri.size();
    cerr << ans << endl;
  }
  printf("%d\n", ans);
  return 0;
}