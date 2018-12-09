#include <bits/stdc++.h>

using namespace std;

const string filename = "icecream.in";
const int N = 1e5 + 5;

pair<int, int> ice[N];
int h[N];

int main() {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
      int c;
      scanf("%d", &c);
      ice[i].first = c;
    }
    for (int i = 0; i < n; ++i) {
      int c;
      scanf("%d", &c);
      ice[i].second = c;
    }
    sort(ice, ice+n);
    int worst = ice[k-1].first;
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      if (ice[i].first > worst) break;
      tot = i+1;
      h[i] = ice[i].second;
    }
    sort(h, h+tot);
    reverse(h, h+tot);
    long long ans = 0;
    for (int i = 0; i < k; ++i)
      ans += h[i];
    printf("%d %lld\n", worst, ans);
  }
#ifndef LOCAL
  fclose(stdin);
#endif

  return 0;
}