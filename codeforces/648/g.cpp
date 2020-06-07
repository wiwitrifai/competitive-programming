#include <bits/stdc++.h>

using namespace std;

const int B = 63;

long long ask(set<int> st) {
  if (st.empty())
    return 0;
  printf("? %d\n", (int)st.size());
  for (int x : st)
    printf("%d ", x);
  printf("\n");
  fflush(stdout);
  long long ans;
  scanf("%lld", &ans);
  if (ans == -1)
    exit(0);
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> val;
  int nmask = 1 << 13;
  for (int mask = 0; mask < nmask; ++mask) {
    if (__builtin_popcount(mask) == 6)
      val.emplace_back(mask);
  }
  assert((int)val.size() > n);
  long long all = 0;
  vector<long long> res(13);
  for (int i = 0; i < 13; ++i) {
    set<int> st;
    for (int j = 1; j <= n; ++j) {
      if ((val[j] >> i) & 1)
        st.insert(j);
    }
    res[i] = ask(st);
    all |= res[i];
  }
  vector<long long> a(n+1, all);
  for (int i = 0; i < 13; ++i) {
    for (int j = 1; j <= n; ++j) {
      if ((val[j] >> i) & 1)
        a[j] &= res[i];
    }
  }
  vector<int> pos(B, -1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < B; ++j)
      if ((a[i] >> j) & 1) {
        if (pos[j] == -1)
          pos[j] = i;
        else
          pos[j] = -2;
      }
  }

  printf("!");
  for (int i = 1; i <= n; ++i) {
    long long ans = all;
    for (int j = 0; j < B; ++j) {
      if (pos[j] == i) {
        ans ^= 1LL << j;
      }
    }
    printf(" %lld", ans);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}
