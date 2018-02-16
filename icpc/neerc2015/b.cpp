#include <bits/stdc++.h>

using namespace std;

void open(string name) {
#ifndef LOCAL
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
#endif
}

const int BASE = 1 << 30;

typedef vector<int> bigint;
bigint add(bigint le, bigint ri) {
  long long cur = 0;
  bigint res;
  for (int i = 0; i < max(le.size(), ri.size()); ++i) {
    if (i < le.size())
      cur += le[i];
    if (i < ri.size())
      cur += ri[i];
    res.push_back(cur % BASE);
    cur /= BASE;
  }
  while (cur) {
    res.push_back(cur % BASE);
    cur /= BASE;    
  }
  return res;
}

void multiply(bigint & b, int k) {
  long long cur = 0;
  for (int i = 0; i < b.size(); ++i) {
    cur += 1LL * b[i] * k;
    b[i] = cur % BASE;
    cur /= BASE;
  }
  while (cur) {
    b.push_back(cur % BASE);
    cur /= BASE;
  }
}

int getBit(const bigint & b, int k) {
  if (k/30 >= b.size()) return 0;
  return (b[k/30] >> (k % 30)) & 1;
}

int main() {
  open("binary");
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("1");
    return 0;
  }
  vector<bigint> ans;
  vector<bigint> c;
  bigint satu(1, 0);
  ans.push_back(satu);
  c.push_back(satu);
  satu[0] = 1;
  for (int len = 1; ans.size() < 10000; ++len) {
    vector<bigint> b;
    for (int i = 0; i < c.size(); ++i) {
      if (getBit(c[i], len-1) == 0)
        b.push_back(c[i]);
    }
    c = b;
    for (int i = 0; i < b.size(); ++i) {
      bigint now = add(b[i], satu);
      c.push_back(now);
      ans.push_back(now);
      if (ans.size() == n+1) {
        for (int i = 0; i < len; ++i) {
          printf("%d", getBit(now, len-i-1));
        }
        printf("\n");
        return 0;
      }
    }
    multiply(satu, 10);
  }


  return 0;
}