#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N];
int pos[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  vector<int> ans;
  for (int i = n-1; i >= 0; --i) {
    int now = 0;
    for (int j = 0; j < n; ++j) {
      pos[j] = -2;
      if (a[j] == -1) continue;
      ++now;
      pos[j] = now;
    }
    if (now == 0) break;
    for (int j = n-1; j >= 0; --j) {
      if (pos[j] == a[j]) {
        ans.push_back(a[j]);
        a[j] = -1;
        break;
      }
    }
  }
  if (ans.size() == n) {
    reverse(ans.begin(), ans.end());
    for (int x : ans)
      printf("%d\n", x);
  }
  else
    puts("-1");
  return 0;
}