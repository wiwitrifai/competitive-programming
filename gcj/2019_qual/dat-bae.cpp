#include <bits/stdc++.h>

using namespace std;

string ask(string s) {
  cout << s << endl;
  fflush(stdout);
  string ret;
  cin >> ret;
  return ret;
}

bool solve() {
  int n, b, f;
  scanf("%d %d %d", &n, &b, &f);
  cerr << n << " " << b << " " << f << endl;
  int mod = 1 << f;
  vector<string> query(f, string(n, '0'));
  for (int i = 0; i < n; ++i) {
    int x = i % mod;
    for (int j = 0; j < f; ++j) {
      if (x & (1 << j))
        ++query[j][i];
    }
  }
  vector<string> result;
  for (int i = 0; i < f; ++i) {
    string res = ask(query[i]);
    if (res == "-1")
      return false;
    assert(n-b == (int)res.size());
    result.push_back(res);
  }
  vector<int> val;
  for (int i = 0; i < n-b; ++i) {
    int mask = 0;
    for (int j = 0; j < f; ++j) {
      if (result[j][i] == '1')
        mask |= 1 << j;
    }
    val.push_back(mask);
  }
  vector<int> answer;
  for (int i = 0, j = 0; i < n; ++i) {
    int x = i % mod;
    if (j < val.size() && val[j] == x) {
      ++j;
      continue;
    }
    answer.push_back(i);
  }
  assert(b == (int)answer.size());
  for (int i = 0; i < (int)answer.size(); ++i) {
    printf("%d%c", answer[i], i+1 == (int)answer.size() ? '\n' : ' ');
  }
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret == 1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    if (!solve())
      break;
  }
  return 0;
}
