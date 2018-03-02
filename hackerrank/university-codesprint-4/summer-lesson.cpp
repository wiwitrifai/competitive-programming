#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int cnt[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    ++cnt[c];
  } 
  for (int i = 0; i < m; ++i)
    printf("%d%c", cnt[i], i == m-1 ? '\n' : ' ');
  return 0;
}