#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const double eps = 1e-2;

pair<int, vector<double> > gauss(vector<vector<double>> a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    double maxEl = abs(a[i][i]);
    double maxRow = i;
    for (int k = i + 1; k < n; k++) {
      if (abs(a[k][i]) > maxEl) {
        maxEl = abs(a[k][i]);
        maxRow = k;
      }
    }
    for (int k = i; k < n + 1; k++) {
      double tmp = a[maxRow][k];
      a[maxRow][k] = a[i][k];
      a[i][k] = tmp;
    }
    for (int k = i + 1; k < n; k++) {
      double c = -a[k][i] / a[i][i];
      for (int j = i; j < n + 1; j++) {
        if (i == j) {
          a[k][j] = 0;
        } else {
          a[k][j] += c * a[i][j];
        }
      }
    }
  }
  vector<double> x(n);
  for (int i = n - 1; i >= 0; i--) {
    if (abs(a[i][i]) < eps) return {false, x};
    x[i] = a[i][n] / a[i][i];
    for (int k = i - 1; k >= 0; k--) {
      a[k][n] -= a[k][i] * x[i];
    }
  }
  return {true, x};
}

double power(double a, int b) {
  if (b == 0) return 1;
  double tmp = power(a, b / 2);
  tmp = tmp * tmp;
  if (b & 1) tmp = tmp * a;
  return tmp;
}

double p[N];

int main() {
  int n;
  while (scanf("%d", &n) && n) {
    //puts("----TC----");
    int k = n + 3;
    for (int i = 0; i < k; i++) scanf("%lf", p + i);
    bool done = 0;
    for (int skip = 0; skip < k; skip++) {
      vector<vector<double>> a;
      for (int i = 0; i < k; i++) {
        if (i == skip) continue;
        vector<double> t;
        for (int j = n; j >= 0; j--) {
          t.push_back(power(i, j));
        }
        t.push_back(p[i]);
        a.push_back(t);
      }
      /*
      for (auto i : a) {
        for (auto j : i) {
          printf("%.15f ", j);
        }
        printf("\n");
      }
      */
      vector<double> b = a.back();
      a.pop_back();
      auto it = gauss(a);
      if (it.first) {
        auto x = it.second;
        //cout << "skip " << skip << endl;
        //for (auto i : x) printf("%.15f\n", i);
        a.push_back(b);
        bool konsisten = 1;
        for (auto it : a) {
          double cur = 0;
          for (int j = 0; j + 1 < it.size(); j++) {
            cur += x[j] * it[j];
          }
          //printf("nani kore %.15f %.15f\n", cur, it.back());
          if (abs(cur - it.back()) > eps) {
            konsisten = 0;
            break;
          }
        }
        //printf("skip %d konsisten %d\n", skip, konsisten);
        if (konsisten) {
          cout << skip << endl;
          done = 1;
          break;
        }
      }
    }
    assert(done);
  }

  return 0;
}