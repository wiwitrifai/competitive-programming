#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#pragma GCC target ("sse4")
 
#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <stack>
#include <queue>
 
#include <tuple>
 
#define getchar getchar_unlocked
#define putchar putchar_unlocked
 
#define _rep(_1, _2, _3, _4, name, ...) name
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) rep4(i, a, b, 1)
#define rep4(i, a, b, c) for (int i = int(a); i < int(b); i += int(c))
#define rep(...) _rep(__VA_ARGS__, rep4, rep3, rep2, _)(__VA_ARGS__)
 
using namespace std;
 
using i8 = signed char;
using i16 = signed short;
using i64 = long long;
using u8 = unsigned char;
using u32 = unsigned;
using u64 = unsigned long long;
using f80 = long double;
 
const int M = 1e5;
struct node {
  int par, id, head;
};
i16 values[M + 1];
node nodes[M + 1];
 
int A[M + 1], heavy[M + 1];
vector<int> edges[M + 1];
int dfs(int v, int prev=-1) {
  int c = 1, best = 0, h = -1, cnt;
  for (auto w : edges[v]) if (w != prev) {
    nodes[w].par = v;
    c += cnt = dfs(w, v);
    if (cnt > best) best = cnt, h = w;
  }
  heavy[v] = h;
  return c;
}
 
void decompose(int v) {
  queue<int> que;
  que.push(v);
  int id = 0;
  while (!que.empty()) {
    int len = 0, v = que.front(); que.pop();
    for (int w = v; w != -1; w = heavy[w], ++len) {
      values[id] = A[w];
      nodes[w].head = v, nodes[w].id = id++;
      for (auto u : edges[w]) {
        if (u != nodes[w].par && u != heavy[w]) que.push(u);
      }
    }
    nodes[v].head = -len;
  }
}
 
int head(int v) {
  return nodes[v].head < 0 ? v : nodes[v].head;
}
 
pair<int, int> path_len(int v, int w) {
  int vlen = 0, wlen = 0;
  while (1) {
    int hv = head(v), hw = head(w);
    if (hv == hw) break;
    if (nodes[hv].id > nodes[hw].id) {
      vlen += nodes[v].id - nodes[hv].id + 1; v = nodes[hv].par;
    } else {
      wlen += nodes[w].id - nodes[hw].id + 1; w = nodes[hw].par;
    }
  }
  if (nodes[w].id > nodes[v].id) wlen += nodes[w].id - nodes[v].id + 1;
  else vlen += nodes[v].id - nodes[w].id + 1;
  return {vlen, wlen};
}
 
i16 path1[M + 1];
i16 path2[M + 1];
i16 temp[M + 1];
 
void read_vals(int beg, int len, i16* dest) {
  rep(i, len) dest[i] = values[beg + i];
}
void write_vals(i16* src, int beg, int len) {
  rep(i, len) values[beg + i] = src[i];
}
 
void get_path(int v, int w, int vlen, int wlen, i16* vals) {
  auto* pw = vals + wlen; 
  auto* pv = pw + vlen;
  while (1) {
    int hv = head(v), hw = head(w);
    if (hv == hw) break;
    if (nodes[hv].id > nodes[hw].id) {
      int l = nodes[v].id - nodes[hv].id + 1;
      read_vals(nodes[hv].id, l, pv -= l); v = nodes[hv].par;
    } else {
      int l = nodes[w].id - nodes[hw].id + 1;
      read_vals(nodes[hw].id, l, pw -= l); w = nodes[hw].par;
    }
  }
  if (nodes[w].id > nodes[v].id) {
    int l = nodes[w].id - nodes[v].id + 1;
    read_vals(nodes[v].id, l, pw -= l);
  } else {
    int l = nodes[v].id - nodes[w].id + 1;;
    read_vals(nodes[w].id, l, pv -= l);
  }
}
 
void set_path(int v, int w, int vlen, int wlen, i16* vals) {
  auto* pw = vals + wlen; 
  auto* pv = pw + vlen;
  while (1) {
    int hv = head(v), hw = head(w);
    if (hv == hw) break;
    if (nodes[hv].id > nodes[hw].id) {
      int l = nodes[v].id - nodes[hv].id + 1;
      write_vals(pv -= l, nodes[hv].id, l); v = nodes[hv].par;
    } else {
      int l = nodes[w].id - nodes[hw].id + 1;
      write_vals(pw -= l, nodes[hw].id, l); w = nodes[hw].par;
    }
  }
  if (nodes[w].id > nodes[v].id) {
    int l = nodes[w].id - nodes[v].id + 1;
    write_vals(pw -= l, nodes[v].id, l);
  } else {
    int l = nodes[v].id - nodes[w].id + 1;;
    write_vals(pv -= l, nodes[w].id, l);
  }
}
 
