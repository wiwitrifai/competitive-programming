#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int n = a + b + c;
  int cnt = n / 7;
  puts((max(a, max(b, c)) == cnt * 4) ? "YA" : "TIDAK");
  return 0;
}