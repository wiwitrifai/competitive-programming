// by luqman
#include <bits/stdc++.h>

using namespace std;
const string filename = "jenga";
const int N = 5005;
const double eps = 1e-7;

struct bit_double {
  bit_double() {}
  bit_double(int n) : n(n) {
    a.assign(n + 1, 0);
  }
  void add(int i, double val) {
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      a[i] += val;
    }
  }
  double find(int i) {
    double ret = 0;
    for (; i <= n; i |= i + 1) ret += a[i];
    return ret;
  } 
  int n;
  vector<double> a;
};

struct bit_int {
  bit_int() {}
  bit_int(int n) : n(n) {
    a.assign(n + 1, 0);
  }
  void add(int i, int val) {
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      a[i] += val;
    }
  }
  int find(int i) {
    int ret = 0;
    for (; i <= n; i |= i + 1) ret += a[i];
    return ret;
  } 
  int n;
  vector<int> a;
};

int n, w, h, m;
int bef[N][N * 2];
int aft[N][N * 2];
bit_int* cnt;
bit_double* sum_x;
bit_double* sum_y;

bool kurang(double a, double b) {
  return a < b && fabs(a - b) > eps;
}

bool cek(int level) {
  double sumx = sum_x->find(level + 1);
  double sumy = sum_y->find(level + 1);
  int count = cnt->find(level + 1);
  if (count == 0) return 1;
  int l = aft[level][0];
  int r = bef[level][n + 1];
  if  (l > n) return 0;
  // puts("lala");
  double ll = l - 0.5;
  double rr = r + 0.5;
  sumx /= count;
  sumy /= count;
  // printf("level %d: %d %.3f %.3f, %.3f %.3f\n", level, count, sumx, sumy, ll, rr);
  if (level % 2) {
    return kurang(ll, sumy) && kurang(sumy, rr);
  } else {
    return kurang(ll, sumx) && kurang(sumx, rr);
  }
}

void remove(int i, int j) {
  bef[i][aft[i][j]] = bef[i][j];
  aft[i][bef[i][j]] = aft[i][j];
}

int main() {
#ifndef LOCAL
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
#endif
  // puts("asu");
  scanf("%d %d %d %d", &n, &w, &h, &m);
  // printf("%d %d %d %d\n", n, w, h, m);
  for (int i = 1; i <= h; i++) {
    for (int j = 0; j <= n + 1; j++) {
      bef[i][j] = j - 1;
      aft[i][j] = j + 1;
    }
  }

  cnt = new bit_int(h);
  sum_x = new bit_double(h);
  sum_y = new bit_double(h);
  for (int i = 1; i <= h; i++) {
    double x = (n % 2? n / 2 + 1 : (double) (n + 1) / 2);
    for (int j = 1; j <= n; j++) {
      // printf("asu %d %d\n", i, j);
      if (i&1) {
        cnt->add(i, 1);
        sum_x->add(i, x);
        sum_y->add(i, j);
      } else {
        cnt->add(i, 1);
        sum_x->add(i, j);
        sum_y->add(i, x);
      }
    }
  }
  // puts("build done");
  for (int tt = 1; tt <= m; tt++) {

    int l, k;
    scanf("%d %d", &l, &k);
    // printf("DEBUG EVENT %d\n", tt);
    double x = (n % 2? n / 2 + 1 : (double) (n + 1) / 2);
    if (l % 2) {
      cnt->add(l, -1);
      sum_x->add(l, -x);
      sum_y->add(l, -k);
    } else {
      cnt->add(l, -1);
      sum_x->add(l, -k);
      sum_y->add(l, -x);
    }
    remove(l, k);
    //printf("op done\n");
    for (int i = l; i >= 1; i--) {
      //printf("checking %d...\n", i);
      if (!cek(i)) {
        puts("yes");
        printf("%d\n", tt);
        goto NIKI_EMERSAN;
      }
    }
    //puts("");
  }
  puts("no");

  NIKI_EMERSAN:
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout); 
#endif
  return 0;
}