#include <bits/stdc++.h>

using namespace std;

int cnt[5];

int main() {
  for (int i = 0; i < 3; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ++cnt[a];
    ++cnt[b];
  }
  for (int i = 1; i <= 4; ++i) if (cnt[i] >= 3) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}