#include <bits/stdc++.h>

using namespace std;

const int N = 256;

int a[N][N], b[N][N];
int u[N * N], v[N * N];
int n, m;
int p[N], ansp[N];

long long calc() {
  long long sa = 0, sb = 0;
  for (int i = 0; i < m; ++i) {
    int x = p[u[i]], y = p[v[i]];
    sa += a[x][y];
    sb += b[x][y];
  }
  return sa * sb;
}

int main() {
  srand(time(0));
  time_t startt = clock();
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", a[i]+j);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", b[i]+j);
  for (int i = 0; i < m; ++i)
    scanf("%d %d", u+i, v+i);
  for (int i = 0; i < n; ++i)
    ansp[i] = p[i] = i;
  long long best = calc();
  int k = n * n * n; 
  while ((clock() - startt) * 1000 / CLOCKS_PER_SEC < 1945) {
    int reset = 0 && !(rand() % 100);
    if (reset) {
      for (int i = 0; i < n; ++i) p[i] = i;
      random_shuffle(p, p+n);
    }
    else {
      k /= 2;
      k = max(k, 1);
      k += !(rand() & 1);
      for (int i = 0; i < n; ++i) p[i] = ansp[i];
      for (int i = 0; i < k; ++i) {
        int x = rand() % n, y = rand() % n;
        swap(p[x], p[y]);
      }
    }
    long long cur = calc();
    if (cur < best) {
      best = cur;
      for (int i = 0; i < n; ++i)
        ansp[i] = p[i];
    }
  }
  cerr << best << endl;
  for (int i = 0; i < n; ++i)
    printf("%d%c", ansp[i], i == n-1 ? '\n' : ' ');
  return 0;
}