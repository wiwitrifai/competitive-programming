#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N];

int main() {
  int a, b, v, w;
  scanf("%d %d", &a, &v);
  scanf("%d %d", &b, &w);
  int t;
  scanf("%d", &t);
  int d = abs(a - b);
  if (v <= w) {
    puts("NO");
    return 0;
  }
  int dv = v - w;
  puts(((long long)dv * t >= d) ? "YES" : "NO");
  return 0;
}
