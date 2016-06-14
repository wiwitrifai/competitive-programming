#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
bitset< N > bs;
int main() {
  int n; 
  long long sum = 0;
  scanf("%d", &n);
  bs.set();
  bs[0] = bs[1] = 0;
  for(int i = 2; i<=n; i++) if(bs[i]) {
    for(long long j = 1LL*i*i; j<=n; j+= i)
      bs[j] = 0;
    if(i < 10)
      continue;
    bool ok = true;
    int b = i;
    while(b) {
      ok &= bs[b];
      b /= 10;
    }
    b = 10;
    while(b <= i) {
      ok &= bs[i % b];
      b *= 10;
    }
    if(ok)
      sum += i;
  }
  cout << sum << endl;
  return 0;
}