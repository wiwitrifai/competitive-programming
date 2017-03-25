#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 6;
int p[N];
int f[N];
bool used[N];

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return false;
  if (-p[u] > -p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
} 

int main() {
  f[1] = 1;
  for (int i = 2; i < N; i++) if (f[i] == 0) {
    for (int j = i; j < N; j+= i)
      if (f[j] == 0)
        f[j] = i;
  }
  memset(p, -1, sizeof p);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    int last = -1;
    while (a > 1) {
      int now = f[a];
      used[now] = 1;
      if (last != -1) {
        merge(last, now);
      }
      while ((a % now) == 0)
        a /= now;
      last = now;
    }
  }
  set< int > st;
  for (int i = 0; i < N; i++) if (used[i]) {
    st.insert(find(i));
  }
  printf("%d\n", st.size());
  return 0;
}