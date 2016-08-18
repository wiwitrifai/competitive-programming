#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
const long double pi = acos(-1);

pair< long double, int > v[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int xx, yy;
    scanf("%d %d", &xx, &yy);
    long double len = sqrt(xx * xx + yy * yy);
    long double angle = asin((long double)xx/len);
    if (angle < 0)
      angle += 2 * pi;
    if (yy / len < 0)
      angle = 3 * pi - angle;
    if (angle > 2 *pi)
      angle -= 2 * pi;
    v[i] = {angle, i+1};
  }
  sort(v,v+n);
  int a, b;
  a = v[n-1].second;
  b = v[0].second;
  long double now = v[0].first + 2 * pi - v[n-1].first;
  for (int i = 0; i < n-1; i++) {
    long double cur = v[i+1].first - v[i].first;
    if (now > cur) {
      now = cur;
      a = v[i].second;
      b = v[i+1].second;
    }
  }

  printf("%d %d\n", a, b);
  return 0;
}