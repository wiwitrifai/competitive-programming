#include <bits/stdc++.h>

using namespace std;

vector<int> c;

int ask(int x, int y) {
  int ans;
#ifdef LOCAL
  ans = c[x] % c[y];
#else
  printf("? %d %d\n", x, y);
  fflush(stdout);
  scanf("%d", &ans);
#endif
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
#ifdef LOCAL
  c.resize(n+1);
  iota(c.begin(), c.end(), 0);
  srand(time(0));
  random_shuffle(c.begin()+1, c.end());
  for (int i = 1; i <= n; ++i)
    cerr << c[i] << " ";
  cerr << endl;
#endif

  vector<int> p(n+1);
  int last = 1;
  for (int i = 2; i <= n; ++i) {
    int a = ask(last, i);
    int b = ask(i, last);
    if (a > b) {
      p[last] = a;
      last = i;
    } else {
      p[i] = b;
    }
  }
  vector<int> used(n+1, 0);
  for (int i = 1; i <= n; ++i) {
    if (i == last) continue;
    used[p[i]] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i])
      p[last] = i;
  }
  printf("!");
  for (int i = 1; i <= n; ++i)
    printf(" %d", p[i]);
  printf("\n");


#ifdef LOCAL
  for (int i = 1; i <= n; ++i)
    assert(c[i] == p[i]);
#endif
  return 0;
}
