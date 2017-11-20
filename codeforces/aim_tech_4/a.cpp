#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) 
    scanf("%d", a+i), b[i] = a[i];
  sort(b, b+n);
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(b, b+n, a[i]) - b;
  vector<vector< int > > ans; 
  for (int i = 0; i < n; i++) if (a[i] >= 0) {
    vector< int > cur;
    int now = i;
    while (now >= 0) {
      cur.push_back(now+1);
      int nx = a[now];
      a[now] = -1;
      now = nx;
    }
    sort(cur.begin(), cur.end());
    cur.erase(unique(cur.begin(), cur.end()), cur.end());
    ans.push_back(cur);
  }

  printf("%d\n", ans.size());
  for (auto it : ans) {
    printf("%d", it.size());
    for (int x : it)
      printf(" %d", x);
    printf("\n");
  }
  return 0;
}