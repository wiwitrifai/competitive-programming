#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> f;
  for (int i = 1; 1LL * i * i <= n; ++i) {
    if (n % i) continue;
    f.push_back(i);
    int x = n/i;
    if (x != i)
      f.push_back(x);
  }
  sort(f.begin(), f.end());
  f.erase(unique(f.begin(), f.end()), f.end());
  set<long long> st;
  for (int x : f) {
    int cnt = n/x;
    int til = n - x;
    long long sum = cnt + 1LL * cnt * (til) / 2;
    // cerr << x << " " << sum << endl;
    st.insert(sum);
  }
  // printf("%d\n", (int)st.size());
  for (long long x : st) {
    printf("%lld ", x);
  }
  printf("\n");
  return 0;
}