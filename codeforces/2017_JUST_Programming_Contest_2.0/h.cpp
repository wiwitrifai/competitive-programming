#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, ans[N], last[55];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  for (int i = 0; i < 55; i++)
    last[i] = n;
  a[n] = -1;
  for (int i = n-1; i >= 0; i--) {
    int id = n;
    for (int j = a[i]+1; j <= 50; j++)
      id = min(id, last[j]);
    ans[i] = a[id];
    last[a[i]] = i;
  }
  for (int i = 0; i < n; i++)
    printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
  return 0;
}