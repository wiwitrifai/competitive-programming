#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N], n, k;

int main() {
  scanf("%d %d", &n, &k);
  vector<int> val;
  int mi = 1e9 + 7, ma = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (max(i, abs(n-1-i)) > k)
      val.push_back(a[i]);
  }
  sort(val.begin(), val.end());
  for (int i = 0, j = 0; i < n; ++i) {
    if (max(i, abs(n-1-i)) > k)
      a[i] = val[j++];
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
  return 0;
}