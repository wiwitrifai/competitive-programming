#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

bitset< N > isprim;

int a[N];

int main() {
  isprim.set();
  isprim[1] = 0;
  for (int i = 2; i < N; i++) if(isprim[i]) {
    for(long long j = 1LL * i * i; j < N; j += i)
      isprim[j] = 0;
  }
  int n;
  scanf("%d", &n);
  int add1 = 0, val1;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    if(a[i] > 1 && isprim[a[i]+1]) {
      add1 = 1;
      val1 = a[i];
    }
    if(a[i] == 1)
      cnt++;
  }
  if(cnt + add1 > 2) {
    printf("%d\n", cnt + add1);
    for(int i = 0; i<cnt; i++)
      printf("1 ");
    if(add1)
      printf("%d", val1);
    printf("\n");
  }
  else {
    for(int i = 0; i<n; i++) {
      for(int j = i+1; j<n; j++) if(isprim[a[i]+a[j]]) {
        printf("2\n%d %d\n", a[i], a[j]);
        return 0;
      }
    }
    printf("1\n%d\n", a[0]);
  }
  
  return 0;
}