// Score: partial 800 points

#include <bits/stdc++.h>

using namespace std;

const int zero = 3;
const int one = 4;
int n = 2e5, q = n;

vector<int> val;

vector<tuple<char, int, int, int>> ans;

void add(int i, int j, int k) {
  --q;
  assert(q >= 0);
  ans.emplace_back('+', i, j, k);
  val[k] = val[i] + val[j];
}

void cmp(int i, int j, int k) {
  --q;
  assert(q >= 0);
  ans.emplace_back('<', i, j, k);
  val[k] = val[i] < val[j];
}

void opand(int i, int j, int k) {
  add(i, j, k);
  cmp(one, k, k);
}

void multiply1b(int posa, int posb, int res, int maxb, int l) {
  int u = l, v = u + 1;
  add(zero, zero, u);
  add(zero, zero, v);
  for (int i = 0; i < maxb; ++i) {
    cmp(u, posb, v);
    opand(posa, v, v);
    add(u, v, u);
  }
  add(u, zero, res);
}

void multiplyab(int posa, int posb, int res, int maxb, int l) {
  int u = l, v = u + 1, w = v + 1;
  add(zero, zero, u);
  add(zero, zero, w);
  for (int i = 0; i < maxb; ++i) {
    cmp(u, posb, v);
    add(u, v, u);
    multiply1b(v, posa, v, maxb, l + 5);
    add(v, w, w);
  }
  add(w, zero, res);
}

int main() {

  for (int a = 6; a <= 6; ++a) {
    for (int b = 7; b <= 7; ++b) {
      val.assign(n, 0);
      val[0] = a;
      val[1] = b;
      add(0, 1, one);
      cmp(zero, one, one);
      assert(val[one] == 1);
      assert(val[zero] == 0);
      multiplyab(0, 1, 2, 11, 6);
      assert(val[2] == a * b);
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    char op;
    int i, j, k;
    tie(op, i, j, k) = it;
    printf("%c %d %d %d\n", op, i, j, k);
  }
  return 0;
}
