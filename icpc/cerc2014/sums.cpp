#include <cmath>
#include <bits/stdc++.h>
using namespace std;

const int N = sqrt(1e9) + 5;
vector< int > prime;
bitset< N > bs;

int main() {
  for(int i = 2; i<N; i++) if(!bs[i]) {
    prime.push_back(i);
    for(long long j = 1LL*i*i; j<N; j+=i)
      bs[j] = 1;
  }
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    int n;
    scanf("%d", &n);
    int m = n;
    int k = 2;
    while(n % 2 == 0) {
      n >>=1;
      k <<= 1;
    }
    for(int i = 1; i<prime.size() && prime[i] < k; i++) {
      if(n % prime[i] == 0) {
        if(k > prime[i]) {
          n *= k;
          n /= prime[i];
          k = prime[i];
        }
        break;
      }
    }
    if(k < n) {
      int a = (n-k+1)/2;
      printf("%d = ", m);
      for(int i = 0; i<k; i++)
        printf("%d%s", a+i, i == k-1 ? "\n" : " + ");
    }
    else
      puts("IMPOSSIBLE");
  } 
  return 0;
}
