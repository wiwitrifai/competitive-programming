#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, s, t;
    scanf("%d %d %d", &n, &s, &t);
    int dua = s + t - n;
    printf("%d\n", max(s, t) - dua + 1);
  }
  return 0;
}
