#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N], cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", p+i);
    --p[i];
  }
  for (int i = n-1; i >= 0; --i) {
    cnt[i] = max(cnt[i], 1);
    if (i == 0)
      break;
    cnt[p[i]] += cnt[i];
  }
  sort(cnt, cnt+n);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", cnt[i], i == n-1 ? '\n' : ' ');
  }
  return 0;
}