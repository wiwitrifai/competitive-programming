#include <bits/stdc++.h>

using namespace std;

const int N = 505;

vector<int> a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int id = -1, sel = -1;
  int all = 0;
  for (int i = 0; i < n; ++i) {
    a[i].resize(m);
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
    all ^= a[i][0];
    for (int j = 1; j < m; ++j) {
      if (a[i][j] != a[i][0]) {
        id = i;
        sel = j;
      }
    }
  }
  if (all) {
    puts("TAK");
    for (int i = 0; i < n; ++i)
      printf("1%c", i == n-1 ? '\n' : ' ');
  }
  else if (id != -1) {
    puts("TAK");
    for (int i = 0; i < n; ++i) {
      printf("%d%c", id == i ? sel + 1 : 1, i == n-1 ? '\n' : ' ');
    }
  }
  else {
    puts("NIE");
  }
  return 0;
}
