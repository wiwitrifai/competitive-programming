#include <bits/stdc++.h>

using namespace std;

int a[8];

char s[7][20] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" , "Sunday"}; 

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long k;
    scanf("%lld", &k);
    long long sum = 0;
    for (int i = 0; i < 7; ++i)
      scanf("%d", a+i), sum += a[i];
    long long z = (max(k - sum, 0LL))/sum;
    k -= sum * z;
    int ans = 6;
    while (k > 0) {
      ans = (ans + 1) % 7;
      k -= a[ans];
    }
    printf("%s\n", s[ans]);
  }
  return 0;
}