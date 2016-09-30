#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5, inf = 1e8;

int n, m, k;
int a[N];
char s[N];
vector< int > b;
int main() {
  scanf("%d %d %d", &n, &k, &m);
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    if (s[i] == '1')
      b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  int ans = 0;
  for (int i = (int)b.size() - 1; i >= 0; i--) {
    if (k) {
      k--;
    }
    else if (m) {
      ans += b[i]/2;
      m--;
    }
    else
      ans += b[i];
  }
  printf("%d\n", ans);
  return 0;
}
