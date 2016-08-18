#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], n, m;
int cnt[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i); 
    if(a[i] <= m)
      cnt[a[i]]++;
  }
  for(int i = m; i>0; i--) {
    for(int j = i+i; j<=m; j+= i)
      cnt[j] += cnt[i];
  }
  int ans = 1, cn = 0;
  for(int i = 1; i<=m; i++) {
    if(cn < cnt[i])
      ans = i, cn = cnt[i];
  }
  printf("%d %d\n", ans, cn);
  for(int i = 0; i<n; i++)
    if(ans % a[i] == 0)
      printf("%d ", i+1);
  printf("\n");
  return 0;
}