#include <bits/stdc++.h>

using namespace std;

void openfile(string name) {
#ifndef LOCAL
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
#endif
}
void closefile() {
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
}

const int mod = 1e9 + 7;
struct matrix {
  vector< vector< int > > a;
  int n, m;
  matrix(int n, int m) : n(n), m(m), a(n, vector< int >(m, 0)) {
    for (int i = min(n, m)-1; i >= 0; i--)
      a[i][i] = 1;
  }
  matrix operator+(const matrix & other) const {
    matrix ret(n, m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        ret.a[i][j] = a[i][j] + other.a[i][j];
        if (ret.a[i][j] >= mod)
          ret.a[i][j] -= mod;
      }
    return ret;
  }
  matrix operator*(const matrix & other) const {
    matrix ret(n, other.m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < other.m; j++) {
        int & cur = ret.a[i][j];
        cur = 0;
        for (int k = 0; k < m; k++) {
          cur = (cur + 1LL * a[i][k] * other.a[k][j]) % mod;
        }
      }
    }
    return ret;
  }
  matrix operator^(long long pw) const {
    matrix ret(n, m);
    matrix b = *this;
    for (; pw; pw>>=1, b = b*b)
      if (pw & 1) ret = ret * b;
    return ret;
  }
  void debug() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cerr << a[i][j] << " ";
      cerr << endl;
    }
  }
};
vector< string > lines;
vector< string > tokenize(string s) {
  istringstream iss(s);
  return vector<string>{istream_iterator<string>{iss}, istream_iterator<string>{}};
}
bool lower(char c) {
  return c >= 'a' && c <= 'z';
}
int n = 0, id;
map< string, int > mp;
matrix dfs() {
  matrix ret(n+1, n+1);
  vector< string > tokens = tokenize(lines[id]);
  if (lower(tokens[0][0])) {
    int pos = mp[tokens[0]];
    for (int i = 0; i <= n; i++)
      ret.a[pos][i] = 0;
    for (int i = 2; i < tokens.size(); i++) {
      string cur = tokens[i];
      if (cur[0] == '(' || cur[0] == ')' || cur[0] == '+') continue;
      if (lower(cur[0]))
        ret.a[pos][mp[cur]]++;
      else {
        ret.a[pos][n] += stoi(cur);
      }
    }
    id++;
    return ret;
  }
  else {
    int pw = stoi(tokens[0]);
    id++;
    while (id < lines.size()) {
      if (lines[id].back() == '}')
        break;
      ret = dfs() * ret;
    }
    id++;
    ret = ret ^ pw;
    return ret;
  }
}

int main() {
  openfile("cowbasic");
  string s;
  while (getline(cin, s)) {
    lines.push_back(s);
    vector< string > tokens = tokenize(s);
    if (lower(tokens[0][0]) && !mp.count(tokens[0])) {
      mp[tokens[0]] = n++;
    }
  }
  string last = lines.back();
  lines.pop_back();
  string ret = tokenize(last).back();
  matrix res(n+1, 1);
  for (int i = 0; i <= n; i++)
    res.a[i][0] = 1;
  id = 0;
  while (id < lines.size()) {
    res = dfs() * res;
  }
  printf("%d\n", res.a[mp[ret]][0]);
  closefile();
  return 0;
}