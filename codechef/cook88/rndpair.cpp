#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    int big = 0;
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
        big = max(big, a[i] + a[j]);
    int cnt = 0, all = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        all++;
        cnt += big == (a[i] + a[j]);
      }
    }
    printf("%.9lf\n", (double)cnt/all);
  }
  return 0;
}