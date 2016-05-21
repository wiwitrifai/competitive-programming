#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int p[N];
int n, k;
bool cek(long long po) {
  long long g, pw, cnt;
  g = pw = cnt = 0;
  for(int i = 0; i<n; i++) {
    if(pw < p[i])
      pw = p[i];
    cnt++;
    if(pw*cnt > po) {
      g++;
      if(g >= k)
        return false;
      pw = p[i];
      cnt = 1;
    }
  }
  return g < k;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    long long l, r;
    scanf("%d%d", &n, &k);
    l = 0;
    r = 0;
    for(int i = 0; i<n; i++) {
      scanf("%d", p+i);
      r += p[i];
      if(p[i] > l)
        l = p[i];
    }
    r *= n;
    while(l < r) {
      long long mid = (l+r)/2;
      if(cek(mid))
        r = mid;
      else
        l = mid+1;
    }
    printf("%I64d\n", r);
  }
  return 0;
}