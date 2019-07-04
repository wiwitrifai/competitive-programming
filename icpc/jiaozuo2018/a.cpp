#include <bits/stdc++.h>

using namespace std;

char str[5][55] = {"Typically Otaku", "Eye-opener", "Young Traveller", "Excellent Traveller", "Contemporary Xu Xiake"};

void solve() {
  int cnt = 0;
  for (int i = 0; i < 4; ++i) {
    int a;
    scanf("%d", &a);
    cnt += a > 0;
  }
  printf("%s\n", str[cnt]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
