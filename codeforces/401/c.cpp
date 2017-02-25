#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector< vector< int > > a;
int last[N];
int wow[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  a.resize(n);
  for (int i = 0; i < n; i++)
    a[i].resize(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  memset(last, 0, sizeof last);
  wow[0] = 0;
  for (int i = 1; i < n; i++) {
    int mi = i;
    for (int j = 0; j < m; j++) {
      if (a[i-1][j] > a[i][j])
        last[j] = i;
      mi = min(mi, last[j]);
    }
    wow[i] = mi;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--; r--;
    puts(wow[r] <= l ? "Yes" : "No"); 
  }
  return 0;
}