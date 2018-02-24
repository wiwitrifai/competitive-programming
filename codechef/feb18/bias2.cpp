#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int id[N];
int n, m, l[N], r[N];
int a[N][N];
// Count Inversion
int bit[N];
int get(int x) {
  int res = 0;
  for (; x <= n; x += x&-x)
    res += bit[x];
  return res;
}
void upd(int x, int v = 1) {
  for (; x; x -= x&-x)
    bit[x] += v;
}
int countInversion() { // O(n log n)
  fill(bit, bit+n+1, 0);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += get(id[i]+1);
    upd(id[i]+1);
  }
  return res;
}
// Compare current best ans and guess
long long score[N];
bool cmp(int le, int ri) {
  if (score[le] == score[ri])
    return le < ri;
  return score[le] > score[ri];
}
int ans[N], v[N];
int best;
int calc() {  // O(n * (m + log n))
  for (int i = 0; i < n; ++i) {
    score[i] = 0;
    for (int j = 0; j < m; ++j) {
      score[i] += 1LL * a[i][j] * v[j];
    }
  }
  for (int i = 0; i < n; ++i)
    id[i] = i;
  sort(id, id+n, cmp);
  return countInversion();
}
void compare(int res) {
  if (best > res) {
    best = res;
    for (int i = 0; i < m; ++i)
      ans[i] = v[i];
  } 
}
// used for some heuristics
int inv[N], idsoal[N];
int main() {
  time_t startt = clock();
  srand(time(0));
  int t;
  scanf("%d", &t);
  for (int tt = 0; tt < t; ++tt) {
    // read
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d %d", l+i, r+i);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", a[i]+j);
      }
    }
    // initialize
    for (int i = 0; i < n; ++i) id[i] = i;
    best = 1e9;
    for (int i = 0; i < m; ++i) v[i] = (l[i] + r[i]) / 2;
    compare(calc());
    // some heuristic
    long long tot = 0;
    for (int i = 0; i < m; ++i) {
      sort(id, id+n, [&](int le, int ri){ return a[le][i] == a[ri][i] ? le < ri : a[le][i] < a[ri][i];});
      inv[i] = countInversion();
      tot += 1LL * n * (n-1) / 2 - inv[i];
    }
    for (int i = 0; i < m; ++i) {
      long long cur = 1LL * n * (n-1) / 2 - inv[i];
      v[i] = l[i] + 1LL * (r[i]-l[i]) * cur / tot;
      idsoal[i] = i;
    }
    compare(calc());
    sort(idsoal, idsoal+m, [&](int le, int ri) { return inv[le] == inv[ri] ? le < ri : inv[le] < inv[ri]; });
    for (int i = 0; i < m; ++i) {
      int u = idsoal[i];
      v[u] = l[u] + 1LL * (r[u] - l[u]) * (i) / m;
    }
    compare(calc());
    // all randoms
    while ((double)(clock() - startt) / CLOCKS_PER_SEC * 1000 + 50 < (double)3000 * (tt+1) / t) {
      for (int i = 0; i < m; ++i)
        v[i] = ans[i];
      int x = rand() % m;
      int y = 1LL * rand() * rand() % (r[x] - l[x] + 1);
      v[x] = l[x] + y;
      x = rand() % m;
      y = 1LL * rand() * rand() % (r[x] - l[x] + 1);
      v[x] = l[x] + y;
      y = 1LL * rand() * rand() % (r[x] - l[x] + 1);
      v[x] = l[x] + y;
      compare(calc());
    }
    for (int i = 0; i < m; ++i)
      printf("%d%c", ans[i], (i == m-1) ? '\n' : ' ');
  }
  return 0;
}