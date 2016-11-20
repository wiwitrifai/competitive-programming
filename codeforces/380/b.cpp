#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int n, a, b, k;
int can[N];

int main() {
  scanf("%d %d %d %d", &n, &a, &b, &k);
  scanf("%s", s);
  if (b == 1) {
    int cnt = n-k - a + 1;
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) if (s[i] == '0') {
      printf("%d ", i+1);
      cnt--;
      if (cnt == 0)
        break;
    }
    printf("\n");
    return 0;
  }
  int last = -1;
  vector< pair<int, int> > range;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (last == -1)
        last = i;
    }
    else {
      if (last != -1) {
        range.push_back({last, i});
        last = -1;
      }
    }
  }
  if (last != -1)
    range.push_back({last, n});
  int sum = 0;
  int ans = 0, id = -1;
  for (int i = 0; i < range.size(); i++) {
    can[i] = (range[i].second - range[i].first) / b;
    sum += can[i];
  }
  ans = sum - a + 1;
  printf("%d\n", ans);
  for (int i = 0; i < range.size(); i++) {
    for (int j = 0, now = range[i].first+b; j < can[i]; j++, now += b) {
      if (ans <= 0)
        break;
      now = min(now, range[i].second);
      printf("%d ", now);
      ans--;
    }
  }
  printf("\n");
  return 0;
}