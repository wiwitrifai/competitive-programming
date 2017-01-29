#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  printf("%d\n", t);
  for (int i = 1; i <= t; i++) {
    cerr << i << endl;
    printf("1\n");
    int now = 1;
    int cnt = 0;
    while (now <= i) now <<= 1;
    now>>=1;
    while (now) {
      cnt++;
      printf("%d", ((now & i) ? 1 : 0));
      now >>= 1;
    }
    printf("\n");
    cnt /= 2;
    printf("%d\n", cnt);
  }
  return 0;
}