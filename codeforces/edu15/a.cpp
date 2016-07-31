#include <bits/stdc++.h>

using namespace std;

const int N =1e5 + 5;

int n, a[N];

int main() {
  scanf("%d", &n);
  for(int i= 0; i<n; i++)
    scanf("%d", a+i);
  int ans = 1, tmp = 1;
  for(int i= 1; i<n; i++) {
    if(a[i] > a[i-1])
      tmp++;
    else
      tmp = 1;
    ans = max(ans, tmp);
  }

  printf("%d\n", ans);
  return 0;
}