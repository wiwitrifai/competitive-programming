#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int bit[N], n, k;
void upd(int x, int v) {
  for (; x <= n; x += x&(-x))
    bit[x] = max(bit[x], v); 
}
int get(int x) {
  int ret = 0;
  for (; x; x -= x&(-x))
    ret = max(ret, bit[x]);
  return ret;
}
int to[N];

int main() {
#ifndef LOCAL
  freopen("nocross.in", "r", stdin);
  freopen("nocross.out", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    to[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    vector< int > v;
    for (int j = max(1, x-4); j <= min(n, x+4); j++)
      v.push_back(to[j]);
    sort(v.begin(), v.end());
    for (int j = v.size()-1; j >= 0; j--) {
      upd(v[j], get(v[j]-1) + 1);
    }
  }
  printf("%d\n", get(n));
  return 0;
}