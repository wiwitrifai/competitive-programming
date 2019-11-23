#include <bits/stdc++.h>

using namespace std;

vector<int> precompute(vector<int> & s) {
  int n = s.size();
  vector<int> a(n, 0);
  for(int i = 1; i < n; i++) {
    int j = a[i - 1];
    while(j > 0 && s[i] != s[j]) j = a[j - 1];
    if(s[i] == s[j]) a[i] = j + 1;
  }
  return a;
}

vector<vector<int>> b, p;
vector<int> ans, id, last;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i + 1 < n; ++i) {
    a[i] ^= a[i+1];
  }
  vector<int> mapto(q);
  --n;
  a.pop_back();
  map<vector<int>, int> num;
  for (int it = 0; it < q; ++it) {
    int k;
    scanf("%d", &k);
    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
      scanf("%d", &c[i]);
    }
    for (int i = 0; i + 1 < k; ++i) {
      c[i] ^= c[i+1];
    }
    c.pop_back();
    auto iter = num.find(c);
    if (iter == num.end()) {
      int val = num.size();
      mapto[it] = val;
      num[c] = val;
      b.push_back(c);
      p.push_back(precompute(c));
    }
    else
      mapto[it] = iter->second;
  }
  ans.resize(num.size(), 0);
  id.resize(num.size(), 0);
  last.resize(num.size(), -2);
  int lastq = -2, ansq = 0;
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < (int)b.size(); ++k) {
      int & j= id[k];
      vector<int> & bk = b[k];
      vector<int> & pk = p[k];
      int len = b[k].size();
      while (j > 0 && a[i] != bk[j]) j = pk[j-1];
      if (bk[j] == a[i]) ++j;
      if (j == len) {
        j = pk[j-1];
        int lef = i - len;
        if (last[k] <= lef) {
          ++ans[k];
          last[k] = i+1;
        }
        if (lastq <= lef) {
          ++ansq;
          lastq = i+1;
        }
      }
    }
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[mapto[i]]);
  printf("%d\n", ansq);
  return 0;
}
