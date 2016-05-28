#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int len[N], ans[N];

int main() {
  for(int m = 1; m*m < N; m++) {
    int now = 2*m*m;
    for(int n = 1; n < m; n++) {
      now += 2*m;
      if(now >= N)
        break;
      if(((n & 1) && (m & 1)) || gcd(n, m) > 1)
        continue;
      len[now]++;
    }
  }
  for(int i = N-1; i>=12; i--) if(len[i]) {
    for(int j = i+i; j<N; j+= i)
      len[j] += len[i];
  }
  for(int i = 12; i<N; i++) {
    ans[i] = ans[i-1] + (len[i] == 1);
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n]);
  }
  return 0;
}