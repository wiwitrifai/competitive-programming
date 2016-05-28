#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int main() {
  int n;
  scanf("%d", &n);
  int a, b;
  a = -1;
  b = inf;
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    if(x) {
      a = b;
      b = inf;
    }
    else {
      int c = a;
      a = b;
      b = min(b, c)+1;
    }
  }
  printf("%d\n", b);

  return 0;
}