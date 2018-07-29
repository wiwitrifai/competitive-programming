#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long s[N];
long long sum[N];
int ganjil[N];

void solve(int tc) {
  int n, o;
  long long d;
  scanf("%d %d %lld", &n, &o, &d);
  long long a, b, c, m, l;
  scanf("%lld %lld %lld %lld %lld %lld %lld", s, s+1, &a, &b, &c, &m, &l);
  for (int i = 2; i < n; ++i) {
    s[i] = (a * s[i-1] + b * s[i-2] + c) % m;
  }
  for (int i = 0; i < n; ++i)
    s[i] += l;
  sum[0] = 0;
  ganjil[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum[i+1] = sum[i] + s[i];
    bool odd = s[i] & 1;
    ganjil[i+1] = ganjil[i] + odd;
  }
  set<pair<long long, int> > st;
  bool found = 0;
  long long ans = 0;
  for (int i = 0, r = 0; i < n; ++i) {
    while (r <= n && ganjil[r] - ganjil[i] <= o) {
      st.insert(make_pair(sum[r], r));
      ++r;
    }
    st.erase(make_pair(sum[i], i));
    if (st.empty()) continue;
    auto it = st.lower_bound(make_pair(sum[i]+d+1, -1));
    if (it == st.begin()) continue;
    --it;
    if (found)
      ans = max(ans, it->first-sum[i]);
    else
      ans = it->first-sum[i], found = 1;
  }
  printf("Case #%d: ", tc);
  if (!found)
    puts("IMPOSSIBLE");
  else
    printf("%lld\n", ans);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}