#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int isperfect[N];

int main() {
  for (int i = 0; i < N; ++i) {
    int y = i * i;
    if (y >= N) break;
    isperfect[y] = 1;
  }
  int n;
  scanf("%d", &n);
  int ans = -1e9;
  for (int i = 0;i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a < 0)
      ans = max(ans, a);
    else {
      if (!isperfect[a])
        ans = max(ans, a);
    }
  }
  printf("%d\n", ans);

  return 0;
}