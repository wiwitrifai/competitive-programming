#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

bool composite[N];
int ans[N];

int main() {
  for (int i = 2; i < N; ++i) {
    if (composite[i]) continue;
    for (int j = i+i; j < N; j += i) {
      composite[j] = 1;
    }
  }
  for (int i = 2; i < N; ++i) {
    ans[i] = ans[i-1] + !composite[i];
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n]);
  }
  return 0;
}
