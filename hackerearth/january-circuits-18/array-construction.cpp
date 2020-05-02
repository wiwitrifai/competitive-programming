#include <bits/stdc++.h>

using namespace std;

const int N = 256;

int c[N][N];
int a[N], n, m, ans[N], best;

int calc() {
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int d = a[i]-a[j];
      ret += c[i][j] * d * d;
    }
  }
  return ret;
}

void genRandom() {
  int r = m % n, d = m/n;
  fill(a, a+n, d);
  set<int> st;
  if (r < n-r) {
    while (st.size() < r) {
      st.insert(rand() % n);
    }
    for (int x : st)
      ++a[x];
  }
  else {
    r = n-r;
    while (st.size() < r) {
      st.insert(rand() % n);
    }
    for (int x : st)
      --a[x];
    for (int i = 0; i < n; ++i)
      ++a[i];
  }
}

int main() {
  time_t startt = clock();
  srand(time(0));
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", c[i]+j);
  genRandom();
  for (int i = 0; i < n; ++i) {
    ans[i] = a[i];
  }
  best = calc();
  int d = m/n, r = m % n;
  int cnt = 0;
  if (r) {
    vector<int> lebih, kurang;
    for (int i = 0; i < n; ++i)
      if (a[i] > d)
        lebih.push_back(i);
      else
        kurang.push_back(i);
    while ((double)(clock() - startt) * 1000 / CLOCKS_PER_SEC < 1975) {
      int pos1, pos2;
      int leb = lebih[pos1 = rand() % lebih.size()], kur = kurang[pos2 = rand() % kurang.size()];
      --a[leb];
      ++a[kur];
      int now = calc();
      if (now <= best) {
        for (int i = 0; i < n; ++i)
          ans[i] = a[i];
        best = now;
        cnt = 0;
        swap(lebih[pos1], kurang[pos2]);
      }
      else
        ++a[leb], --a[kur], ++cnt;
    }
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i], (i == n-1) ? '\n' : ' ');
  cerr << best << endl;
  return 0;
}