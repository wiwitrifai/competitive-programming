#include <bits/stdc++.h>

using namespace std;

vector<int> dua, tiga, enam;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= 30000; ++i) {
    if ((i % 6) == 0)
      enam.push_back(i);
    else if ((i % 2) == 0)
      dua.push_back(i);
    else if ((i % 3) == 0)
      tiga.push_back(i);
  }
  if (n == 3) {
    puts("2 5 63");
  }
  else if (n == 4) {
    puts("2 5 20 63");
  }
  else {
    int a = 2, b = 2;
    int na = dua.size(), nb = tiga.size();
    n -= a + b;
    int k = min(n, nb - b) / 2;
    b += k * 2;
    n -= 2 * k;
    k = min(n, na - a) / 2;
    a += 2 * k;
    n -= 2 * k;
    for (int i = 0; i < a; ++i)
      printf("%d ", dua[i]);
    for (int j = 0; j < b; ++j)
      printf("%d ", tiga[j]);
    for (int i = 0; i < n; ++i)
      printf("%d ", enam[i]);
    printf("\n");
  }
  return 0;
}