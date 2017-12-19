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
  for (int i = 1; i <= 150; ++i) {
    cerr << i << " start " << endl;
    while (1) {
      polinom a, b;
      a = generate(i);
      b = generate(i-1);
      cerr << " sut " << endl;
      if (get(a, b)) {
        ans[i] = {a, b};
        cout << "{{";
        for (int i = 0; i < a.size(); ++i)
          cout << a[i] << ",";
        cout << "},{";
        for (int i = 0; i < b.size(); ++i)
          cout << b[i] << ",";
        cout << "}}," << endl;
        break;
      }
    }
    cerr << i << " done " << endl;
  }
  return 0;
}