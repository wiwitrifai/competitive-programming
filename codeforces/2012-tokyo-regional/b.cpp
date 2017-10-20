#include <bits/stdc++.h>

using namespace std;

const int N = 15;

string a[N], b[N];

int main() {
  int n, m;
  cin >> n >> m;
  while (n && m) {
    int c = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int ca = 0, cb = 0, cc = 0;
    vector<tuple<int, int, int, int> > rule;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < a[i].size(); j++) {
        if (a[i][j] != '.') break;
        cnt++;
      }
      rule.emplace_back(ca, cb, cc, cnt);
      //printf("%d %d %d: %d\n", ca, cb, cc, cnt);
      for (int j = 0; j < a[i].size(); j++) {
        if (a[i][j] == '(') {
          ca++;
        } else if (a[i][j] == ')') {
          ca--;
        } else if (a[i][j] == '[') {
          cb++;
        } else if (a[i][j] == ']') {
          cb--;
        } else if (a[i][j] == '{') {
          cc++;
        } else if (a[i][j] == '}') {
          cc--;
        }
      }
    }
    vector<tuple<int, int, int>> can;
    for (int i = 1; i <= 20; i++) {
      for (int j = 1; j <= 20; j++) {
        for (int k = 1; k <= 20; k++) {
          bool ok = 1;
          for (auto it : rule) {
            int ca, cb, cc, res;
            tie(ca, cb, cc, res) = it;
            if (ca * i + cb * j + cc * k != res) {
              ok = 0;
              break;
            }
          }
          if (ok) can.emplace_back(i, j, k);
        }
      }
    }
    ca = 0; cb = 0; cc = 0;
    printf("0");
    for (int i = 1; i < m; i++) {
      for (int j = 0; j < b[i-1].size(); j++) {
        if (b[i-1][j] == '(') {
          ca++;
        } else if (b[i-1][j] == ')') {
          ca--;
        } else if (b[i-1][j] == '[') {
          cb++;
        } else if (b[i-1][j] == ']') {
          cb--;
        } else if (b[i-1][j] == '{') {
          cc++;
        } else if (b[i-1][j] == '}') {
          cc--;
        }
      }
      if (can.empty()) {
        printf(" -1");
      } else {
        int u, v, w;
        tie(u, v, w) = can[0];
        int res = ca * u + cb * v + cc * w;
        for (int j = 1; j < can.size(); j++) {
          tie(u, v, w) = can[j];
          int cur = ca * u + cb * v + cc * w;
          if (cur != res) {
            res = -1;
          }
        }
        printf(" %d", res);
      }
    }
    printf("\n");
    cin >> n >> m;
  }

  return 0;
}