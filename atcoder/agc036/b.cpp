#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5, LG = 61;
const long long inf = 1LL << LG;

int a[N];
int to[N];
long long go[LG][N];
int last[N];

int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n; ++i) {
    a[n+i] = a[i];
  }
  fill(last, last+N, 2 * n);
  for (int i = 2 * n-1; i >= n; --i) {
    last[a[i]] = i;
  }
  for (int i = n-1; i >= 0; --i) {
    to[i] = last[a[i]] - i + 1;
    last[a[i]] = i;
  }
  for (int i = 0; i < n; ++i)
    go[0][i] = to[i];
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j < n; ++j) {
      go[i+1][j] = min(go[i][j] + go[i][(j+go[i][j]) % n], inf);
    }
  }
  long long cur = 0;
  long long tot = 1LL * k * n;
  for (int i = LG-1; i >= 0; --i) {
    if (cur + go[i][cur % n] < tot) {
      cur += go[i][cur % n];
    }
  }
  cur %= n;
  vector<int> ans;
  memset(last, -1, sizeof last);
  for (int i = cur; i < n; ++i) {
    if (last[a[i]] != -1) {
      while (1) {
        int cur = ans.back();
        ans.pop_back();
        last[cur] = -1;
        if (cur == a[i])
          break;
      }
    }
    else {
      last[a[i]] = i;
      ans.push_back(a[i]);
    }
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    if (i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
