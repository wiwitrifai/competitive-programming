#include <bits/stdc++.h>

using namespace std;

vector<int> mask, unmask;
int st;
int a, b, pos, bpos;
int dx[] = {0, 1, 1, 1}, dy[] = {1, 1, 0, -1};

int cek(int black, int white) {
  for (int x : unmask) {
    if ((black & x) == x || (white & x) == x)
      return 0;
  }
  int all = black | white;
  if (black & white) return 0;
  if ((black & (1 << st)) == 0) return 0;
  if ((white & bpos) == 0) return 0;
  int nb = __builtin_popcount(black), nw = __builtin_popcount(white);
  if (nb != nw) return 0;
  for (int x : mask) {
    if ((white & x) == x) {
      return 1;
    }
  }  
  return 0;
}

int cnt[5];
vector<pair<int, int> > ans;
void solve(int black, int white, int cur) {
  if ((black | white) & bpos) {
    if (cek(black, white))
      ans.emplace_back(black, white);
  }
  else {
    for (int i = 0; i < 4; ++i) {
      if (cnt[i] >= 4) continue;
      int now = cnt[i] * 4 + i;
      ++cnt[i];
      if (cur)
        solve(black | (1 << now), white, 0);
      else
        solve(black, white | (1 << now), 1);
      --cnt[i];
    }
  }
}

int main() {
  scanf("%d %d %d", &st, &a, &b);
  --a, --b, --st;
  pos = a * 4 + b;
  pair<int, int> now = {a, b};
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int d = 0; d < 4; ++d) {
        int cur = 0;
        bool last = 0;
        for (int k = 0; k < 3; ++k) {
          int x = i + dx[d] * k, y = j + k * dy[d];
          if (x < 0 || x >= 4 || y < 0 || y>= 4) break;
          if (make_pair(x, y) == now) last = 1;
          int val = x * 4 + y;
          cur |= 1 << val;
        }
        if (__builtin_popcount(cur) == 3) {
          if (last)
            mask.push_back(cur);
          else
            unmask.push_back(cur);
        }
      }
    }
  }
  bpos = 1 << pos;
  cnt[st] = 1;
  solve(1 << st, 0, 0);
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  printf("%d\n", ans.size());
  return 0;
}