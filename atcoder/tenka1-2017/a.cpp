#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < 3505; i++) {
    for (int j = 1; j < 3505; j++) {
      long long up = 1LL * n * i * j, down = 4LL * i * j - (i + j) * 1LL * n;
      if (down <= 0) continue;
      if (up % down) continue;
      long long w = up / down;
      cout << i << " " << j << " " << w << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}