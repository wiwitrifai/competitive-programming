#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int bnow = 0;
    cur = 0;
    for (int j = 0; j < 8; j++) {
      int x = (b[i] >> j) & 1;
      cur ^= x;
      bnow |= (cur << j);
    }
    printf("%d%c", bnow, i == n-1 ? '\n' : ' ');
  }
  return 0;
}