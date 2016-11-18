#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< int > bit[N];

void upd(int id, int x, int v) {
  for (x; x < bit[id].size(); x+= x & (-x))
    bit[id][x] += v;
}
int get(int id, int x) {
  int ret = 0;
  for (; x; x -= x & (-x))
    ret += bit[id][x];
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
  }
  return 0;
}