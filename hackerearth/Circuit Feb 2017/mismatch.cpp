#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;

char s[N], p[N];

int main() {
  int k;
  scanf("%d", &k);
  scanf("%s", s);
  int len = strlen(s);
  int n;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", p);
    int m = strlen(p);
    int ans = 0;
    for (int i = 0; i + m <= len; i++) {
      int j = 0;
      while (j < m && s[i+j] == p[j]) j++;
      j += k;
      while (j < m && s[i+j] == p[j]) j++;
      ans += j >= m;
    }
    printf("%d\n", ans);
  }
  return 0;
}