#include <bits/stdc++.h>

using namespace std;

int ans[] = {13, 23, 291, 576, 4895, 9261, 67163, 127597, 850659};

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n - 1]);
  }

  return 0;
}