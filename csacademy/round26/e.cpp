#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

pair< int, int > p[N];
int a[N], n, id[N];
int last[N], cnt[N], val[N];
int ok[N];

int main() {
  scanf("%*d %*d %d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    p[i] = {x, y};
  } 
  sort(p, p+n);
  int k = 0;
  for (int i = 0; i < n; i++) {
    int z = upper_bound(a, a+k, p[i].second) - a;
    a[z] = p[i].second;
    id[z] = i;
    val[i] = z+1;
    k += z == k;
  }
  memset(last, -1, sizeof last);
  for (int i = n-1; i >= 0; i--) {
    if (val[i] == k) ok[i] = 1;
    else if (last[val[i]+1] != -1 && p[last[val[i]+1]].second >= p[i].second)
      ok[i] = 1;
    if (ok[i]) {
      cnt[val[i]]++;
      if (last[val[i]] == -1 || p[i].second > p[last[val[i]]].second)
        last[val[i]] = i;
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += cnt[i] == 1;
  }
  printf("%d\n", ans);
  return 0;
}