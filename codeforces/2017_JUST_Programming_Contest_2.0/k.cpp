#include <bits/stdc++.h>

using namespace std;
const int N = 10;
bool fix[N];
char s[N][N];
int x[N][N];
int r[N], c[N];
bool cek(int id) {
  if (id == 1) return 1;
  return (abs(c[id]-c[id-1]) <= 1) && (abs(r[id]-r[id-1]) <= 1);
}
long long get(int id) {
  if (id == 10)
    return 1;
  if (fix[id]) {
    if (!cek(id))
      return 0;
    else
      return get(id+1);
  }
  else {
    long long ret = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) if (x[i][j] == 0) {
        r[id] = i;
        c[id] = j;
        x[i][j] = id;
        if (cek(id))
          ret += get(id+1);
        x[i][j] = 0;
      }
    }
    return ret;
  }
}

int main() {
  for (int i = 0; i < 3; i++)
    scanf("%s", s[i]);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      if (s[i][j] > '0') {
        int now = s[i][j]-'0';
        x[i][j] = s[i][j]-'0';
        r[now] = i;
        c[now] = j;
        fix[now] = 1;
      }
  }
  cout << get(1) << endl;
  return 0;
}