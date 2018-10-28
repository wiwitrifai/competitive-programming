#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int last = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    int now = a[i];
    a[i] = now - last;
    last = now;
  }
  vector<int> ans;
  for (int k = 1; k <= n; ++k) {
    bool ok = 1;
    for (int i = k; i < n; ++i) {
      if (a[i] != a[i-k]) {
        ok = 0;
        break;
      }
    }
    if (ok)
      ans.push_back(k);
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d%c", ans[i], i == (int)ans.size()-1 ? '\n' : ' ');
  }
  return 0;
}