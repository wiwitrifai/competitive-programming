#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

typedef pair< int, int > ii;

int t, n, d[N], x[N][N], ptr[N], p[N];

int root(int u) {
  if(p[u] < 0) return u;
  return p[u] = root(p[u]);
}
bool merge(int u, int v) {
  if((u = root(u)) == (v = root(v)))
    return false;
  if(p[u] < p[v])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  return true;
}

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
      p[i] = -1, ptr[i] = 1;
    for(int i = 0; i<n; i++) {
      for(int j = 0; j<n; j++) {
        scanf("%d", x[i]+j);
        x[i][j]--;
      }
    }
    int m = n-1;
    for(int i = 0; i<n; i++)
      if(merge(i, x[i][0])) {
        printf("%d %d\n", i+1, x[i][0]+1);
        m--;
      }
    while(m) {
      for(int i = 0; i<n; i++)
        d[i] = -1;
      for(int i = 0; i<n; i++) {
        int &u = ptr[i];
        int r = root(i);
        while(u<n && r == root(x[i][u])) u++;
        int v = x[i][u];
        if(d[v] == i) {
          printf("%d %d\n", i+1, v+1);
          m--;
          if(m == 0)
            break;
          merge(i, v);
        }
        d[i] = v;
      }
    }
    puts("\n");
  }
  return 0;
}