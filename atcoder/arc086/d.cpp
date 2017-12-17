#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];
int main() {
  vector<pair<int, int> > ans;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a+i);
  }
  int mi = 0, ma = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < a[mi]) mi = i;
    if (a[i] > a[ma]) ma = i;
  }
  if (abs(a[mi]) < abs(a[ma]))
    swap(mi, ma);
  for (int i = 0; i < n; i++) {
    long long mul = a[mi] * 1LL * a[i];
    if (mul < 0) {
      a[i] += a[mi];
      ans.emplace_back(mi+1, i+1);
    }
  }
  if (a[mi] >= 0) {
    for (int i = 1; i < n; ++i)
      ans.emplace_back(i, i+1);
  }
  else {
    for (int i = n-1; i > 0; --i)
      ans.emplace_back(i+1, i);
  }
  printf("%d\n", ans.size());
  for (auto it : ans)
    printf("%d %d\n", it.first, it.second);
  return 0;
}