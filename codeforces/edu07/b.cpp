#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d:%d", &a, &b);
  scanf("%d", &c);
  int n = a * 60 + b;
  n += c;
  n %= 24 * 60;
  printf("%02d:%02d\n", n/60, n % 60);

  return 0;
}