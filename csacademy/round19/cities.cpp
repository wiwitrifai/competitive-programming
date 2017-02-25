#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, inf = 1e9 + 7;

pair< int , int > city[N];
long long sum[N];
int main() {
  int n, x, k;
  scanf("%d %d %d", &n, &x, &k);
  for (int i = 0; i < n; i++) {
    int pos, w;
    scanf("%d %d", &pos, &w);
    city[i] = {pos, w};
  }
  sort(city, city+n);
  sum[0]= 0;
  for (int i = 0; i < n; i++)
    sum[i+1] = sum[i] + city[i].second;
  long long ans = 0;
  int id = lower_bound(city, city+n, make_pair(x, inf)) - city;
  for (int i = 0; i < n; i++) {
    if (city[i].first <= x) {
      if (city[i].first + k < x)
        continue;
      ans = max(ans, sum[id] - sum[i]);
      int ri = k - (x - city[i].first) * 2;
      if (ri < 0) continue;
      ri = lower_bound(city, city+n, make_pair(x + ri, inf)) - city - 1;
      // cerr << i << " " << ri << endl;
      ans = max(ans, sum[ri+1] - sum[i]);
    }
    else {
      if (city[i].first - k > x)
        break;
      ans = max(ans, sum[i+1] - sum[id]);
      int le = k - (city[i].first - x) * 2;
      if (le < 0) continue;
      le = lower_bound(city, city+n, make_pair(x - le, 0)) - city;
      // cerr << le << " " << i << endl;
      ans = max(ans, sum[i+1] - sum[le]);
    }
  }
  printf("%lld\n", ans);
  return 0 ;
}