#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int c[N][N], b[N][N];
int artp[N * N], ada[N * N];
int num[N * N], low[N * N], cntr;
int n, p, root, rchild;

inline bool valid(int x, int y) {
  return min(x, y) >= 0 && max(x, y) < n;
}
inline int enc(int x, int y) {
  return x * n + y;
}
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

#define bir 1
#define mer 2

void dfs(int v, int par = -1) {
  num[v] = low[v] = ++cntr;
  int x = v/n, y = v % n;
  ada[v] = (b[x][y] == 1);
  for (int i = 0; i < 4; ++i) {
    int xx = x + dx[i], yy = y + dy[i];
    if (!valid(xx, yy)) continue;
    if (c[xx][yy] == -1 || c[xx][yy] == mer) continue;
    int u = enc(xx, yy);
    if (u == par) continue;
    if (num[u] == -1) {
      dfs(u, v);
      ada[v] |= ada[u];
      if (v == root) ++rchild;
      if (ada[u] && low[u] >= num[v])
        artp[v] = 1;
      low[v] = min(low[v], low[u]);
    }
    else
      low[v] = min(num[u], low[v]);
  }
  // cerr << x << " " << y << " " << num[v] << " " << low[v] << endl;
}


bool sudah[N * N];
int pre[N * N];

char s[N];

void print() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char res = c[i][j] <= 0 ? (c[i][j] == -1 ? '-' : '?') : (c[i][j] == 1 ? 'B' : 'M');
      if (res == 'B' && b[i][j] != 1)
        res = 'B';
      if (res == 'M' && b[i][j] != 2)
        res = 'M';
      printf("%c", res);
    }
    printf("\n");
  }
}

void print_err() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cerr << (c[i][j] <= 0 ? (c[i][j] == -1 ? '-' : '?') : (c[i][j] == 1 ? 'B' : 'M'));
    }
    cerr << endl;
  }
}


int main() {
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    if (s[0] == '0') {
      for (int j = 0; j < n; ++j)
        c[j][i] = -1;
    }
    else if (s[0] != '-') {
      int len = strlen(s);
      int d = 0;
      --len;
      for (int j = 0; j < len; ++j)
        d = (s[j] - '0') + d * 10;
      --d;
      for (int j = 0; j < d; ++j)
        c[j][i] = -1;
      if (s[len] == 'B')
        c[d][i] = 1;
      else
        c[d][i] = 2;
    }
  }
  for (int i = 0; i < n; ++i) {
    {
      scanf("%s", s);
      if (s[0] == '0') {
        for (int j = 0; j < n; ++j)
          c[i][j] = -1;
      }
      else if (s[0] != '-') {
        int len = strlen(s);
        int d = 0;
        --len;
        for (int j = 0; j < len; ++j)
          d = (s[j] - '0') + d * 10;
        --d;
        for (int j = 0; j < d; ++j)
          c[i][j] = -1;
        if (s[len] == 'B')
          c[i][d] = 1;
        else
          c[i][d] = 2;
      }
    }

    {
      scanf("%s", s);
      if (s[0] == '0') {
        for (int j = 0; j < n; ++j)
          c[i][j] = -1;
      }
      else if (s[0] != '-') {
        int len = strlen(s);
        int d = 0;
        --len;
        for (int j = 0; j < len; ++j)
          d = (s[j] - '0') + d * 10;
        --d;
        for (int j = 0; j < d; ++j)
          c[i][n-1-j] = -1;
        if (s[len] == 'B')
          c[i][n-1-d] = 1;
        else
          c[i][n-1-d] = 2;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    if (s[0] == '0') {
      for (int j = 0; j < n; ++j)
        c[j][i] = -1;
    }
    else if (s[0] != '-') {
      int len = strlen(s);
      int d = 0;
      --len;
      for (int j = 0; j < len; ++j)
        d = (s[j] - '0') + d * 10;
      --d;
      for (int j = 0; j < d; ++j)
        c[n-1-j][i] = -1;
      if (s[len] == 'B')
        c[n-1-d][i] = 1;
      else
        c[n-1-d][i] = 2;
    }
  }
  // print_err();
  vector<int> biru, merah;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      b[i][j] = c[i][j];
      if (b[i][j] == bir)
        biru.push_back(enc(i, j));
      else if (b[i][j] == mer)
        merah.push_back(enc(i, j));
    }
  // print();
  for (int z : merah) {
    memset(artp, 0, sizeof artp);
    memset(num, -1, sizeof num);
    memset(low, -1, sizeof low);
    memset(ada, 0, sizeof ada);
    cntr = 0;
    for (int v : biru) {
      if (num[v] != -1) continue;
      root = v;
      rchild = 0;
      dfs(root);
      artp[v] = rchild > 1;
    }
    // cerr << " merah " << z/n << " " << z%n << endl;
    for (int i = 0; i < n * n; ++i) {
      artp[i] &= ada[i];
      ada[i] = 0;
      // if (artp[i]) cerr << i/n << " " << i%n << endl;
    }
    queue<int> que;
    que.push(z);
    memset(pre, -1, sizeof pre);
    pre[z] = z;
    int found = -1;
    while (!que.empty() && found == -1) {
      int v = que.front(); que.pop();
      int x = v / n, y = v % n;
      for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!valid(xx, yy) || c[xx][yy] == -1 || c[xx][yy] == bir) continue;
        int u = enc(xx, yy);
        if (artp[u] || pre[u] != -1) continue;
        pre[u] = v;
        que.push(u);
        if (sudah[u])
          found = u;
      }
    }
    if (found != -1) {
      int v = found;
      while (v != z) {
        c[v / n][v % n] = mer;
        v = pre[v];
      }
    }
    sudah[z] = 1;
  }
  for (int z : biru) {
    c[z/n][z%n] = 0;
  }
  for (int z : biru) {
    int x = z/n, y = z % n;
    if (c[x][y] == bir) continue;
    queue<int> que;
    que.push(z);
    c[x][y] = bir;
    while (!que.empty()) {
      int v = que.front(); que.pop();
      x = v/n, y = v%n;
      for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!valid(xx, yy) || c[xx][yy] != 0) continue;
        int u = enc(xx, yy);
        c[xx][yy] = bir;
        que.push(u);
      }
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (c[i][j] == 0)
        c[i][j] = -1;
  print();
  return 0;
}