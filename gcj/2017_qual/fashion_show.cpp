#include <bits/stdc++.h>

using namespace std;

const int N = 333;
vector< int > g[N];
char x[111][111], bef[111][111];
bool live[N], lived[N];
bool mark[N];
int match[N], matched[N];

bool dfs(int v){// v is in X, it reaturns true if and only if there is an augmenting path starting from 
  if (!live[v]) return false;
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : g[v]) {
    if (!lived[u]) continue;
    if(matched[u] == -1 or dfs(matched[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
      return match[v] = u, matched[u] = v, true;
  }
  return false;
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= 3 * n; i++)
      g[i].clear();
    fill(live, live+N, 1);
    fill(lived, lived+N, 1);
    fill(match, match+N, -1);
    fill(matched, matched+N, -1);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        x[i][j] = bef[i][j] = '.';
    for (int i = 0; i < m; i++) {
      char s[5];
      int r, c;
      scanf("%s %d %d", s, &r, &c);
      r--; c--;
      x[r][c] = s[0];
      bef[r][c] = s[0];
    }
    int sz = m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (x[i][j] != 'x' && x[i][j] != 'o')
          g[i].push_back(j);
        else {
          match[i] = j;
          matched[j] = i;
          lived[j] = 0;
          live[i] = 0;
        }
        if (x[i][j] != '+' && x[i][j] != 'o')
          g[n + i+j].push_back(n + i+n-j);
        else {
          int f = n+i+j, t = n+i+n-j;
          match[f] = t;
          matched[t] = f;
          lived[t] = 0;
          live[f] = 0;
        }
      }
    } 
    while(true){
      memset(mark, false, sizeof mark);
      bool fnd = false;
      for(int i = 0; i < 3 * n; i++) if(match[i] == -1 && !mark[i])
        fnd |= dfs(i);
      if(!fnd)
        break;
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (match[i] == j) {
          x[i][j] = 'x';
        }
        else
          x[i][j] = '.';
        if (match[i+j+n] == n+i+n-j) {
          if (x[i][j] == '.')
            x[i][j] = '+';
          else if (x[i][j] == 'x')
            x[i][j] = 'o';
        }
        if (x[i][j] == 'o') ans += 2;
        else if (x[i][j] == '+' || x[i][j] == 'x') ans += 1;
        if (x[i][j] != '.' && x[i][j] != bef[i][j]) cnt++;
        if (x[i][j] != bef[i][j] && bef[i][j] != '.') {
          if (bef[i][j] == '+')
            assert(x[i][j] == '+' || x[i][j] == 'o');
          else 
            assert(x[i][j] == 'x' || x[i][j] == 'o');
        }
      }
    }
    printf("Case #%d: %d %d\n", tc, ans, cnt);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (x[i][j] != '.' && x[i][j] != bef[i][j]) {
          printf("%c %d %d\n", x[i][j], i+1, j+1);
          cnt--;
        }
      }
    }
    assert(cnt == 0);
    cerr << "Case #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl; 
  }
  return 0;
}