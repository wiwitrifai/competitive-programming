#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int b, p, f, h, c;
    scanf("%d %d %d %d %d", &b, &p, &f, &h, &c);
    int ans = 0;
    for (int i = 0; i * 2 <= b && i <= p; ++i) {
      int sisa = b - i * 2;
      int cnt = min(sisa/2, f);
      ans = max(ans, i * h + cnt * c);
    }
    printf("%d\n", ans);
  }
  return 0;
}