void reverse(i16* a, int N, i16* res=nullptr) {
  if (res == nullptr) {
    rep(i, N) temp[i] = a[N - 1 - i];
    rep(i, N) a[i] = temp[i];
  } else {
    rep(i, N) res[i] = a[N - 1 - i];
  }
}
 
bool same_path(i16* a, i16* b, int N) {
  i16 ret = 0;
  rep(i, N) ret |= a[i] ^ b[i];
  return ret == 0;
}
 
int get_int() {
  int c, n;
  while ((c = getchar()) < '0');
  n = c - '0';
  while ((c = getchar()) >= '0') n = n * 10 + (c - '0');
  return n;
}
 
void solve() {
  int N, Q;
  while (~scanf("%d %d", &N, &Q)) {
    rep(i, N) A[i] = get_int();
    rep(i, N) edges[i].clear();
    rep(i, N - 1) {
      int v = get_int() - 1, w = get_int() - 1;
      edges[v].push_back(w);
      edges[w].push_back(v);
    }
    dfs(0);
    decompose(0);
 
    // O(QN)
    rep(i, Q) {
      int c = get_int();
      int v = get_int() - 1;
      int w = get_int() - 1;
 
      auto l1 = path_len(v, w);
      int vlen1, wlen1; tie(vlen1, wlen1) = l1;
      int len1 = vlen1 + wlen1;
      get_path(v, w, vlen1, wlen1, path1);
 
      if (c == 1) {
        if (wlen1 >= vlen1) {
          rep(i, vlen1) path2[i + wlen1] = path1[wlen1 - vlen1 + i];
          rep(i, vlen1) path2[wlen1 - vlen1 + i] = path1[i + wlen1];
          reverse(path1, wlen1 - vlen1, path2);
        } else {
          rep(i, wlen1) path2[i] = path1[len1 - wlen1 + i];
          rep(i, wlen1) path2[len1 - wlen1 + i] = path1[i];
          reverse(path1 + wlen1, vlen1 - wlen1, path2 + wlen1);
        }
        set_path(v, w, vlen1, wlen1, path2);
 
      } else {
        int v2 = get_int() - 1;
        int w2 = get_int() - 1;
        auto l2 = path_len(v2, w2);
        int vlen2, wlen2; tie(vlen2, wlen2) = l2;
        int len2 = vlen2 + wlen2;
 
        assert(len1 == len2);
 
        if (c == 2) {
          get_path(v2, w2, vlen2, wlen2, path2);
 
          auto* p1 = path1, *p2 = path2;
          if (wlen1 < wlen2) swap(wlen1, wlen2), swap(p1, p2);
          bool same = true;
          same = same && same_path(p1 + wlen1, p2 + wlen1, len1 - wlen1);
          same = same && same_path(p1 + wlen1 - wlen2, p2, wlen2);
          if (same) {
            reverse(p1, wlen1 - wlen2, temp);
            same = same_path(temp, p2 + wlen2, wlen1 - wlen2);
          }
          puts(same ? "Yes" : "No");
 
        } else if (c == 3) {
          if (wlen1 > wlen2) {
            rep(i, vlen1) path2[wlen1 + i] = path1[wlen1 + i];
            rep(i, wlen2) path2[i] = path1[wlen1 - wlen2 + i];
            reverse(path1, wlen1 - wlen2, path2 + wlen2);
          } else {
            rep(i, vlen2) path2[wlen2 + i] = path1[wlen2 + i];
            rep(i, wlen1) path2[wlen2 - wlen1 + i] = path1[i];
            reverse(path1 + wlen1, wlen2 - wlen1, path2);
          }
          set_path(v2, w2, vlen2, wlen2, path2);
          
        } else {
          assert(0);
        }
      }
 
    }
  }
}
 
int main() {
  clock_t beg = clock();
  solve();
  clock_t end = clock();
  fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
  return 0;
}