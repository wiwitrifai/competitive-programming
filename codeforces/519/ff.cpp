#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 2;

int a[N];
int p[N];
vector<int> prime;
int np[N], cnt[N];
bool ada[N];
bool siap[N];
long long sum[N];

int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}
vector<int> semua;

bool dfs(int x, int i, int v = 0) {
  if (v == 1)
    return true;
  if (x <= 0)
    return false;
  --x;
  while (i < semua.size()) {
    if (dfs(x, i+1, gcd(v, semua[i])))
      return true;
    ++i;
  }
  return false;
}

int main() {
  for (int i = 0; i < N; ++i)
    a[i] = i;
  for (int i = 2; i < N; ++i) {
    if (p[i]) continue;
    prime.push_back(i);
    for (int j = i; j < N; j += i) {
      if (p[j] == 0)
        p[j] = i;
      int now = a[j];
      while ((now % i) == 0)
        now /= i;
      now *= i;
      a[j] = now;
      ++np[j];
    }
  }
  for (int i = 2; i < N; ++i) {
    siap[a[i]] = 1;
  }
  int n;
  scanf("%d", &n);
  int g = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    x = a[x];
    ada[x] = 1;
    g = gcd(g, x);
  }
  if (g != 1) {
    puts("-1");
    return 0;
  }
  if (ada[1]) {
    puts("1");
    return 0;
  }
  int all = 0;
  for (int i = 2; i < N; ++i) {
    if (!ada[i]) continue;
    semua.push_back(i);
    for (int j = i+i; j < N; j += i)
      ada[j] = 0;
  }
  for (int i = 2; i < N; ++i) {
    if (!siap[i]) continue;
    for (int j = i; j < N; j += i)
      cnt[i] += ada[j];
  }
  for (int i = 2; i < N; ++i) {
    if (!siap[i]) continue;
    int now = (np[i] & 1) ? cnt[i] : -cnt[i];
    for (int j = i; j < N; j += i)
      sum[j] += now;
  }
  for (int x : semua) {
    if (sum[x] == semua.size()) continue;
    puts("2");
    return 0;
  }
  srand(time(0));
  random_shuffle(semua.begin(), semua.end());
  for (int i = 3; ; ++i ){
    if (dfs(i, 0)) {
      printf("%d\n", i);
      return 0;
    }
  }
  return 0;
}