#include <bits/stdc++.h>

using namespace std;

const int N = 3e6 + 6;

int a[N];
long long mul[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  for(int i = 1; i<N; i++) if(a[i]) {
    for(int j = 1; 1LL*i*j<N; j++) {
      long long cnt = 0;
      if(j == i)  
        cnt = 1LL* a[i] * (a[i]-1);
      else
        cnt = 1LL* a[i] * a[j];
      mul[i*j] += cnt;
    }
  }
  for(int i = 1; i<N; i++) {
    mul[i] += mul[i-1];
  }
  int m;
  scanf("%d", &m);
  long long all = 1LL * n * (n-1);
  while(m--) {
    int p;
    scanf("%d", &p);
    printf("%I64d\n", all - mul[p-1]);
  }
  return 0;
}