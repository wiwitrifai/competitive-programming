#include <bits/stdc++.h>

using namespace std;

const int N = 55;

string s[N];
char buffer[N];

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n, k;
    long long v;
    scanf("%d %d %lld", &n, &k, &v);
    for (int i = 0; i < n; ++i) {
      scanf("%s", buffer);
      s[i] = string(buffer);
    }
    long long now = (v-1) * k % n;
    vector<pair<int, string> > ans;
    for (int i = 0; i < k; ++i) {
      while (now >= n) now %= n;
      ans.emplace_back(now, s[now]);
      ++now;
    }
    sort(ans.begin(), ans.end());
    printf("Case #%d:", tc);
    for (auto it : ans)
      printf(" %s", it.second.c_str());
    printf("\n");
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
  }
  return 0;
}