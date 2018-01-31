#include <bits/stdc++.h>

using namespace std;

const int N = 303;

int ans[N][N];
bool used[N][N], pick[N][N];
int p[N * N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int nm = n * m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      p[i * m + j] = i * m + j;
  srand(time(0));
  time_t startt = clock();
  bool found = 0;
  while (1) {
    random_shuffle(p, p+nm);
    set<pair<int, int> > st;
    for (int i = 0; i < n; ++i) {
      for (int j =0; j < m; ++j) {
        used[i][j] = 0;
        st.insert(make_pair(i, j));
      }
    }
    bool ok = 1;
    for (int i = 0; i < nm; ++i) {
      int now = p[i];
      ok = 0;
      int x = now/m, y = now % m;
      for (auto it = st.begin(); it != st.end(); ++it) {
        int xx = (it->first + x) % n, yy = (it->second + y) % m;
        if (used[xx][yy]) continue;
        used[xx][yy] = 1;
        ans[x][y] = xx * m + yy;
        ok = 1;
        st.erase(it);
        break;
      }
      if (!ok) break;
    }
    if (ok) {
      found = 1;
      break;
    }
    if ((double)(clock() - startt) * 1000 / CLOCKS_PER_SEC > 960) break;
  }
  if (found) {
    puts("1");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int now = ans[i][j];
        printf("%d %d%c", 1 + (now/m), 1 + (now % m), j == m-1 ? '\n' : ' ');
      }
    }
  }
  else
    puts("0");
  return 0; 
}