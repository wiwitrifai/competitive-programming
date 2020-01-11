#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];
int masuk[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int cnt = 0, d = 0;
  for (int i = 0; i < n; ++i) {
    ++d;
    if (a[i] > 0) {
      int v = a[i];
      if (masuk[v] != 0) {
        puts("-1");
        return 0;
      }
      masuk[v] = 1;
      ++cnt;
    }
    else {
      int v = -a[i];
      if (masuk[v] != 1) {
        puts("-1");
        return 0;
      }
      masuk[v] = 2;
      --cnt;
    }
    if (cnt == 0) {
      for (int k = i-d+1; k <= i; ++k) {
        masuk[abs(a[k])] = 0;
      }
      if (d > 0)
        ans.push_back(d);
      d = 0;
    }
  }
  if (cnt != 0) {
    puts("-1");
    return 0;
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i], i+1 == (int)ans.size() ? '\n' : ' ');
  }
  return 0;
}
