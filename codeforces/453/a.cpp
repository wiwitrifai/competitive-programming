#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

int par1[N], par2[N], a[N];

int main() {
  int k;
  scanf("%d", &k);
  for (int i = 0; i <= k; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < a[0]; ++i)
    par1[i] = par2[i] = 0;
  bool ok = 0;
  int now = a[0];
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < a[i]; ++j) {
      par1[now + j + 1] = now;
      par2[now + j + 1] = now;
    }
    if (a[i] > 1 && a[i-1] > 1) {
      par2[now + a[i] - 1] = now-1;
      ok = 1;
    }
    now += a[i];
  } 
  if (ok) {
    puts("ambiguous");
    for (int i = 1; i <= now; ++i)
      printf("%d%c", par1[i], i == now ? '\n' : ' ');
    for (int i = 1; i <= now; ++i)
      printf("%d%c", par2[i], i == now ? '\n' : ' ');
  }
  else
    puts("perfect");
  return 0;
}