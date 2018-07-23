#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

char buffer[N];

bool ethan(const string & a, const string & b) {
  size_t i, j;
  i = j = 0;
  while (i < a.size()) {
    if (j >= b.size()) return false;
    if (a[i] == b[j]) {
      ++i, ++j;
    }
    else if (i == 0) {
      ++j;
    }
    else {
      i = 0;
    }
  }
  return true;
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    scanf("%s", buffer);
    string s(buffer);
    size_t n = s.size();
    string ans = "";
    for (size_t len = 1; len < n; ++len) {
      string now = s.substr(0, len) + s;
      if (!ethan(s, now)) {
        ans = now;
        break;
      }
    }
    printf("Case #%d: %s\n", tc, ans.empty() ? "Impossible" : ans.c_str());
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
  }
  return 0;
}