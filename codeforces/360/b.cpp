#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int bs[N], pp[N], n, k;
int main() {
  bs[0] = bs[1] = 1;
  for(int i= 2; i<N; i++) if(bs[i] == 0) {
    bs[i] = i;
    for(long long j = 1LL*i*i; j<N; j+= i)
      if(bs[j] == 0)
        bs[j] = i;
  }
  scanf("%d%d", &n, &k);
  memset(pp, 0, sizeof pp);
  while(n--) {
    int x;
    scanf("%d", &x);
    while(x > 1) {
      int p = bs[x];
      int cnt = 0;
      while((x % p) == 0) {
        cnt++;
        x /= p;
      }
      pp[p] = max(pp[p], cnt);
    }
  }
  bool ok = true;
  while(k > 1) {
    int p = bs[k];
    int cnt = 0;
    while((k % p) == 0) {
      cnt++;
      k /= p;
    }
    if(pp[p] < cnt) {
      ok = false;
      break;
    }
  }
  puts(ok ? "Yes" : "No");

  return 0;
}