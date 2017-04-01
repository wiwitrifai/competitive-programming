#include <bits/stdc++.h>

using namespace std;

const int N = 111;

bool live[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
    live[i] = 1;
  int now = 1, s = n;
  while (k--) {
    int a;
    scanf("%d", &a);
    a %= s;
    while (a--) {
      now = (now + 1) % n;
      while (!live[now]) now = (now + 1) % n;
    }
    live[now] = 0;
    int ans = now;
    if (ans == 0)
      ans = n;
    printf("%d ", ans);
    now = (now + 1) % n;
    while (!live[now]) now = (now + 1) % n;
    s--;
  }
  printf("\n");
  return 0;
}