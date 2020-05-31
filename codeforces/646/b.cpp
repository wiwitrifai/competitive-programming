#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int one = 0;
    for (int i = 0; i < n; ++i)
      one += s[i] == '1';
    int cone = 0;
    int ans = min(one, n - one);
    for (int i = 0; i < n; ++i) {
      cone += s[i] == '1';
      int lone = cone, lzero = i+1 - cone;
      int rone = one - lone, rzero = n-i-1 - rone;
      ans = min(ans, min(lone + rzero, lzero + rone));
    }
    printf("%d\n", ans);
  }
  return 0;
}
