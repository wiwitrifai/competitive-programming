
#include <bits/stdc++.h>

using namespace std;


vector<int> read_sequence(int k, int n) {
  vector<int> s(n);
  for (int i = 0; i < k; ++i)
    scanf("%d", &s[i]);
  long long a, b, c, d;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
  for (int i = k; i < n; ++i) {
    s[i] = ((a * s[i-2] + b * s[i-1] + c) % d);
  }
  return s;
}

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> s = read_sequence(k, n);
  vector<int> x = read_sequence(k, n);
  vector<int> y = read_sequence(k, n);
  long long sumx = 0, sumy = 0, sums = 0;
  for (int i = 0; i < n; ++i) {
    sums += s[i];
    sumx += x[i];
    sumy += y[i];
  }
  if (sums < sumx || sums > sumx+sumy) {
    puts("-1");
    return;
  }
  vector<int> ans = s;
  long long cur = 0;
  for (int i = 0; i < n; ++i) {
    ans[i] = max(ans[i], x[i]);
    ans[i] = min(ans[i], x[i]+y[i]);
    cur += ans[i];
  }
  for (int i = 0; i < n; ++i) {
    if (cur < sums) {
      long long add = sums - cur;
      long long now = x[i]+y[i] - ans[i];
      add = min(add, now);
      cur += add;
      ans[i] += add;
    } else {
      long long rem = cur - sums;
      long long now = ans[i] - x[i];
      rem = min(rem, now);
      cur -= rem;
      ans[i] -= rem;
    }
  }
  assert(cur == sums);
  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    assert(x[i] <= ans[i] && ans[i] <= x[i]+y[i]);
    ret = ret + max(ans[i] - s[i], 0);
  }
  printf("%lld\n", ret);
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
