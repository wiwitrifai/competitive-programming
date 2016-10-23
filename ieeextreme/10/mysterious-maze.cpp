/**
  IEEExtreme Programming Contest 10
  Problem : Mysterious Maze
  Solver  : Luqman Arifin S
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int di[] = {0, 0, -1, 1};
int dj[] = {1, -1, 0, 0};

int a[N][N];
int par[N * N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      par[i * N + j] = i * N + j;
    }
  }
  //puts("mau");
  for (int j = 1; j <= n; j++) {
    merge(j, j + 1);
    merge((n + 1) * N + j + 1, (n + 1) * N + j);
    a[0][j] = 1;
    a[n + 1][j] = 1;
  }
  int now = 0;
  while (1) {
    int u, v;
    scanf("%d", &u);
    if (u == -1) break;
    scanf("%d", &v);
    for (int i = 0; i < 4; i++) {
      int ti = u + di[i];
      int tj = v + dj[i];
      if (a[ti][tj]) {
        merge(u * N + v, ti * N + tj);
      }
    }
    a[u][v] = 1;
    now++;
    //puts("masih bisa");
    if (find(1) == find((n + 1) * N + 1)) {
      printf("%d\n", now);
      return 0;
    }
    /*
    printf("%d %d\n", find(1), find((n + 1) * N + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        printf("%d ", find(i * N + j));
      }
      printf("\n");
    }
    puts("");
    */
  }
  puts("-1");
  return 0;
}
