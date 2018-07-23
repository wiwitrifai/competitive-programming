#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  puts((b-a)&1 ? "Borys" : "Alice");
  return 0;
}