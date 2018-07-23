#include <bits/stdc++.h>

using namespace std;

const int N = 2018;

bitset<N * N> bs;
int n;

int main() {
  scanf("%d", &n);
  bs[0] = 1;
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    tot += a;
    bs = bs | (bs << a);
  }
  int mid = tot/2;
  while (!bs[mid]) --mid;
  printf("%d\n", tot - mid);
  return 0;
}