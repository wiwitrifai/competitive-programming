#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int m[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n + n; i++) {
      for (int j = 0; j < n + n; j++) {
        scanf("%d", m[i]+j);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans += max(max(m[i][j], m[2 * n - i - 1][j]), max(m[i][2 * n - j - 1], m[2 * n - i - 1][2 * n - j - 1]));
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}