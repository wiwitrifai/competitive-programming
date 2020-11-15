// WA

#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int go[N][2], suf[N];

char s[N], t[N];
double p[2];
int nodes = 0;

int add(char x[N]) {
  int len = strlen(x);
  int now = 0;
  for (int i = 0; i < len; ++i) {
    int to = 0;
    if (x[i] == 'H')
      to = 1;
    if (go[now][to] == 0) {
      go[now][to] = ++nodes;
    }
    now = go[now][to];
  }
  return now;
}

vector<int> que;

void bfs() {
  for (int i = 0; i < 2; ++i)
    if (go[0][i])
      que.push_back(go[0][i]);
  for (int j = 0; j < (int)que.size(); ++j) {
    int v = que[j];
    for (int i = 0; i < 2; ++i) {
      if (go[v][i]) {
        int w = suf[v];
        while (w && go[w][i] == 0) {
          w = suf[w];
        }
        suf[go[v][i]] = go[w][i];
        que.push_back(go[v][i]);
      }
    }
  }
}

bool done[N];
template<typename T>
struct matrix {
  int n, m;
  T a[N][N];
  matrix(int n, int m) : n(n), m(m) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        a[i][j] = 0;
  }
  void reset() {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        a[i][j] = (i == j);
  }
  const T * operator[](const int id) const {
    return a[id];
  }
  T * operator[](const int id) {
    return a[id];
  }
  matrix operator*(const matrix& mat) const {
    matrix ret(this->n, mat.m);
    for(int i = 0; i < this->n; ++i) {
      for(int j = 0; j < mat.m; ++j) {
        T now = 0;
        for(int k = 0; k<this->m; ++k) {
          now = (now + (T)this->a[i][k] * mat[k][j]);
        }
        ret[i][j] = now;
      }
    }
    return ret;
  }
  matrix operator^(long long pw) const {
    matrix ret(n, m), base = *this;
    ret.reset();
    while(pw) {
      if(pw & 1)
        ret = ret*base;
      base = base*base;
      pw >>= 1;
    }
    return ret;
  }
};

template<typename T>
ostream& operator<<(ostream& os, const matrix<T> & mat) {
  for(int i = 0; i < mat.n; ++i) {
    for(int j = 0; j < mat.m; ++j)
      os << mat.a[i][j] << " ";
    os << endl;
  }
  return os;
}
bool lose() {
  int n = strlen(s), m = strlen(t);
  for (int i = 0; i + m <= n; ++i) {
    bool ok = 1;
    for (int j = 0; j < m; ++j) {
      if (s[i+j] != t[j]) {
        ok = 0;
        break;
      }
    }
    if (ok)
      return true;
  }
  return false;
}

int main() {
  scanf("%s %s", s, t);
  int gon = add(s), killua = add(t);
  scanf("%lf", p+1);
  p[0] = 1 - p[1];
  if (lose()) {
    puts("0");
    return 0;
  }
  bfs();
  ++nodes;
  matrix<long double> mat(nodes, nodes);
  for (int i = 0; i < nodes; ++i) {
    if (i == gon || i == killua) {
      mat[i][i] += 1;
      continue;
    }
    for (int j = 0; j < 2; ++j) {
      int w = i;
      while (w && go[w][j] == 0) w = suf[w];
      mat[go[w][j]][i] += p[j];
    }
  }
  matrix<long double> awal(nodes, 1);
  awal[0][0] = 1;
  long long pw = 10000000000LL;
  for (int i = 0; i < 10; ++i)
    mat = mat ^ pw;
  mat = mat * awal;
  double ans = mat[gon][0];
  printf("%.20lf\n", ans);
  return 0;
}
