/**
  IEEExtreme Programming Contest 10
  Problem : Checkers Challange
  Solver  : Wiwit Rifa'i
  Status  : Partial Score

  Using Heuristic (A* Search Algorith) 
*/


#include <bits/stdc++.h>

using namespace std;

const int N = 1<<25;
const int B = 13;
const int C = 10;
const int D = 2;

char s[10][10], t[10][10];
bitset< N > vis;
bool x[7][7];
int to, from;

int get() {
  int nx = 0;
  for (int k = 0; k < 5; k++) {
    for (int z = 0; z < 5; z++) {
      if (x[k][z])
        nx |= 1<<(k * 5 + z);
    }
  }
  return nx;
}
void print() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d", x[i][j]);
    }
    printf("\n");
  }
}

int heu(int v) {
  int u = v ^ to;
  return __builtin_popcount(u) * D;
  int ret = 0;
  for (int i = 0; i < 5; i++) {
    if (u & 31)
      ret++;
    u >>= 5;
  }
  return ret;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    for (int i = 0; i < 5; i++) {
      scanf("%s %s", s[i], t[i]);
    }
    from = 0, to = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (s[i][j] == 'X')
          from |= 1<< (i * 5 + j);
        if (t[i][j] == 'X')
          to |= 1<<(i * 5 + j);
      }
    }
    vis.reset();
    vis[from] = 1;
    priority_queue< pair<int, int> > pq; 
    // pq.push({-__builtin_popcount(from ^ to), from});
    pq.push({-heu(from), from});
    int ans = B;
    while (!pq.empty()) {
      auto it = pq.top();
      int cost = -it.first, v = it.second;
      pq.pop();
      int h = heu(v), g = cost - h;
      // int h = 0, g = cost;
      if (v == to) {
        ans = g/C;
        break;
      }
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          x[i][j] = (v >> (i * 5 + j)) & 1;
        }
      }
      // cerr << v << " " << g << " " << h << endl;
      // print();
      for (int len = 1; len <= 5; len++) {
        for (int i = 0; i <= 5-len; i++) {
          for (int j = 0; j <= 5-len; j++) {
            // negate
            // if (len == 3)
            //   cerr << i << " " << j << endl;
            for (int k = 0; k < len; k++) {
              for (int z = 0; z < len; z++) {
                x[i+k][j+z] = !x[i+k][j+z];
              }
            }
            int nx = get();
            int ncost = (g+C+heu(nx));
            // int ncost = (g+1);
            if (!vis[nx]) {
              pq.push({-ncost, nx});
              vis[nx] = 1;
            }
            for (int k = 0; k < len; k++) {
              for (int z = 0; z < len; z++) {
                x[i+k][j+z] = !x[i+k][j+z];
              }
            }

            if (len == 1)
              continue;

            // flip horizontal
            for (int k = 0; k < len; k++) {
              for (int z = 0, y = len-1; z < y; z++, y--) {
                swap(x[i+k][j+z], x[i+k][j+y]);
              }
            }
            nx = get();
            // ncost = (g+1+__builtin_popcount(nx ^ to));
            ncost = (g+C+heu(nx));
            if (!vis[nx]) {
              pq.push({-ncost, nx});
              vis[nx] = 1;
            }
            for (int k = 0; k < len; k++) {
              for (int z = 0, y = len-1; z < y; z++, y--) {
                swap(x[i+k][j+z], x[i+k][j+y]);
              }
            }

            // flip vertical

            for (int k = 0; k < len; k++) {
              for (int z = 0, y = len-1; z < y; z++, y--) {
                swap(x[i+y][j+k], x[i+z][j+k]);
              }
            }
            nx = get();
            // ncost = (g+1+__builtin_popcount(nx ^ to));
            ncost = (g+C+heu(nx));
            if (!vis[nx]) {
              pq.push({-ncost, nx});
              vis[nx] = 1;
            }
            for (int k = 0; k < len; k++) {
              for (int z = 0, y = len-1; z < y; z++, y--) {
                swap(x[i+y][j+k], x[i+z][j+k]);
              }
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}