#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long calc(string s) {
  int n = s.size();
  long long ans = 0;
  for (int j = 0; j < n; ++j) {
    long long cur = 0;
    char last = 'F';
    for (int i = j; i < n; ++i) {
      char c = s[i];
      if (c == 'O') {
        cur += last == 'X';
        last = c;
      } else if (c == 'X') {
        cur += last == 'O';
        last = c;
      }
      ans += cur;
    }
  }
  return ans;
}

void solve() {
  int n;
  string s;
  cin >> n >> s;
  string p;
  char last = 'F';
  int last_pos = -1;
  long long ans = 0, add = 0;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c == 'O') {
      if (last == 'X') {
        add += last_pos + 1;
      }
      last = c;
      last_pos = i;
    } else if (c == 'X') {
      if (last == 'O') {
        add += last_pos + 1;
      }
      last = c;
      last_pos = i;
    }
    add %= mod;
    ans = (ans + add) % mod;
  }
  cout << ans << endl;
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
