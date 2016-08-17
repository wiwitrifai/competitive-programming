#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e18;
int n, a[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i<n; i++) 
      scanf("%d", a+i);
    int u, v;
    scanf("%d%d", &u, &v);
    u--; v--;
    long long ans = inf;
    long long sum = 0;
    for(int i = 0; i<2; i++) {
      int now = u;
      sum = 0;
      while(now != v) {
        sum += a[now];
        now = (now + 1) % n;
      }
      ans = min(ans, sum);
      long long add = 0, madd = add;
      stack< long long > st;
      st.push(0);
      now = u;
      do {
        now = (now + n-1) % n;
        add += a[now];
        madd = min(add, madd);
        st.push(madd);
      } while(now != v);
      ans = min(ans, sum + 2LL*madd);
      now = v;
      add = 0; madd = 0;
      while(now != u) {
        add += a[now];
        madd = min(madd, add);
        st.pop();
        now = (now + 1) % n;
        ans = min(ans, sum + 2LL*(madd + st.top()));
      }
      swap(u, v);
    }
    printf("%lld\n", ans);
  }

  return 0;
}