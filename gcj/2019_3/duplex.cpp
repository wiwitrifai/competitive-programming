// still wrong answer, don't know why
#include <bits/stdc++.h>

using namespace std;

const int N = 201, K = 512;

char s[N][N];

int pre[N][K], res[N][K];
char ans[N][N];

int r, c;
int w[N], mv[N];
int enco() {
  int now = 0;
  for (int i = 0; i < r; ++i) {
    assert(w[i] >= 0 && w[i] < 4);
    now = now * 4 + w[i];
  }
  return now;
}
void deco(int now) {
  for (int i = r-1; i >= 0; --i) {
    w[i] = now % 4;
    now /= 4;
  }
}
int mask[N], p[N], renum[N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}
void merge(int u, int v) {
  if ((u = find(u)) == (v = find(v)))
    return;
  p[u] = p[v];
}
bool ada[N], udah[N];

void solve(int tc) {
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; ++i)
    scanf("%s", s[i]);
  int cur = 0;
  w[0] = cur;
  for (int i = 1; i < r; ++i) {
    if (s[i][0] != s[i-1][0])
      ++cur;
    w[i] = cur;
  }
  memset(pre, -1, sizeof pre);
  int nmove = 1;
  for (int i = 0; i < r-1; ++i)
    nmove *= 3;
  pre[0][enco()] = enco();
  int cc = c;
  char ujung = s[r-1][c-1];
  while (c > 1) {
    bool ok = 1;
    for (int i = 0; i < r; ++i)
      if (s[i][c-1] != ujung)
        ok = 0;
    if (ok)
      --c;
    else
      break;
  }
  for (int i = 0; i+1 < c; ++i) {
    for (int x = 0; x < K; ++x) {
      if (pre[i][x] == -1) continue;
      deco(x);
      for (int move = 0; move < nmove; ++move) {
        int cmo = move;
        bool ok = 1;
        for (int j = 0; j < r-1; ++j) {
          mv[j] = cmo % 3;
          cmo /= 3;
          if (mv[j] == 1 && s[j][i] != s[j+1][i+1])
            ok = 0;
          if (mv[j] == 2 && s[j+1][i] != s[j][i+1])
            ok = 0;
        }
        if (!ok) continue;
        fill(mask, mask+r, 0);
        for (int j = 0; j < r; ++j) {
          if (s[j][i] == s[j][i+1])
            mask[j] |= 1 << w[j];
        }
        for (int j = 0; j < r-1; ++j) {
          if (mv[j] == 1) {
            mask[j+1] |= 1 << w[j]; 
          }
          else if (mv[j] == 2) {
            mask[j] |= 1 << w[j+1];
          }
        }
        for (int j = 0; j < r-1; ++j)
          if (s[j+1][i+1] == s[j][i+1])
            mask[j+1] |= mask[j];
        for (int j = r-1; j >= 0; --j)
          if (s[j+1][i+1] == s[j][i+1])
            mask[j] |= mask[j+1];
        fill(ada, ada+r, 0);
        fill(udah, udah+r, 0);
        for (int j = 0; j < r; ++j) {
          ada[w[j]] = 1;
        }
        for (int j = 0; j < r; ++j) {
          int now = mask[j];
          for (int bit = 0; now; now >>= 1, ++bit) {
            if (now & 1)
              udah[bit] = 1;
          }
        }
        for (int j = 0; j < r; ++j) {
          if (ada[j] && !udah[j]) {
            ok = 0;
          }
        }
        if (!ok) continue;
        fill(p, p+r, -1);
        for (int j = 0; j < r; ++j) {
          int last = -1, now = mask[j];
          for (int bit = 0; now; now >>= 1, ++bit) {
            if (now & 1) {
              if (last != -1) {
                merge(last, bit);
              }
              last = bit;
            }
          }
        }
        int num = 0;
        fill(renum, renum+r, -1);
        for (int j = 0; j < r; ++j) {
          if (udah[j] && find(j) == j) {
            renum[j] = num++;
          }
        }
        for (int j = 0; j < r; ++j) {
          int now = mask[j];
          if (now == 0) {
            w[j] = num++;
            continue;
          }
          for (int bit = 0; now; now >>= 1, ++bit) {
            if (now & 1) {
              w[j] = renum[find(bit)];
              assert(w[j] >= 0 && w[j] < r);
              break;
            }
          }
        }
        int to = enco();
        pre[i+1][to] = x;
        res[i+1][to] = move;
        deco(x);
      }
    }
  }
  for (int x = 0; x < K; ++x) {
    if (pre[c-1][x] == -1) continue;
    bool ok = 1;
    deco(x);
    int a = -1, b = -1;
    for (int i = 0; i < r; ++i) {
      if (s[i][c-1] == 'A') {
        if (a == -1)
          a = w[i];
        if (a != w[i] && !(ujung == 'A' && c < cc)) {
          ok = 0;
          break;
        }
      }
      else {
        if (b == -1)
          b = w[i];
        if (b != w[i] && !(ujung == 'B' && c < cc)) {
          ok = 0;
          break;
        }
      }
    }
    if (!ok)
      break;
    printf("Case #%d: POSSIBLE\n", tc);
    for (int i = 0; i < r-1; ++i) {
      for (int j = 0; j < cc-1; ++j)
        ans[i][j] = '.';
      ans[i][cc-1] = '\0';
    }
    int now = x;
    for (int i = c-1; i > 0; --i) {
      int cmo = res[i][now];
      for (int j = 0; j < r-1; ++j) {
        int yey = cmo % 3;
        cmo /= 3;
        if (yey == 1)
          ans[j][i-1] = '\\';
        if (yey == 2)
          ans[j][i-1] = '/';
      }
      now = pre[i][now];
    }
    for (int i = 0; i < r-1; ++i)
      printf("%s\n", ans[i]);
    return;
  }
  printf("Case #%d: IMPOSSIBLE\n", tc);
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
