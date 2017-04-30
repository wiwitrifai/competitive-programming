#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d%s", &n, s);
    for (int i = n-1, j = 0; i >= 0; i--, j += 2) {
      int k = s[i]-'0';
      b[j] = b[j+1] = 0;
      if (k & 1) b[j] = 1;
      if (k & 2) b[j+1] = 1;
    }
    n = 2 * n;
    while (n > 0 && !b[n-1]) n--;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (b[i])
        printf("%d", cnt), cnt = 1;
      else
        cnt++;
    }
    printf("\n");
  }
  return 0;
}