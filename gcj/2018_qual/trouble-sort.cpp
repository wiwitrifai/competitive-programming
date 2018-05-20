#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n;
    scanf("%d", &n);
    vector<int> even, odd;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      if (i & 1)
        odd.push_back(a[i]);
      else
        even.push_back(a[i]);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    for (int i = 0; i < odd.size(); ++i)
      a[i * 2 + 1] = odd[i];
    for (int i = 0; i < even.size(); ++i)
      a[i * 2] = even[i];
    int id = -1;
    for (int i = 1; i < n; ++i)
      if (a[i] < a[i-1]) {
        id = i-1;
        break;
      }
    if (id == -1)
      printf("Case #%d: OK\n", tc);
    else
      printf("Case #%d: %d\n", tc, id);
  }
  return 0;
}