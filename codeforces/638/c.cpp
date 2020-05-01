#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    sort(s, s+n);
    if (s[0] != s[k-1] || k == n) {
      printf("%c\n", s[k-1]);
    }
    else {
      if (s[k] == s[n-1]) {
        int cnt = n - k;
        printf("%c", s[k-1]);
        cnt = (cnt + k-1) / k;
        for (int i = 0; i < cnt; ++i)
          printf("%c", s[k]);
        printf("\n");
      }
      else {
        printf("%s\n", s+k-1);
      }
    }
  }
  return 0;
}
