#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 6;
int id[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int ans = 0, ans1 = 0;
  for (int i = 1; i <= k; i++) {
    int a;
    scanf("%d", &a);
    if (id[a]) {
      printf("%d %d\n", id[a], i);
      return 0;
    }
    id[a] = i;
  }
  for (int i = 1; i <= n; i++) if (id[i]) {
    for (int j = i+i; j <= n; j += i) if (id[j]) {
      printf("%d %d\n", id[i], id[j]);
      return 0;
    }
  }
  puts("0 0");
  return 0;
}