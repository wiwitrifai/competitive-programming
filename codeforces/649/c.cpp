#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> ans(n, -1);
  int last = -1;
  for (int i = 0, l = 0; i < n; ++i) {
    if (a[i] > last+1) {
      ans[i] = ++last;
      while (l < i && last+1 < a[i]) {
        if (ans[l] == -1) {
          ans[l] = ++last;
        }
        ++l;
      }
      if (last+1 != a[i]) {
        puts("-1");
        return 0;
      }
    }
  }
  last += 2;
  for (int i = 0; i < (int)ans.size(); ++i) {
    if (ans[i] == -1)
      ans[i] = ++last;
    printf("%d%c", ans[i], i+1 == (int)ans.size() ? '\n' : ' ');
  }
  return 0;
}


