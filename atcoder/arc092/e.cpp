#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

long long a[N];
bool live[N];
bool used[N];

int bit[N];
int get(int x) {
  ++x;
  int r = 0;
  for (; x; x -= x & -x)
    r += bit[x];
  return r;
}
void upd(int x, int v) {
  ++x;
  for (; x < N; x += x&-x)
    bit[x] += v;
}
set<int> st;
void rem(int id) {
  st.erase(id);
  upd(id, -1);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", a+i);
  long long sum1 = 0, ma1 = -1e18, sum2 = 0, ma2 = -1e18;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      if (a[i] > 0)
        sum1 += a[i];
      ma1 = max(ma1, a[i]);
    }
    else {
      if (a[i] > 0)
        sum2 += a[i];
      ma2 = max(ma2, a[i]);
    }
  }
  fill(live, live+n, 1);
  if (ma1 < 0) sum1 = ma1;
  if (ma2 < 0) sum2 = ma2;
  if (sum1 > sum2) {
    if (ma1 < 0) {
      for (int i = 0; i < n; ++i)
        if (a[i] == ma1) {
          used[i] = 1;
          break;
        }
    }
    else {
      for (int i = 1; i < n; i += 2)
        if (a[i] >= 0)
          used[i] = 1;
    }
  }
  else {
    if (ma2 < 0) {
      for (int i = 0; i < n; ++i)
        if (a[i] == ma2) {
          used[i] = 1;
          break;
        }
    }
    else {
      for (int i = 0; i < n; i += 2)
        if (a[i] >= 0)
          used[i] = 1;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i)
    if (used[i]) ans += a[i];
  for (int i = 0; i < n; ++i) {
    upd(i, 1);
    st.insert(i);
  }
  printf("%lld\n", ans);
  vector<int> op;
  while (st.size() > 1) {
    for (auto it = st.begin(); it != st.end(); ++it) {
      if (used[*it]) continue;
      auto nx = it;
      ++nx;
      bool del = 0;
      if (it == st.begin() || nx == st.end()) {
        del = 1;
      }
      else {
        auto pr = it; --pr;
        if (used[*pr] == used[*nx])
          del = 1;
      }
      if (del) {
        op.push_back(get(*it));
        if (nx != st.end()) {
          used[*it] = used[*nx];
          rem(*nx);
        }
        if (it != st.begin()) {
          auto pr = it; --pr;
          used[*it] = used[*pr];
          rem(*pr);
        }
        break;
      }
    }
  }
  printf("%d\n", op.size());
  for (int x : op)
    printf("%d\n", x);
  return 0;
}