#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 6;
char s[N];
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    int one = 0, ma = 0, now = 0;
    for (int i = 0; i < n; i++)
      one += s[i] == '0';
    for (int i = 0; i < 2 * n; i++) {
      if (s[i % n] == '0')
        now++;
      else
        now = 0;
      ma = max(ma, now);
    }
    printf("%d\n", max(one - ma, 0));
  }
  return 0;
} 