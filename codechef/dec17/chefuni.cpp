#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9 + 7;

int a, b, c;
int x, y, z;

int get(int nc) {
  if (nc < 0) return inf;
  vector<int> v = {x - nc, y - nc, z - nc};
  sort(v.begin(), v.end());
  if (v[0] < 0) return inf;
  int sum = v[0] + v[1] + v[2];
  if (2 * a <= b) {
    return sum * a + nc * c;
  }
  int na = sum, nb = 0;
  if (v[2] >= v[0] + v[1])
    nb = v[0] + v[1], na = sum - nb * 2;
  else
    nb = sum/2, na = sum - nb * 2;
  return na * a + nb * b + nc * c;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d %d %d %d", &x, &y, &z, &a, &b, &c);
    int lo = 0, hi = min(x, min(y, z))/2;
    int ans = inf;
    while (lo + 2 < hi) {
      int le = (lo + lo + hi) / 3, ri = (lo + hi + hi) / 3;
      int vle = get(le * 2), vri = get(ri * 2);
      ans = min(ans, min(vle, vri));
      if (vle < vri)
        hi = ri;
      else
        lo = le;
    }
    for (int i = lo * 2; i <= hi * 2; i++)
      ans = min(ans, get(i));
    lo = 0, hi = (min(x, min(y, z))-1)/2;
    while (lo + 2 < hi) {
      int le = (lo + lo + hi) / 3, ri = (lo + hi + hi) / 3;
      int vle = get(le * 2 + 1), vri = get(ri * 2 + 1);
      ans = min(ans, min(vle, vri));
      if (vle < vri)
        hi = ri;
      else
        lo = le;
    }
    for (int i = lo * 2 + 1; i <= hi * 2 + 1; i++)
      ans = min(ans, get(i));
    printf("%d\n", ans);
  }
  return 0;
}