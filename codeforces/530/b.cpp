#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

string s[N];
char buff[N];
pair<string, string> match[] = {{"AC", "GT"}, {"AG", "CT"}, {"AT", "CG"}};
string ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buff);
    s[i] = buff;
    ans[i] = s[i];
  }
  int best = n * m + 1;
  for (int rot = 0; rot < 2; ++rot) {
    for (int it = 0; it < 3; ++it) {
      string a[2];
      a[0] = match[it].first, a[1] = match[it].second;
      if (rot)
        swap(a[0], a[1]);
      {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
          int ca, cb;
          ca = cb = 0;
          for (int j = 0; j < m; ++j) {
            int v = j&1;
            ca += a[i&1][v] != s[i][j];
            cb += a[i&1][v^1] != s[i][j];
          }
          cur += min(ca, cb);
        }
        if (cur < best) {
          best = cur;
          for (int i = 0; i < n; ++i) {
            int ca, cb;
            ca = cb = 0;
            for (int j = 0; j < m; ++j) {
              int v = j&1;
              ca += a[i&1][v] != s[i][j];
              cb += a[i&1][v^1] != s[i][j];
            }
            if (ca < cb) {
              for (int j = 0; j < m; ++j) {
                int v = j&1;
                ans[i][j] = a[i&1][v];
              }
            }
            else {
              for (int j = 0; j < m; ++j) {
                int v = j&1;
                ans[i][j] = a[i&1][v^1];
              }
            }
          }    
        }
      }
      {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
          int ca, cb;
          ca = cb = 0;
          for (int i = 0; i < n; ++i) {
            int v = i&1;
            ca += a[j&1][v] != s[i][j];
            cb += a[j&1][v^1] != s[i][j];
          }
          cur += min(ca, cb);
        }
        if (cur < best) {
          best = cur;
          for (int j = 0; j < m; ++j) {
            int ca, cb;
            ca = cb = 0;
            for (int i = 0; i < n; ++i) {
              int v = i&1;
              ca += a[j&1][v] != s[i][j];
              cb += a[j&1][v^1] != s[i][j];
            }
            if (ca < cb) {
              for (int i = 0; i < n; ++i) {
                int v = i&1;
                ans[i][j] = a[j&1][v];
              }
            }
            else {
              for (int i = 0; i < n; ++i) {
                int v = i&1;
                ans[i][j] = a[j&1][v^1];
              }
            }
          }
        }
      }
    }
  }
  cerr << best << endl;
  for (int i = 0; i < n; ++i)
    printf("%s\n", ans[i].c_str());
  return 0;
}