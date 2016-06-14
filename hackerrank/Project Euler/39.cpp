#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 6;

int cnt[N], ans[N];

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  for(int m = 1; m*m < N; m++) {
    for(int now = 2*m*(m+1), n = 1; now < N && n < m; now += 2*m, n++) {
      if(gcd(n, m) > 1 || ((n & 1) && (m & 1)))
        continue;
      cnt[now]++;
    }
  }
  for(int i = N-1; i>1; i--) if(cnt[i]) {
    for(int j = i + i; j<N; j+= i)
      cnt[j] += cnt[i];
  }
  int now = 0;
  for(int i = 2; i<N; i++) {
    if(cnt[now] < cnt[i]) {
      now = i;
    }
    ans[i] = now;
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