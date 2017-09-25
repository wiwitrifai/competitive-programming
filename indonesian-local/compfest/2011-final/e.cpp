#include <bits/stdc++.h>

using namespace std;


const int N = 24;
int mod;

struct matrix {
  int a[N][N];
  matrix() {
    memset(a, 0, sizeof a);
  }
  int * operator[](int id) {
    return a[id];
  }
  matrix operator*(matrix& m) {
    matrix res;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        long long now = 0;
        for (int k = 0; k < N; k++) {
          now = (now + 1LL * a[i][k] * m[k][j]) % mod;
        }
        res[i][j] = now;
      }
    }
    return res;
  }
  matrix operator^(int k) {
    matrix res;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        res[i][j] = (i == j);
    for (matrix base = *this; k; k >>= 1, base = base * base)
      if (k & 1) res = res * base;
    return res;
  }
};

pair<int, int> edge[] = {{1, 2}, {1, 5}, {1, 4}, {2, 3}, {2, 6}, {3, 4}, {3, 7}, {4, 8}, {5, 6}, {5, 8}, {6, 7}, {7, 8}};

int main() {
  int t;
  scanf("%d", &t);
  matrix a;
  for (int i = 0; i < 12; i++) {
    int v = edge[i].first;
    for (int j = 0; j < 12; j++) {
      if (j == i) continue;
      if (edge[j].first == v)
        a[j*2+1][i*2] = 1;
      if (edge[j].second == v)
        a[j*2][i*2] = 1;
    }
    v = edge[i].second;
    for (int j = 0; j < 12; j++) {
      if (j == i) continue;
      if (edge[j].first == v)
        a[j*2+1][i*2+1] = 1;
      if (edge[j].second == v)
        a[j*2][i*2+1] = 1;
    }
  }
  while (t--) {
    char s[10];
    int u, v, k;
    scanf("%s", s);
    u = s[0] - 'A' + 1;
    scanf("%s", s);
    v = s[0] - 'A' + 1;
    matrix b;
    scanf("%d %d", &k, &mod);
    for (int j = 0; j < 12; j++) {
      if (edge[j].first == u)
        b[j*2+1][0] = 1;
      if (edge[j].second == u)
        b[j*2][0] = 1;
    }
    k--;
    matrix res = (a ^ k) * b;
    int ans = 0;
    for (int i = 0; i < 12; i++) {
      if (edge[i].first == v)
        ans = (ans + res[i*2][0]) % mod;
      if (edge[i].second == v)
        ans = (ans + res[i*2+1][0]) % mod;
    }
    if (ans < 0) ans += mod;
    printf("%d\n", ans);
  }  
}