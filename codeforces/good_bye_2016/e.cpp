#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

void upd(int & x, int y) {
  if (y == -1)
    return;
  if (x == -1 || x > y)
    x = y;
}

struct state {
  int cnt[5][4][5];
  void reset() {
    memset(cnt, -1, sizeof cnt);
    cnt[0][0][0] = 0;
  }
  void addr(int x) {
    if (x != 2 && x && 0 && x != 1 && x != 6 && x != 7)
      return;
    if (x == 6) {
      for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
          if (cnt[i][0][j] != -1) {
            upd(cnt[i][1][j], cnt[i][0][j]);
            if (j < 3)
              cnt[i][0][j]++;
          }
        }
      for (int i = 0; i < 5; i++)
        for (int j = 0; j < 4; j++) {
          if (cnt[i][j][3] != -1)
            cnt[i][j][3]++;
          if (cnt[i][j][4] != -1)
            cnt[i][j][4]++;
          // trigger kiri
        }
      return;
    }
    if (x == 7) {
      for (int i = 0; i < 5; i++)
        for (int j = 0; j < 4; j++) {
          upd(cnt[i][j][4], cnt[i][j][3]);
        }
      for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++) {
          if (cnt[0][i][j] != -1) {
            upd(cnt[1][i][j], cnt[0][i][j]);
            cnt[0][i][j]++;
          }
        }
      return;
    }
    int id = 0;
    if (x == 2)
      id = 0;
    else if (x == 0)
      id = 1;
    else if (x == 1)
      id = 2;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 4; j++) {
        if (cnt[i][j][id] != -1) {
          upd(cnt[i][j][id+1], cnt[i][j][id]);
          cnt[i][j][id]++;
        }
      }
  }

  void addl(int x) {
    if (x != 2 && x && 0 && x != 1 && x != 6 && x != 7)
      return;
    cerr << x << endl;
    if (x == 2) {
      for (int i = 0; i < 5; i++)
        for (int j = 0; j < 4; j++) {
          if (cnt[i][j][0] != -1) {
            upd(cnt[i][j][1], cnt[i][j][0]);
            if (j)
              cnt[i][j][0]++;
          }
        }
    }
    if (x == 6) {
      for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
          if (cnt[i][0][j] != -1) {
            upd(cnt[i][1][j], cnt[i][0][j]);
            cnt[i][0][j]++;
          }
        }
      return;
    }
    if (x == 7) {
      for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++) {
          if (cnt[0][i][j] != -1) {
            upd(cnt[1][i][j], cnt[0][i][j]);
            cnt[0][i][j]++;
          }
        }
      return;
    }
    int id = 0;
    if (x == 2)
      id = 3;
    else if (x == 0)
      id = 2;
    else if (x == 1)
      id = 1;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++) {
        if (cnt[i][id][j] != -1) {
          if (id + 1 < 4)
            upd(cnt[i][id+1][j], cnt[i][id][j]);
          cnt[i][id][j]++;
        }
      }
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 5; j++) {
        if (cnt[id][i][j] != -1) {
          upd(cnt[id+1][i][j], cnt[id][i][j]);
          cnt[id][i][j]++;
        }
      }
  }
};
vector< int > occ[10];
int n, q;
char s[N];
int ans[N];
vector< pair< pair<int, int>, int > > que;

const int G = sqrt(N);

bool cmp(pair< pair<int, int>, int > a, pair< pair<int, int>, int > b) {
  int ga = a.first.first/G, gb = b.first.first/G;
  if (ga != gb)
    return ga < gb;
  return a.first.second < b.first.second;
}

int main() {
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    que.push_back(make_pair(make_pair(a, b), i));
  }
  sort(que.begin(), que.end(), cmp);
  state now;
  now.reset();
  int gr = -1, le = 0, ri = 0;
  for (int i = 0; i < q; i++) {
    int l = que[i].first.first, r = que[i].first.second, id = que[i].second;
    if (l/G != gr) {
      gr = l/G;
      ri = (gr+1) * G;
      le = ri;
      now.reset();
    }
    while (ri < r) {
      now.addr(s[ri]-'0');
      ri++;
    }
    state tmp = now;
    for (int j = min(le, r)-1; j >= l; j--) {
      tmp.addl(s[j]-'0');
    }
    ans[id] = -1;
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 4; k++) {
        upd(ans[id], tmp.cnt[j][k][5]);
        upd(ans[id], tmp.cnt[5][k][j]);
      }
    }
  }
  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);
  return 0;
}