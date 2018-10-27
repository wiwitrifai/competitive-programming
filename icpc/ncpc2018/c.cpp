#include <bits/stdc++.h>

using namespace std;

bool push[400];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    push[x] = 1;
  }
  int sum = 0, s = 0;
  int ans = 0;
  for (int i = 0; i < 370; ++i) {
    sum += s;
    if (push[i])
      ++s;
    if (sum + s >= 20) {
      ++ans;
      sum = 0;
      s = 0;
    }
  }
  if (s > 0)
    ++ans;
  printf("%d\n", ans);

  return 0;
}