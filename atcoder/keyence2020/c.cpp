#include <bits/stdc++.h>

using namespace std;

const int A = 1e9;

int main() {
  int n, k, s;
  scanf("%d %d %d", &n, &k, &s);
  for (int i = 0; i < n; ++i) {
    int val = A;
    if (i < k)
      val = s;
    else {
      if (s == A)
        val = 1;
      else
        val = s+1;
    }
    printf("%d%c", val, i+1 == n ? '\n' : ' ');
  }
  return 0;
}
