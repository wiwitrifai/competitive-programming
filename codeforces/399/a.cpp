#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int ma = a[0], mi = a[0];
  for (int i= 0;i < n; i++)
    ma = max(ma, a[i]), mi= min(mi, a[i]);
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += (a[i] < ma && a[i] > mi);
  printf("%d\n", ans);
  return 0;
}