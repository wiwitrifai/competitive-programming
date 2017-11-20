#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, sum;
    scanf("%d %d", &n, &sum);
    s[n] = '\0';
    for (int i = 0, j = n-1; i <= j; i++, j--) {
      if (i == j) {
        int d = min(9, sum);
        s[i] = d + '0';
        sum -= d;
      }
      else {
        int d = min(9, sum/2);
        s[i] = s[j] = d + '0';
        sum -= d + d;
      }
    } 
    if (sum != 0 || s[0] == '0') {
      puts("-1");
    }
    else
      printf("%s\n", s);
  }
  return 0;
}