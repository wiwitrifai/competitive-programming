#include <bits/stdc++.h>

using namespace std;

int x[10];

int a[10], b[10];

bool row(int v) {
  int r = (v/3) * 3;
  for (int i = 0; i < 3; i++)
    if (x[r + i] != x[v])
      return false;
  return true;
}

bool col(int v) {
  int r = v % 3;
  for (int i = 0; i < 3; i++)
    if (x[r + i * 3] != x[v])
      return false;
  return true;
}

bool diag() {
  if (x[0] == 0) return false;
  if (x[4] != x[0] || x[8] != x[0]) return false;
  return true;
} 
bool diag2() {
  if (x[2] == 0) return false;
  if (x[4] != x[2] || x[6] != x[2]) return false;
  return true;
} 

vector<int> cek() {
  memset(x, 0, sizeof x);
  vector<int> ret;
  for (int i = 0, j = 0, c = 0; c < 9; ) {
    while (x[a[i]] != 0) i++;
    x[a[i]] = 1;
    if (row(a[i]) || col(a[i]) || diag() || diag2())
      return ret;
    i++;
    c++;
    if (c < 9) {
      while (x[b[j]] != 0) j++;
      x[b[j]] = -1;
      ret.push_back(b[j]);
      if (row(b[j]) || col(b[j]) || diag() || diag2())
        return vector<int>();
      j++;
      c++;
    }
  }
  return vector<int>();
}

int main() {
  for (int i = 0; i < 9; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    int now = u * 3 + v;
    a[i] = now;
    b[i] = i;
  }
  vector<int> ans;
  do {
    vector<int> res = cek();
    if (res.size()) {
      if (ans.size() == 0)
        ans = res;
      if (ans.size() > res.size()|| (res.size() == ans.size() && res < ans))
        ans = res;
    }
  } while(next_permutation(b, b+9));
  for (int v : ans) {
    printf("%d %d\n", v/3 + 1, (v % 3) + 1);
  }
  return 0;
}