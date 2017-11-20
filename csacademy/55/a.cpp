#include <bits/stdc++.h>

using namespace std;

const int N = 111;
int t[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++)
    scanf("%d", t+i);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0;
    for (int j = 0; j < m; j++)
      ans += t[j] <= b && t[j] >= a;
    printf("%d\n", ans);
  }
  return 0;
}