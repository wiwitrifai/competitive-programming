#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int t[N];

int main() {
  int n, k, c;
  scanf("%d %d %d", &n, &c, &k); 
  for (int i = 0; i < n; i++)
    scanf("%d", t+i);
  sort(t, t+n);
  int ans = 0, start = -1, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (start == -1 || cnt >= c)
      start = t[i], cnt = 0, ans++;
    if (start + k < t[i])
      start = t[i], cnt = 0, ans++;
    cnt++;
  }
  printf("%d\n", ans);
  return 0;
}