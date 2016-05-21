#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int prim[N];

int main() {
  for(int i = 2; i<N; i++) if(prim[i] == 0) {
    prim[i] = i;
    for(long long j = 1LL*i*i; j<N; j+= i)
      if(prim[j] == 0)
        prim[j] = i;
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int x = 0;
    while(n > 1) {
      n /= prim[n];
      x++;
    }
    if(x == k)
      puts("Ya");
    else
      puts("Tidak");
  }
  return 0;
}