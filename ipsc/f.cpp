#include <bits/stdc++.h>

using namespace std;

long long mul(long long a, long long b, long long mod) {
  long long ret = 0;
  while(b) {
    if(b & 1)
      ret = (ret + a) % mod;
    a = (a << 1) % mod;
    b >>= 1;
  }
  return ret;
}

const int N = 1e6 + 5;
char ans[N];
int m;

int main() {
  int t;
  long long n, a, b;
  int k;
  scanf("%d", &t);
  while(t--) {
    scanf("%lld%lld%d", &n, &a, &k);
    a--;
    m = 0;
    for(int i = 1; i<=k; i++) {
      scanf("%lld", &b);
      b--;
      if(a == b)
        continue;
      long long tmp = a;
      long long pw = 1;
      int p  = 0;
      long long c = b/2;
      for(p = 0; p<64; p++) {
        long long res = (c - a) % n;
        if(res < 0)
          res += n;
        if(res < pw)
          break;
        a = (a << 1) % n;
        pw <<= 1;
      }
      long long res = (c - a) % n;
      if(res < 0)
        res += n;
      long long last = tmp;
      for(int j = p-1; j>=0; j--) {
        if((res >> j) & 1) {
          ans[m++] = (last >= n) ? 'R' : 'L';
          last = (last % n) * 2 + 1;
        }
        else {
          ans[m++] = (last >= n) ? 'L' : 'R';
          last = (last % n) * 2;
        }
      }
      if(last != b) {
        if((last % n) * 2 == b) {
          ans[m++] = (last >= n) ? 'L' : 'R';
        }
        else {
          ans[m++] = (last >= n) ? 'R' : 'L';
        }
      }
      a = b;
    }
    ans[m] = '\0';
    printf("%d:%s\n", m, ans);
    cerr << t << " completed!\n";
  }
  return 0;
}