#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> process(vector<int> sign) {
  vector<int> ans(sign.size());
  int len = sign.size();
  ans[len-1] = 1;
  int le = -1, cur = 0;
  for (int i = len-1; i >= 0; --i) {
    if (le * sign[i] < 0)
      ans[i] = len-i;
    else
      ans[i] = 1;
    le = sign[i];
  }

  int l = -1e9, r = 1e9, now = 0;
  for (int i = 0; i < len; ++i) {
    int cur = now + sign[i] * ans[i];
    assert(l < cur && cur < r);
    if (now < cur)
      l = now;
    else
      r = now;
    now = cur;
  }
  return ans;
}

int main() {
  vector<int> ver, hor;
  bool datar = 1;
  int pos = 1;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    if (datar)
      hor.push_back(pos);
    else
      ver.push_back(pos);
    int l, t;
    scanf("%d %d", &l, &t);
    if (datar)
      pos = pos;
    else
      pos = -pos;
    pos *= t;
    datar ^= 1;
  }
  vector<int> aver = process(ver), ahor = process(hor);
  for (int i = 0; i < n; ++i) {
    printf("%d\n", i & 1 ? aver[i/2] : ahor[i/2]);
  }
  return 0;
}