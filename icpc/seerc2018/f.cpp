#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

vector<tuple<char, int, int> > ans;

void process(int l, int r, int p) {
  if (l < p) {
    int i = p;
    while (i >= l) {
      while (i >= l && a[i] == a[p]) --i;
      if (i < l) break;
      bool less = a[i] < a[p];
      while (i >= l && (a[i] <= a[p]) == less) {
        a[i] = a[p];
        --i;
      }
      ans.emplace_back(less ? 'M' : 'm', i+1, p);
    }
  }
  if (p < r) {
    int i = p;
    while (i <= r) {
      while (i <= r && a[i] == a[p]) ++i;
      if (i > r) break;
      bool less = a[i] < a[p];
      while (i <= r && (a[i] <= a[p]) == less) {
        a[i] = a[p];
        ++i;
      }
      ans.emplace_back(less ? 'M' : 'm', p, i-1);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b+i);
  }
  int m = 0;
  int j = 0;
  int last = -1;
  for (int i = 0; i < n; ++i) {
    if (b[j] != a[i]) continue;
    process(last+1, i, i);
    a[m] = a[i];
    if (m <= last && m > 0) {
      ans.emplace_back(a[m-1] <= a[i] ? 'M' : 'm', m, i);
    }
    last = i;
    ++m;
    while (j < n && b[j] == a[i]) ++j;
    if (j == n) break;
  }
  if (j != n) {
    puts("-1");
    return 0;
  }
  for (int i = m; i <= last; ++i) {
    a[i] = a[m-1];
  }
  process(m-1, n-1, m-1);
  j = n-1;
  for (int i = m-2; i >= 0; --i) {
    while (j > 0 && b[j] != a[i]) --j;
    ans.emplace_back(a[i+1] <= a[i] ? 'M' : 'm', i, j);
  }
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    char q;
    int l, r;
    tie(q, l, r) = it;
    ++l, ++r;
    printf("%c %d %d\n", q, l, r);
  }
  return 0;
}