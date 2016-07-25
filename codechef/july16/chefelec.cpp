#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%s", &n, s);
    for(int i = 0; i<n; i++)
      scanf("%d", a+i);
    set< pair<int, int> > st;
    for(int i = 0; i<n; i++) {
      if(s[i] == '1') {
        if(i && s[i-1] == '0')
          st.insert(make_pair(a[i]-a[i-1], i-1));
        if(i < n-1 && s[i+1] == '0')
          st.insert(make_pair(a[i+1]-a[i], i+1));
      }
    }
    long long ans = 0;
    while(!st.empty()) {
      auto it = st.begin();
      int now = it->second, cost = it->first;
      st.erase(it);
      if(s[now] == '1')
        continue;
      ans += cost;
      s[now] = '1';
      if(now && s[now-1] == '0')
        st.insert(make_pair(a[now]-a[now-1], now-1));
      if(now < n-1 && s[now+1] == '0')
        st.insert(make_pair(a[now+1]-a[now], now+1));
    }
    printf("%lld\n", ans);
  }
  return 0;
}