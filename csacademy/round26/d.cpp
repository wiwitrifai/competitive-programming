#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int a[N], n, b[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", b+i);
  bool ok = 1;
  for (int i = 1; i <= n; i++) {
    if (b[i] >= 2) {
      if (b[i-1] == b[i] || b[i+1] == b[i])
        ok = 0;
      if (b[i] > 2 && (i == 1 || i == n))
        ok = 0;
    }
    else if (b[i] == 1) {
      if (b[i-1] == 1 || b[i+1] == 1)
        ok = 0;
    }
  }
  if (!ok)
    puts("-1");
  else {
    vector< int > ans;
    for (int i = 1; i <= n; i++) {
      if (b[i] == 3) {
        ans.push_back(i);
        ans.push_back(i+1);
        ans.push_back(i-1);
        ans.push_back(i);
        a[i] = 3;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (b[i] == 2) {
        if (i < n && b[i+1] != 3)
          ans.push_back(i+1);
        else if (i > 1 && b[i-1] != 3)
          ans.push_back(i-1);
        else
          ok = 0;
        ans.push_back(i);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (b[i] == 1) {
        ans.push_back(i);
      }
    }
    if (ok) {
      printf("%d\n", ans.size());
      for (int id : ans)
        printf("%d ", id);
      printf("\n");
    }
    else
      puts("-1");
  }
  return 0;
}