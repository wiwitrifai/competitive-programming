#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  if (n > 2 * k) {
    puts("NO");
    return;
  }
  sort(s.begin(), s.end());
  for (int i = 1; i + 1 < n; ++i) {
    if (s[i-1] == s[i] && s[i] == s[i+1]) {
      puts("NO");
      return;
    }
  }
  puts("YES");
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
