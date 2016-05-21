#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18 + 90LL;
int n;
long long ll, w;
long long a[N], b[N];

int main() {
  scanf("%d%lld%lld", &n, &w, &ll);
  long long l = 0, r = inf;
  for(int i = 0; i<n; i++) {
    scanf("%lld%lld", a+i, b+i);
  }
  while(l < r) {
    long long mid = (l+r)>>1;
    long double sum = 0;
    for(int i = 0; i<n; i++) {
      long double now = a[i] + (long double)b[i] * mid;
      if(now >= ll)
        sum += now;
    }
    if(sum < w)
      l = mid+1;
    else
      r = mid;
  }
  cout << l << endl;
  return 0;
}