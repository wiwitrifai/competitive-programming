#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", n * (m-1) + (n-1)*m);
  }
  return 0;
}