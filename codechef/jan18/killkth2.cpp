#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  vector<string> vs;
  for (int i = 0; i < s.size(); ++i)
    for (int j = i+1; j <= s.size(); ++j)
      vs.push_back(s.substr(i, j-i));
  sort(vs.begin(), vs.end());
  string res;
  for (string ss : vs)
    res += ss;
  int q;
  scanf("%d", &q);
  long long g = 0;
  while (q--) {
    long long p, m;
    scanf("%lld %lld", &p, &m);
    long long k = (p * g) % m;
    printf("%c\n", res[k]);
    g += res[k];
  }

  return 0;
}