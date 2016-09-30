#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool isprim[100];
int cnt[N];

int main() {
  memset(isprim, 1, sizeof isprim);
  isprim[0] = isprim[1] = 0;
  for (int i = 2; i < 100; i++) if (isprim[i]) {
    for (int j = i * i; j < 100; j += i)
      isprim[j] = false;
  }
  cnt[0] = 0;
  for (int i = 1; i < N; i++) {
    cnt[i] = cnt[i-1] + isprim[__builtin_popcount(i)];
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", cnt[r] - (l ? cnt[l-1] : 0));
  }
  return 0;
}