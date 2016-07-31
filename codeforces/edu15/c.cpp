#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

long long a[N], b[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++)
    scanf("%I64d", a+i);
  for(int i = 0; i<m; i++)
    scanf("%I64d", b+i);
  long long l = 0, r = 2e9 + 7;
  while(l < r) {
    long long mid = (l+r)>>1;
    bool ok = true;
    int now = 0;
    for(int i = 0; i<n; i++) {
      while(now < m && (b[now] + mid < a[i])) now++;
      if(now >= m || a[i]+mid < b[now]) {
        ok = false;
        break;
      }
    }
    if(ok)
      r = mid;
    else
      l = mid+1;
  }
  printf("%I64d\n", r);
  return 0;
}