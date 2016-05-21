#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b, t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d", &n, &a, &b);
    int diff = abs(a-b);
    if(diff & 1)
      puts("Mikael");
    else
      puts("Steven");
  }
  return 0;
}