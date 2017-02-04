#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 20) + 8;
int n, a[N], b[N];

int main() {
  scanf("%d", &n);
  int m = 1 << n;
  for (int i = 0; i < m; i++)
    scanf("%d", a+i), b[i] = a[i];
  map< int, int > ans;
  sort(b, b+m);
  int lv = 0;
  for (int i = 0; i < m; i++) {
    int now = b[i];
    if ((1<<(lv+1)) <= (i+1))
      lv++;
    ans[now] = n-lv;
  }
  for (int i = 0; i < m; i++)
    printf("%d ", ans[a[i]]);
  printf("\n");
  return 0;
}