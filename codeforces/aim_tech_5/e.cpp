#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

long long a[N];
int b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
  bool same = 1;
  for (int i = 0; i < n; ++i) {
    if (b[i] != b[0])
      same = 0;
  }
  if (same) {
    if (b[0] == 0) {
      puts("YES");
      for (int i = 0; i < n; ++i) {
        printf("%d%c", 1, i == n-1 ?'\n' : ' ');
      }
    }
    else {
      puts("NO");
    }
    return 0;
  }
  auto pre = [n](int x) { return x == 0 ? n-1 : x-1; };
  auto nxt = [n](int x) { return x == n-1 ? 0 : x+1; };
  int start = -1;
  for (int i = 0; i < n; ++i) {
    if (b[pre(i)] < b[i])
      start = i;
  }
  a[start] = b[start];
  int now = pre(start);
  while (now != start) {
    long long mod = a[nxt(now)];
    long long low = b[pre(now)] + 1;
    a[now] = b[now];
    if (a[now] < low) {
      long long mul = (low - a[now] + mod - 1) / mod;
      a[now] += mul * mod;
    }
    now = pre(now);
  }
  puts("YES");
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", a[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}