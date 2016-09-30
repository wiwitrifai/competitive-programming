#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool vis[N];
int last = -1;

int solve1(int k, int now) {
  char a, b;
  a = '+'; b = '-';
  for (int i = k; i > 0; i--) {
    printf("%c %d\n", a, i);
    if (a == '+')
      now += i;
    else
      now -= i;
    // vis[now] = 1;
    last = max(last, now);
    swap(a, b);
  }
  return now;
}

int solve2(int k, int now) {
  char a, b;
  a = '+';
  b = '-';
  if (k & 1)
    swap(a, b);
  for (int i = 1; i < k; i++) {
    printf("%c %d\n", a, i);
    if (a == '+')
      now += i;
    else
      now -= i;
    // vis[now] = 1;
    last = max(last, now);
    swap(a, b);
  }
}


int main() {
  int now = 0;
  int n, k, s;
  scanf("%d %d %d", &n, &k, &s);
  if (s == 0) {
    int cnt = (n+k-1)/k;
    printf("%d\n", k * cnt);
    for (int i = 0; i < cnt; i++) {
      if ((i & 1) == 0)
        solve1(k, k);
      else {
        printf("+ %d\n", k);
        solve2(k, k);
      }
    }
    return 0;
  }
  printf("%d\n", n);
  while (n) {
    int mi = min(n, k);
    now = solve1(mi, now);
    n -= mi;
    if (n == 0)
      break;
    mi = min(n, k);
    printf("+ %d\n", last+  (mi+1)/2 - now);
    now = last+(mi+1)/2;
    now = solve2(mi, now);
    n -= mi;
  }
  return 0;
}

// 0 4 1 3 2 6 7 5 8 
// 5
// 0 5 1 4 2 3 8 7 9 6 10 
// 0 6 1 5 2 4 