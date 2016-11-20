#include <bits/stdc++.h>

using namespace std;
const int N = 101;
bitset< N * N * N > bs[N];

int main() {
  for (int n = 1; n < N; n++) {
    int nn = n * n * n;
    for (long long i = 0; i < nn; i++) {
      int r = (i * i * i) % nn;
      bs[n][r] = 1; 
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int k, c;
    scanf("%d %d", &k, &c);
    int kkk = k * k * k;
    c = (kkk - c) % kkk;
    puts(bs[k][c] ? "YES" : "NO");  
  }
  return 0;
}