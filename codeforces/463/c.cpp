#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int p[N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; ++i)
        p[i] = i+1;
  for (int i = 0; i * a <= n; ++i) {
    int sisa = n - i * a;
    if (sisa % b) continue;
    for (int j = 0; j < i; ++j)
      p[(j+1) * a - 1] = j * a;
    int offset = i * a;
    int z = sisa / b;
    for (int j = 0; j < z; ++j)
      p[offset + (j+1) * b - 1] = offset + j * b;
    for (int j = 0; j < n; ++j) {
      printf("%d%c", p[j] + 1, j == n-1 ? '\n' : ' ');
    }
    return 0;
  }
  puts("-1");
  return 0;
}