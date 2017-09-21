#include <bits/stdc++.h>

using namespace std;

const int N = 550;
int a[N], n;

int main() {
  scanf("%d", &n);
  n *= 2;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vector<int> val;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        val.push_back(a[k]);
      }
      sort(val.begin(), val.end());
      int now = 0;
      for (int k = 0; k < val.size(); k += 2)
        now += val[k+1] - val[k];
      ans = min(ans, now);
    }
  }
  printf("%d\n", ans);
  return 0;
}