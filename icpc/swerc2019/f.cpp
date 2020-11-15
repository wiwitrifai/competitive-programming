#include <bits/stdc++.h>

using namespace std;

long long area(vector<pair<int, int>> polygon) {
  if (polygon.empty()) return 0;
  long long ret = 0;
  polygon.push_back(polygon[0]);
  for (int i = 0; i+1 < (int)polygon.size(); ++i) {
    pair<int, int> a = polygon[i], b = polygon[i+1];
    ret += 1LL * a.first * b.second - 1LL * a.second * b.first;
  }
  return abs(ret);
}

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  while (n--) {
    int p;
    scanf("%d", &p);
    vector<pair<int, int>> polygon(p);
    for (int i = 0; i < p; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      polygon[i] = make_pair(x, y);
    }
    ans += area(polygon);
  }
  ans /= 2;
  printf("%lld\n", ans);
  return 0;
}
