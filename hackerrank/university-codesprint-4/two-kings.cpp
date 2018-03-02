#include <bits/stdc++.h>

using namespace std;

const int N = 8;

int mask[N][N];
bool used[N * N + N];
bool valid(int x, int y) {
  return 0 <= min(x, y) && max(x, y) < 8;
}

int a, b, c, d;
vector<int> ans;
bool kena(int x, int y, int p, int q) {
  return (x == p || y == q || abs(p-x) == abs(q-y));
}
bool diantara(int x, int y, int p, int q, int r, int s) {
  x -= p, y -= q;
  r -= p, s -= q;
  if (x * s - r * y) return 0;
  return x * r + s * y < 0;
}
bool hayo(int x, int y, int p, int q, int r, int s) {
  if (make_pair(r, s) == make_pair(x, y) || make_pair(x, y) == make_pair(p, q)) return false;
  if (!kena(x, y, r, s)) return false;
  return !(diantara(x, y, p, q, r, s));
}
bool kuda(int x, int y, int p, int q, int r, int s) {
  if (make_pair(r, s) == make_pair(x, y) || make_pair(x, y) == make_pair(p, q)) return false;
  int dx = abs(x-r), dy = abs(y-s);
  if (dx > dy) swap(dx, dy);
  return dx == 1 && dy == 2;
}
vector<pair<int, int> > semua;
bool cek() {
  for (auto it : semua) {
    a = it.first / 8, b = it.first % 8;
    c = it.second / 8, d = it.second % 8;
    bool ok = 0;
    for (int r : ans) {
      int z = r % 64;
      int x = z / 8, y = z % 8;
      if (r >= 64) {
        if (kuda(x, y, a, b, c, d)) {
          ok = 1;
          break;
        }
      }
      else if (hayo(x, y, a, b, c, d)) {
        ok = 1;
        break;
      }
    }
    if (!ok) return false;
    ok = 0;
    for (int r : ans) {
      int z = r % 64;
      int x = z / 8, y = z % 8;
      if (r >= 64) {
        if (kuda(x, y, c, d, a, b)) {
          ok = 1;
          break;
        }
      }
      else if (hayo(x, y, c, d, a, b)) {
        ok = 1;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}
bool solve(int k, int i = 0) {
  if (!k)
    return cek();
  for (; i < 128; ++i) {
    if (used[i & 63]) continue;
    ans.push_back(i);
    used[i & 63] = 1;
    bool ret = solve(k-1, i+1);
    used[i & 63] = 0;
    if (ret) return true;
    ans.pop_back();
  }
  return false;
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(used, 0, sizeof used);
    scanf("%d %d %d %d", &a, &b, &c, &d);
    used[a* 8 + b] = used[c * 8 + d] = 1;
    semua.clear();
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        int x = a + i, y = b + j;
        if (valid(x, y)) {
          int p = x * 8 + y, q = c * 8 + d;
          if (p != q)
            semua.emplace_back(p, q);
        }
        x = c + i, y = d + j;
        if (valid(x, y)) {
          int p = a * 8 + b, q = x * 8 + y;
          if (p != q)
            semua.emplace_back(p, q);
        }
      }
    }
    for (int i = 1; ; ++i) {
      ans.clear();
      bool res = solve(i, 0);
      if (res) assert(ans.size() == i);
      if (res) break;
    }
    printf("%d\n", ans.size());
    for (int z : ans) {
      int x = z % 64;
      printf("%c %d %d\n", z >= 64 ? 'N' : 'Q', x/8, x%8);
    }
  }
  return 0;
}