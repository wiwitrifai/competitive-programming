#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

long long a[N], m, ha, hb;
int n;
bool ok[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lld", a+i);
  scanf("%lld %lld %lld", &m, &ha, &hb);
  vector< long long > p;
  ok[0] = 1;
  for (int i = 0; i < n; i++) {
    p.push_back(a[i]+ha);
    p.push_back(a[i]+hb);
    p.push_back(a[i]-hb+m);
    p.push_back(a[i]-ha+m);
    p.push_back(a[i]);
    if (i)
      ok[i] = a[i] - a[i-1] <= hb && a[i]-a[i-1] >= ha;
  }
  ok[n] = 1;
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  int l = 0, r = -1;
  long long ans = 0;
  int cnt = 0;
  long long ma = -1;
  for (int i = 0; i < p.size(); i++) {
    while (r+1 < n && a[r+1] < p[i]) {
      r++;
      cnt += !ok[r];
    }
    while (l <= r && a[l] >= p[i]-m) {
      l++;
      cnt -= !ok[l];
    }
    long long front = r == -1 ? m : p[i] - a[r];
    long long back = l < n ? min(m, a[l] - p[i] + m) : m;
    if (cnt <= 0 && front <= hb && front >= ha && back <= hb && back >= ha){
      if (ma < r-l+1) {
        ans = p[i] - m;
        ma = r-l+1;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}