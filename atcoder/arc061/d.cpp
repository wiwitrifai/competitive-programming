#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];
long long ans[12];
map< pair<int, int>, int > mp;

int main() {
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);
  vector < int > vh;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a+i, b+i);
    for (int j = -2; j <= 0;  j++)
      for (int k = -2; k <= 0; k++) {
        int x = a[i] + j, y = b[i] + k;
        if (x > 0 && x+2 <= h && y > 0 && y+2 <= w)
          mp[make_pair(x, y)]++;
      }
  }
  for (auto it = mp.begin(); it != mp.end(); it++)
    ans[it->second]++;
  ans[0] = max(0LL, (long long)1LL * (h-2) * (w-2) - (long long)mp.size());
  for (int i = 0; i < 10; i++)
    printf("%lld\n", ans[i]);
  return 0;
}