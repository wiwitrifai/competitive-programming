#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

void print(vector<int> & ans) {
  for (int i = 0; i < ans.size(); ++i)
    printf("%d", ans[i]);
  printf("\n");
}

vector<int> add(vector<int> & a, vector<int> & b) {
  int l = (int)a.size()-1, r = (int)b.size()-1;
  vector<int> res;
  int carry = 0;
  while (l >= 0 || r >= 0 || carry > 0) {
    if (l >= 0)
      carry += a[l];
    if (r >= 0)
      carry += b[r];
    res.push_back(carry % 10);
    carry /= 10;
    --l;
    --r;
  }
  reverse(res.begin(), res.end());
  return res;
}

vector<int> split_add(vector<int> & v, int pos) {
  vector<int> a(pos), b((int)v.size()-pos);
  for (int i = 0; i < pos; ++i)
    a[i] = v[i];
  for (int i = pos; i < v.size(); ++i)
    b[i-pos] = v[i];
  vector<int> res = add(a, b);
  return res;
}

bool cmp(vector<int> & a, vector<int> & b) {
  if (a.size() != b.size())
    return a.size() < b.size();
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i])
      return a[i] < b[i];
  }
  return false;
}


int main() {
  int l;
  scanf("%d", &l);
  scanf("%s", s);
  vector<int> digit(l);
  for (int i = 0; i < l; ++i)
    digit[i] = s[i] -'0';
  vector<int> ans = digit;
  int now = l/2;
  int cnt = 3;
  while (cnt-- > 0) {
    while (now < l && digit[now] == 0)
      ++now;
    if (now >= l) break;
    vector<int> result = split_add(digit, now);
    if (cmp(result, ans))
      ans = result;
    ++now;
  }
  cnt = 3;
  now = l/2-1;
  while (cnt-- > 0) {
    while (now > 0 && digit[now] == 0)
      --now;
    if (now <= 0) break;
    vector<int> result = split_add(digit, now);
    if (cmp(result, ans))
      ans = result;
    --now;
  }
  print(ans);
  return 0;
}
