#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int h[N], w[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", w+i);
    set < pair< int, int > > st;
    for (int i = 0; i < n; i++) {
      scanf("%d", h+i);
      st.insert(make_pair(h[i], i));
    }
    auto it = --st.end(); 
    long long up = 1LL * w[0] * it->first;
    st.erase(it);
    sort(w+1, w+n);
    bool ok = true;
    for (int i = n-1; i > 0; i--) {
      it = st.lower_bound(make_pair((up-1)/w[i] + 1, -1));
      if (it == st.begin()) {
        ok = false;
        break;
      }
      it--;
      assert(1LL * w[i] * it->first < up);
      st.erase(it);
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}