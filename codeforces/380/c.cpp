#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], n, s, cnt[N];

int main() {
  scanf("%d %d", &n, &s);
  s--;
  int ans = 0, tmp = 0;
  for (int i= 0; i < n; i++) {
    scanf("%d", a+i);
    if (i == s) {
      ans += a[s] != 0;
    }
    else {
      cnt[a[i]]++;
    }
  } 
  int ma = n-1;
  tmp = n-1;
  int sum = 0, need = 0;
  for (int i = 1; i <= n; i++) {
    tmp -= cnt[i];
    need += (cnt[i] == 0);
    ma = min(ma, max(tmp, need));
  }
  ans += ma;
  printf("%d\n", ans);
  return 0;
}