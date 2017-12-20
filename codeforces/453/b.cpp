#include <bits/stdc++.h>

using namespace std;

typedef vector<double> polinom;

polinom mult(polinom a, polinom b) {
  polinom res(a.size() + b.size() - 1);
  for (int i = 0; i < a.size(); ++i)
    for (int j = 0; j < b.size(); ++j) {
      res[i+j] += a[i] * b[j];
    }
  return res;
}
polinom add(polinom a, polinom b) {
  polinom res(max(a.size(), b.size()));
  for (int i = 0; i < a.size(); ++i)
    res[i] = a[i] + b[i];
  return res;
}
const int N = 151;
const long double eps = 1e-9;
pair<polinom, polinom> ans[N];
bool val[N];

polinom modu(polinom a, polinom b) {
  polinom cur = a;
  while (cur.size() >= b.size()) {
    polinom kali((int)cur.size() - (int)b.size() + 1);
    kali[(int)cur.size() - b.size()] = -cur.back() / b.back();
    cur = add(cur, mult(kali, b));
    while (cur.size() > 0 && fabs(cur.back()) < eps) cur.pop_back();
  }
  return cur;
}

bool get(polinom a, polinom b) {
  polinom c = modu(a, b);
  if (c.size() < (int)b.size()-1)
    return 0;
  if (c.size() == 0) return 1;
  return get(b, c);
}

polinom generate(int n) {
  polinom ret(n+1);
  ret[n] = 1;
  for (int i = 0; i < n; ++i) {
    int val = rand() % 3;
    while (val > 1) val -= 3;
    while (val < -1) val += 3;
    ret[i] = val;
  }
  return ret;
}

int main() {
  srand(time(0));
  polinom p = {-1,-1,-1,1,0,-1,1,1,-1,1,1,0,-1,0,1,1,-1,1,0,-1,1,1,-1,0,1,1,1,0,1,0,0,-1,0,-1,0,1,-1,-1,1,1,1,-1,-1,0,0,0,-1,-1,1},
  q = {-1,0,-1,-1,-1,-1,-1,-1,0,1,0,-1,-1,0,1,0,-1,1,1,1,1,-1,0,0,-1,0,1,0,1,1,0,-1,-1,0,1,-1,0,1,1,0,-1,-1,0,1,-1,-1,1,1};
  cerr << get(p, q) << endl;

  int n;
  scanf("%d", &n);
  while (1) {
    polinom a = generate(n), b = generate(n-1);
    if (!get(a, b)) continue;
    printf("%d\n", n);
    for (int i = 0; i <= n; ++i)
      printf("%d%c", (int)a[i], (i == n) ? '\n' : ' ');
    printf("%d\n", n-1);
    for (int i = 0; i <= n-1; ++i)
      printf("%d%c", (int)b[i], (i == n-1) ? '\n' : ' ');
    break;
  }
  return 0;
}