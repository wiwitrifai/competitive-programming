#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i), a[i] &= 1;
    int len = strlen(s);
    if (len  > 4) { // chefu 1
      if (n & 1) {
        bool ok = 1;
        for (int i = 0; i < n; i += 2)
          if (!a[i])
            ok = 0;
        puts(ok ? "Chefu" : "Chef");
      }
      else 
        puts("Chef");
    }
    else {
      if (n & 1)
        puts("Chef");
      else {
        int i = 0, j = n-1;
        while (i < n && a[i]) i += 2;
        while (j >= 0 && a[j]) j -= 2;
        puts((j <= i) ? "Chefu" : "Chef");
      }
    }
  }
  return 0;
}