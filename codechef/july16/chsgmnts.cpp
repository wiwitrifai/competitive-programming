#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int n, a[N], id[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
      scanf("%d", a+i), b[i] = a[i];
    sort(b, b+n);
    int m = unique(b, b+n) - b;
    for(int i = 0; i<n; i++) {
      a[i] = lower_bound(b, b+m, a[i])-b;
    }
    long long ans = 0;
    for(int i = 0; i<n; i++) {
      int l = n, r = i-1;
      memset(id, -1, sizeof id);
      stack< pair< int, int > > st;
      st.push({i-1, i-1});
      long long sum = 0;
      for(int j = i; j<n; j++) {
        if(id[a[j]] == -1)
          id[a[j]] = j;
        int last = id[a[j]];
        while(!st.empty() && st.top().first >= last) {
          auto it = st.top(); st.pop();
          sum -= 1LL * (it.first-i) * (it.second-st.top().second);
        }
        sum += 1LL * (last-i) * (j-st.top().second);
        st.push({last, j});
        // cerr << i << " " << j << " " << sum << " " << last <<  endl; 
        ans += sum;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}