#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
int n;
int ans[N];
char s[100];
bool cmp(int a, int b) {
  printf("2 %d %d\n", a, b);
  fflush(stdout);
  scanf("%s", s);
  return s[0] == 'Y';
}
bool divisible(int a, int b, int m) {
  if (m >= n)
    return false;
  printf("1 %d %d %d\n", a, b, m);
  fflush(stdout);
  scanf("%s", s);
  return s[0] == 'Y';
}

void solve(vector< int > & v, int m = 2) {
  if (v.size() == 1)
    return;
  vector< int > l, r;
  l.push_back(v[0]);
  for (int i = 1; i < v.size(); i++)
    if (divisible(v[0], v[i], m))
      l.push_back(v[i]);
    else
      r.push_back(v[i]);
  solve(l, m + m);
  solve(r, m + m);
  if (l.size() < r.size() || ((l.size() == r.size()) && cmp(r[0], l[0])))
    l.swap(r);
  for (int i = 0; i < v.size(); i++) {
    if (i & 1)
      v[i] = r[i>>1];
    else
      v[i] = l[i>>1];
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vector< int > v;
    for (int i = 1; i <= n; i++)
      v.push_back(i);
    solve(v, 2);
    for (int i = 0; i < n; i++)
      ans[v[i]] = i+1;
    printf("3");
    for (int i = 1; i <= n; i++)
      printf(" %d", ans[i]);
    printf("\n");
    fflush(stdout);
  }
  return 0;
}