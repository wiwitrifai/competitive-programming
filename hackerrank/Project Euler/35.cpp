#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7, M = 1e6 + 5;

bitset< N > bs;
int prime[M], np;

int main() {
  bs.set();
  bs[0] = bs[1] = 0;
  int cnt = 0;
  np = 0;
  for(int i = 2; i < N; i++) if(bs[i]) {
    for(long long j = 1LL*i*i; j<N; j+= i)
      bs[j] = 0;
    prime[np++] = i;
  }
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for(int i = 0; i<np; i++) {
    if(prime[i] > n)
      break;
    int p = prime[i];
    int b = 1;
    while(b * 10 <= p) b *= 10;
    int now = p;
    bool ok = true;
    do {
      int x = now % 10;
      now /= 10;
      now += x * b;
      ok &= bs[now];
    } while(now != p);
    if(ok)
      sum += now;
  }
  cout << sum << endl;
  return 0;
}