#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

long long x[N], y[N];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%lld", x+i);
  for(int i = 0; i<n; i++)
    scanf("%lld", y+i);
  sort(x, x+n);
  sort(y, y+n);
  long long ans = 0, save = 0;
  for(int i = 0; i<n; i++) {
    save += x[i] - y[i];
    ans += max(x[i]-y[i], 0LL);
  }
  if(save){
    puts("-1");
    return 0;
  }
  printf("%lld\n", ans);
  return 0;
}