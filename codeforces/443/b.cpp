#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], c[N];

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  long long ans = 1LL * n * m;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  int z = 0;
  c[z] = a[0];
  b[z] = 0;
  for (int i = 0; i < n; i++) {
    // cerr << z << i << endl;
    if (a[i] == c[z])
      b[z]++;
    else {
      z++;
      c[z] = a[i];
      b[z] = 1;
    }
  }
  // cerr << "halo" << endl;
  z++;
  stack<pair<int, int> > st;
  for (int i = z-1; i >= 0; i--) {
    int now = b[i], col = c[i];
    while (!st.empty()) {
      if (st.top().second != col) break;
      now += st.top().first;
      st.pop();
    }
    int cnt = now/k;
    now -= 1LL * cnt * k;
    ans -= 1LL * cnt * k * m;
    if (now)
      st.push(make_pair(now, col));
  }
  for (z = 0; !st.empty(); z++) {
    b[z] = st.top().first;
    c[z] = st.top().second;
    st.pop();
  }
  int l = 0, r = z-1;
  vector<pair<int, int> > depan, belakang;
  while (l < r) {
    if (m < 2) break;
    if (c[l] != c[r]) break;
    depan.emplace_back(b[l], c[l]);
    belakang.emplace_back(b[r], c[r]);
    b[l] += b[r];
    r--;
    int cnt = b[l]/k;
    b[l] -= 1LL * cnt * k;
    ans -= 1LL * cnt * k * (m-1);
    if (b[l] == 0)
      l++;
    else
      break;
  }
  if (l == r) {
    long long cur = 1LL * b[r] * m;
    long long cnt = cur/k;
    cur -= cnt * k;
    ans -= cnt * k;
    while (cur == 0 && (!depan.empty() && !belakang.empty())) {
      cur = depan.back().first + belakang.back().first;
      depan.pop_back();
      belakang.pop_back();
      cnt = cur/ k;
      cur -= cnt * k;
      ans -= cnt * k;
    }
  }
  cout << ans << endl;
  return 0;
}