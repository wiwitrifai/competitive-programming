#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int fp[N];
vector<int> pw[N];
vector<int> prime;

int main() {
  for (int i = 2; i < N; ++i) {
    if (fp[i]) continue;
    prime.push_back(i);
    for (int j = i; j < N; j += i)
      if (fp[j] == 0)
        fp[j] = i;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int p : prime)
      pw[p].clear();
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      while (a > 1) {
        int p = fp[a];
        int cnt = 0;
        while ((a % p) == 0)
          a /= p, ++cnt;
        pw[p].push_back(cnt);
      }
    }
    long long ans = 1;
    for (int p : prime) {
      int sum = 0;
      for (int v : pw[p])
        sum += v;
      int best = 1;
      while (1) {
        int ada = 0;
        for (int v : pw[p]) {
          int butuh = min(v, best);
          ada += butuh + (v - butuh) / 2;
        }
        // cerr << p << " " << ada << " " << best << " "  << n << endl;
        if (ada < best * n)
          break;
        // cerr << " lanjut " << endl;
        ++best;
        ans *= p;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}