#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  scanf("%d", &k);
  vector<int> bits;
  for (int i = 0; i < 15; ++i) {
    if (k & (1 << i))
      bits.push_back(i);
  }
  vector<int> a;
  int now = 0;
  for (int i = 0; i < (int)bits.size(); ++i) {
    now |= (1 << (i+15));
    a.push_back(now);
    now |= (1 << bits[i]);
    a.push_back(now);
  }
  reverse(a.begin(), a.end());
  printf("%d\n", (int)a.size());
  for (int i = 0; i < (int)a.size(); ++i)
    printf("%d%c", a[i], i+1 == (int)a.size() ? '\n' : ' ');
  return 0;
}
