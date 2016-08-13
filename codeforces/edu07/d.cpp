#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = 0;
  int last = 0;
  for (int i = 1 + (n & 1); i < n; i += 2) {
    printf("%d ", i);
    last = i;
  }
  for (int i = last; i > 0; i -= 2) {
    printf("%d ", i);
  }
  last = 0;
  for (int i = 2 - (n & 1); i < n; i += 2) {
    printf("%d ", i);
    last = i;
  }
  printf("%d ", n);
  for (int i = last; i > 0; i -= 2) {
    printf("%d ", i);
  }
  printf("%d\n", n);
  return 0;
}