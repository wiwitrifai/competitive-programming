#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];
int cnt[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%lld", a+i);
    }
    sort(a, a+n);
    long long last = a[0], now = 0;
    cnt[0] = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == last) {
        a[i] = now;
        cnt[now]++;
      }
      else {
        last = a[i];
        a[i] = ++now;
        cnt[now] = 1;
      }
    }
    now = -1;
    set< pair< int, int > > st;
    int ans = n;
    for (int i = 0; i < n; i += k) {
      while (now < a[i]) {
        now++;
        st.insert(make_pair(cnt[now], now));
      }
      auto it = --st.end();
      int c = it->first, v = it->second;
      st.erase(it);
      if (c <= k) {
        ans -= c;
      }
      else {
        ans -= k;
        st.insert(make_pair(c-k, v));
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}