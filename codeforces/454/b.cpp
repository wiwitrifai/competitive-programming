#include <bits/stdc++.h>

using namespace std;

bool neigh(int x, int y, int m) {
  if (x > y) swap(x, y);
  if (y == x + m) return true;
  if ((y % m) == 0) return false;
  if (y == x + 1) return true;
  return false;
}

typedef vector<vector<int> > Mat;

bool cek(Mat mat) {
  set<int> used;
  int n = mat.size(), m = mat[0].size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (i && neigh(mat[i][j], mat[i-1][j], m)) return false;
      if (j && neigh(mat[i][j], mat[i][j-1], m)) return false;
      used.insert(mat[i][j]);
    }
  return used.size() == n * m && (*used.begin()) == 0 && (*used.rbegin()) == (n*m-1);
}

Mat transpose(Mat x) {
  int n = x.size(), m = x[0].size();
  Mat res(m, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int now = x[n-1-j][i];
      res[i][j] = (now % m) * n + (now / m);
    }
  }
  return res;
}

vector<vector<int> > generate(int n, int m) {
  if (n > m) {
    Mat res = generate(m, n);
    if (res.size() > 0)
      return transpose(res);
    return res;
  }
  if (n == 1) {
    if (m == 1) {
      return Mat(1, vector<int>(1, 0));
    }
    if (m < 4) return Mat();
    Mat res(1, vector<int>(m, 0));
    for (int i = 0, j = 1; i < m; ++i, j += 2) {
      if (j >= m) j = 0;
      res[0][i] = j;
    }
    return res;
  }
  else if (n == 2) {
    if (m < 4) return Mat();
    if (m == 4) {
      return {{0,2,4,1},{7,5,3,6}};
    }
    Mat res(2, vector<int> (m, 0));
    Mat col = generate(1, m);
    for (int i = 0; i < m; ++i) {
      res[0][i] = col[0][i];
      res[1][i] = m + col[0][(i + 1) % m];
    }
    return res;
  }
  else if (n == 3) {
    if (m < 3) return Mat();
    if (m == 3) {
      return {{0,2,3}, {4,6,5},{8,1,7}};
    }
    if (m == 4) {
      return {{0,2,4,1},{3,5,11,8},{10,7,9,6}};
    }
    Mat res(3, vector<int> (m, 0));
    Mat col = generate(1, m);
    for (int i = 0; i < m; ++i) {
      res[0][i] = col[0][i];
      res[1][i] = m + col[0][(i + 1) % m];
      res[2][i] = 2 * m + col[0][(i + 2) % m];
    }
    return res;
  }
  Mat res(n, vector<int> (m, 0));
  Mat col = generate(1, m);
  Mat row = generate(1, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      res[i][j] = col[0][j] + row[0][i] * m;
    }
  }
  return res;
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Mat ans = generate(n, m);
  if (ans.empty())
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d%c", ans[i][j]+1, (j == m-1) ? '\n' : ' ');
      }
    }
    // assert(cek(ans));
  }
  return 0;
}