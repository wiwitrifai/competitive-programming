#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

int p[N], used[N], match[N];
int a[N], b[N];
int n, m;
void ask(int x) {
  printf("%d\n", x+1);
  fflush(stdout);
}

int get() {
  int x;
  scanf("%d", &x);
  return x;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 2 * n; ++i)
    scanf("%d", p+i);
  fill(match, match+2*n+1, -1);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", a+i, b+i);
    --a[i], --b[i];
    match[a[i]] = b[i];
    match[b[i]] = a[i];
    if (p[a[i]] < p[b[i]])
      swap(a[i], b[i]);
  }
  int g;
  scanf("%d", &g);
  --g;
  int last = 2 * n;
  for (int i = 0; i < 2 * n; ++i) {
    // for (int j = 0; j < 2 * n; ++j)
    //   cerr << used[j];
    // cerr << endl;
    if ((i & 1) == g) {
      if (match[last] != -1 && !used[match[last]]) {
        ask(match[last]);
        used[match[last]] = 1;
      }
      else {
        int pil = -1;
        for (int j = 0; j < m; ++j) {
          if (used[a[j]]) continue;
          pil = a[j];
        }
        if (pil == -1) {
          for (int j = 0; j < 2 * n; ++j) {
            if (used[j]) continue;
            if (pil == -1 || p[j] > p[pil])
              pil = j;
          }
        }
        ask(pil);
        used[pil] = 1;
      }
    }
    else {
      int x = get();
      --x;
      used[x] = 1;
      last = x;
    }
  }
  return 0;
}