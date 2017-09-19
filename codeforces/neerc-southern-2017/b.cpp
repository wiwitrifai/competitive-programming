#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N], n;
vector<int> ans[N];

int main() {
  scanf("%d", &n);
  int m = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    int l = 0, r = m;
    while (l < r) {
      int mid = (l + r) / 2;
      if (a[mid] > x)
        l = mid + 1;
      else
        r = mid;
    }
    ans[l].push_back(x);
    a[l] = x;
    m += l == m;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      if (j) printf(" ");
      printf("%d", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}