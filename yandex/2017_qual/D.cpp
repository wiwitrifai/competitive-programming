#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    cin >> n;
    int ans = 1;
    while (1) {
      bool ok = 1;
      long long cur = n * ans;
      if (__builtin_popcountll(cur) <= ans)
        break;
      ans++;
    }
    multiset< long long > st;
    long long cur = n * ans, b = 0;
    while (cur) {
      if (cur & 1)
        st.insert(b);
      b++;
      cur >>= 1;
    }
    while (st.size() < ans) {
      auto it = prev(st.end());
      long long w = *it;
      st.erase(it);
      st.insert(w-1);
      st.insert(w-1);
    }
    printf("%d", ans);
    for (int v : st)
      printf(" %lld", v);
    printf("\n");
  }

  return 0;
}