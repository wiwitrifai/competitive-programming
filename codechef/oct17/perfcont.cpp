#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, p;
    scanf("%d %d", &n, &p);
    int hard = p/10, easy = p / 2;
    int ne = 0, nh = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      nh += x <= hard;
      ne += x >= easy;
    }
    puts((nh == 2 && ne == 1) ? "yes" : "no");
  }
  return 0;
}