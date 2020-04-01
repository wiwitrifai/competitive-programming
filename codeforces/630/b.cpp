#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int col[N];

int main() {
  int cnt = 0;
  for (int i = 2; i < N; ++i) {
    if (col[i]) continue;
    ++cnt;
    for (int j = i; j < N; j += i)
      if (col[j] == 0)
        col[j] = cnt;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> all;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      a[i] = col[a[i]];
      all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    printf("%d\n", (int)all.size());
    for (int i = 0; i < n; ++i) {
      a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
      printf("%d%c", a[i], i+1 == n ? '\n' : ' ');
    }
  }
  return 0;
}
