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
  int offr = 0, offc = 0;
  int add = 0;
  string st;
  for (int i = 0; i < m; ++i) {
    if (s[i] == 'I') {
      swap(offr, add);
      if (!st.empty() && st.back() == 'I')
        st.pop_back();
      else
        st.push_back('I');
    }
    else if (s[i] == 'C') {
      swap(offc, add);
      if (!st.empty() && st.back() == 'C')
        st.pop_back();
      else
        st.push_back('C');
    } else if (s[i] == 'L') {
      --offr;
    } else if (s[i] == 'R') {
      ++offr;
    } else if (s[i] == 'U') {
      --offc;
    } else if (s[i] == 'D') {
      ++offc;
    } else {
      assert(false);
    }
  }
  auto origin = x;
  int now = 0;
  bool jump = false;
  while (now < (int)st.size()) {
    if (!jump && now > 0 && x == origin && (now & 1) == 0) {
      int cycle = now;
      int len = st.size();
      int r = len % cycle;
      now = len - r;
      jump = true;
      continue;
    }
    if (st[now] == 'I')
      inverse_row(x);
    else
      inverse_col(x);
    ++now;
  }
  move_row(x, offr);
  move_col(x, offc);
  add_value(x, add % n);
  print(x);
}

int main() {  
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
