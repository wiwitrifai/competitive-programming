#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

const int K = 7;

struct Matrix {
  vector<vector<long long>> a;

  Matrix(vector<vector<long long>> v) {
    a = v;
  }

  Matrix() {
    a = vector<vector<long long>>(K, vector<long long>(K, 0));
    for (int i = 0; i < K; ++i)
      a[i][i] = 1;
  }

  Matrix operator*(Matrix b) {
    Matrix res;
    for (int i = 0; i < K; ++i) {
      for (int j = 0; j < K; ++j) {
        long long val = 0;
        for (int k = 0; k < K; ++k) {
          val = (val + a[i][k] * b.a[k][j]) % mod;
        }
        res.a[i][j] = val;
      }
    }
    return res;
  }
  vector<long long>& operator[](int x) {
    return a[x];
  }
};

ostream& operator<<(ostream& os, const Matrix & m) {
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < K; ++j) {
      if (j)
        os << ' ';
      os << m.a[i][j];
    }
    os << '\n';
  }
  return os;
}

void solve() {
  // ans, dp_x, dp_o, last_pos_x, last_pos_o, acc_f_x, 1
  Matrix acc_ans;
  acc_ans[0][1] = acc_ans[0][2] = 1;

  Matrix set_dp_x;
  set_dp_x[1][2] = set_dp_x[1][4] = 1;
  set_dp_x[2][2] = 0;

  Matrix set_dp_o;
  set_dp_o[2][1] = set_dp_o[1][3] = 1;
  set_dp_o[1][1] = 0;

  Matrix set_last_x;
  set_last_x[3][4] = set_last_x[3][5] = set_last_x[3][6] = 1;
  set_last_x[4][4] = 0;

  Matrix set_last_o;
  set_last_o[4][3] = set_last_o[4][5] = set_last_o[4][6] = 1;
  set_last_o[3][3] = 0;

  Matrix add_acc;
  add_acc[5][6] = 1;

  Matrix reset_acc;
  reset_acc[5][5] = 0;


  Matrix x = acc_ans * reset_acc * set_last_x * set_dp_x;
  Matrix o = acc_ans * reset_acc * set_last_o * set_dp_o;
  Matrix f = acc_ans * add_acc;
  Matrix init;
  for (int i = 0; i < K; ++i)
    init[i][i] = 0;
  init.a[K-1][0] = 1;
  int n;
  string s;
  cin >> n >> s;
  Matrix cur;
  for (int i = 0; i < K; ++i)
    cur.a[i][i] = 1;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c == 'O') {
      cur = o * cur;
    } else if (c == 'X') {
      cur = x * cur;
    } else if (c == 'F') {
      cur = f * cur;
    } else {
      cur = cur * cur;
    }
  }
  cur = cur * init;
  cout << cur.a[0][0] << endl;
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
