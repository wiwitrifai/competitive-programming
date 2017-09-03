#include <bits/stdc++.h>


using namespace std;

long long fib[10006];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int r = n % 3;
    puts((r == 2 || r == 0) ? "YES" : "NO");
  }

  return 0;
}