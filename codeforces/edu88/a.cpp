#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int s = n / k;
    int hig = min(m, s);
    int low = max(0, (m - hig + (k-1) - 1) / (k-1));
    printf("%d\n", hig - low);
  }
  return 0;
}

