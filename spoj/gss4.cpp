#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
long long bit[N];
void upd(int x, long long v) {
  for (; x<= n; x += x & (-x))
    bit[x] += v;
}
long long get(int x) {
  long long ret = 0;
  for (; x; x -= x & (-x))
    ret += bit[x];
  return ret;
}
map< int, long long > mp;

int main() {
  int cs = 1;
  while (scanf("%d", &n) == 1) {
    printf("Case #%d:\n", cs++);
    mp.clear();
    for (int i = 0; i <= n; i++)
      bit[i] = 0;
    for (int i = 1; i <= n; i++) {
      long long a;
      scanf("%lld", &a);
      upd(i, a);
      if (a > 1)
        mp[i] = a;
    }
    int m;
    scanf("%d", &m);
    while (m--) {
      int t, x, y;
      scanf("%d %d %d", &t, &x, &y);
      if (x > y)
        swap(x, y);
      if (t) {
        printf("%lld\n", get(y) - get(x-1));
      }
      else {
        for (auto it = mp.lower_bound(x); it != mp.end() && it->first <= y;) {
          long long a = it->second;
          a = sqrt(a);
          while (a * a <= it->second)
            a++;
          a--;
          upd(it->first, a - it->second);
          if (a == 1) {
            auto del = it;
            it++;
            mp.erase(del);
          }
          else {
            mp[it->first] = a;
            it++;
          }
        }
      }
    }
    printf("\n");
  }
  return 0;
}