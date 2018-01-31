#include <bits/stdc++.h>

using namespace std;

const int N = 202;

int p[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", p+i), p[i]--;
  int ans = 0;
  for (int r = 0; r < n; ++r) {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      cnt += p[(i+r) % n] == i;
    ans = max(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}