#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int a[N], b[N];

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char c;
    int x;
    scanf("%d %c", &x, &c);
    if (c == 'L')
      a[x]++;
    else
      b[x]++;
  }    
  for (int i = 0; i < N; i++)
    ans += min(a[i], b[i]);
  printf("%d", ans);
  return 0;
}