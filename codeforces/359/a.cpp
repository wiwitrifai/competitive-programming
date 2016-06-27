#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], b[N];

long long n, m;
int main() {
  cin >> n >> m;
  int posa = 0, posb = 0;
  long long cur = n-1, ma = 7, mb = 7;
  while(cur > 0) {
    cur /= 7;
    ma *= 7;
    posa++;
  }
  if(posa == 0)
    posa = 1;
  cur = m-1;
  while(cur > 0) {
    cur /= 7;
    mb *= 7;
    posb++;
  }
  if(posb == 0)
    posb = 1;
  if(posa > 7 || posb > 7) {
    puts("0");
    return 0;
  }
  ma = min(ma, n);
  mb = min(mb, m);
  for(int i = 0; i<ma; i++) {
    int mask = 0;
    long long cur = i;
    for(int j = 0; j<posa; j++) {
      int r = cur % 7;
      cur /= 7;
      if(mask & (1<<r)) {
        mask = -1;
        break;
      }
      else
        mask |= (1<<r);
    }
    if(mask >= 0) {
      a[mask]++;
    }
  }
  for(int i = 0; i<mb; i++) {
    int mask = 0;
    long long cur = i;
    for(int j = 0; j<posb; j++) {
      int r = cur % 7;
      cur /= 7;
      if(mask & (1<<r)) {
        mask = -1;
        break;
      }
      else
        mask |= (1<<r);
    }
    if(mask >= 0)
    b[mask]++;
  }
  int all = 1<<7;
  for(int i= all-1; i>=0; i--) {
    for(int j = (i+1) | i; j<all; j = (j+1) | i)
      a[j] += a[i];
  }
  // for(int i = 0; i<all; i++) if(a[i])
  //   cerr << i << " " << a[i] << endl;
  long long ans = 0;
  all --;
  for(int i = 0; i<=all; i++) {
    ans += a[i] * b[all^i];
  }
  cout << ans << endl;
  return 0;
}