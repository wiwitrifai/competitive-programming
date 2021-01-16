#include <bits/stdc++.h>

using namespace std;

void inverse_row(vector<vector<int>> & x) {
  int n = x.size();
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      p[x[i][j]] = j;
    }
    for (int j = 0; j < n; ++j) {
      x[i][j] = p[j];
    }
  }
}

void inverse_col(vector<vector<int>> & x) {
  int n = x.size();
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      p[x[j][i]] = j;
    }
    for (int j = 0; j < n; ++j) {
      x[j][i] = p[j];
    }
  }
}

void print(vector<vector<int>> & x) {
  int n = x.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d%c", x[i][j]+1, j+1 == n ? '\n' : ' ');
    }
  }
}

void move_row(vector<vector<int>> & x, int off) {
  int n = x.size();
  off %= n;
  if (off < 0)
    off += n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      p[j] = x[i][j];
    }
    for (int j = 0; j < n; ++j) {
      x[i][(j+off) % n] = p[j];
    }
  }
}


void move_col(vector<vector<int>> & x, int off) {
  int n = x.size();
  off %= n;
  if (off < 0)
    off += n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      p[j] = x[j][i];
    }
    for (int j = 0; j < n; ++j) {
      x[(j+off) % n][i] = p[j];
    }
  }
}

void add_value(vector<vector<int>> & x, int add) {
  int n = x.size();
  add %= n;
  if (add < 0)
    add += n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      x[i][j] = (x[i][j] + add) % n;
    }
  }
}

const int N = 1e5 + 5;

char s[N];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> x(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &x[i][j]);
      --x[i][j];
    }
  }
  scanf("%s", s);
  string st;
  for (int i = 0; i < m; ++i) {
    if (s[i] == 'I') {
      inverse_row(x);
    }
    else if (s[i] == 'C') {
      inverse_col(x);
    } else if (s[i] == 'L') {
      move_row(x, -1);
    } else if (s[i] == 'R') {
      move_row(x, +1);
    } else if (s[i] == 'U') {
      move_col(x, -1);
    } else if (s[i] == 'D') {
      move_col(x, +1);
    } else {
      assert(false);
    }
  }
  print(x);
  cerr << endl;
}

int main() {  
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
