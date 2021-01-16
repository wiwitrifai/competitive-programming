#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 1e5, m = 1e5;
  string s0(100, 'a');
  string t(n, 'a');
  printf("%d %d\n", n, m);
  printf("%s\n%s\n", s0.c_str(), t.c_str());
  for (int i = 0; i < m; ++i) {
    printf("%d %s\n", (rand() % (n-2)) + 2, string(10, 'a').c_str());
  }
  return 0;
}
