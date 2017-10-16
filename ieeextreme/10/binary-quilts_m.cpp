/**
  IEEExtreme Programming Contest 10
  Problem : Checkers Challange
  Solver  : Wiwit Rifa'i
  Status  : Accepted

  Using Meet in the Middle 
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1<<25;
const int B = 10;

char s[10][10], t[10][10];
int d1[N], d2[N];
bool x[7][7];
int to, from;
vector< int > flip;
vector< int > hor[7][7][7];
vector< int > ver[7][7][7];

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

int main() {
  for (int len = 0; len < 5; len++) { 
    for (int i = 0; i < 5-len; i++) {
      for (int j = 0; j < 5-len; j++) {
        int now = 0;
        for (int a = 0; a <= len; a++) {
          for (int b = 0; b <= len; b++) {
            now |= 1<< ((i+a) * 5 + j + b);
          }
        }
        flip.push_back(now);
      }
    }
  }
  for (int len = 2; len <= 5; len++) {
    for (int i = 0; i <= 5-len; i++) {
      for (int j = 0; j <= 5-len; j++) {
        int now = 0;
        for (int k = 0; k < len; k++) {
          now |= 1<<(i * 5 + j + k);
        }
        for (int k = 0; k < len; k++) {
          hor[len][i][j].push_back(now);
          now <<= 5;
        }
        now = 0;
        for (int k = 0; k < len; k++) {
          now |= 1 << (i * 5 + j + k * 5);
        }
        for (int k = 0; k < len; k++) {
          ver[len][i][j].push_back(now);
          now <<= 1;
        }
      }
    }
  }
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
    memset(d1, -1, sizeof d1);
    memset(d2, -1, sizeof d2);
    queue< int > pq1, pq2;
    pq1.push(from);
    pq2.push(to);
    d1[from] = 0;
    d2[to] = 0;
    int now = 0, ans = -1;
    while (ans == -1) {
      now++;
      while (!pq1.empty() && ans == -1) {
        int v = pq1.front();
        // cerr << 1 << " " << v << endl;
        int cost = d1[v];
        if (cost > now) break;
        pq1.pop();

        if (d1[v] >= 0 && d2[v] >= 0) {
          ans = d1[v] + d2[v];
          break;
        }
        int ncost = cost + 1;
        // negate
        for (int u : flip) {
          int nx = v ^ u;
          if (d1[nx] == -1) {
            pq1.push(nx);
            d1[nx] = ncost;
          }
        }
   
        for (int len = 2; len <= 5; len++) {
          for (int i = 0; i <= 5-len; i++) {
            for (int j = 0; j <= 5-len; j++) {
              // flip horizontal
              int nx = v;
              for (int k = 0; k < len; k++) {
                nx &= ~hor[len][i][j][k];
              }
              for (int k = 0, l = len-1; k <= l; k++, l--) {
                nx |= (v & hor[len][i][j][k]) << (5 * (l-k));
                nx |= (v & hor[len][i][j][l]) >> (5 * (l-k));
              }
              if (d1[nx] == -1) {
                pq1.push(nx);
                d1[nx] = ncost;
              }
              // flip vertical
              nx = v;
              for (int k = 0; k < len; k++) {
                nx &= ~ver[len][i][j][k];
              }
              for (int k = 0, l = len-1; k <= l; k++, l--) {
                nx |= (v & ver[len][i][j][k]) << (l-k);
                nx |= (v & ver[len][i][j][l]) >> (l-k);
              }
              if (d1[nx] == -1) {
                pq1.push(nx);
                d1[nx] = ncost;
              }          
            }
          }
        }
      }
      while (!pq2.empty() && ans == -1) {
        int v = pq2.front();
        int cost = d2[v];
        if (cost > now) break;
        pq2.pop();

        if (d1[v] >= 0 && d2[v] >= 0) {
          ans = d1[v] + d2[v];
          break;
        }
        int ncost = cost + 1;
        // negate
        for (int u : flip) {
          int nx = v ^ u;
          if (d2[nx] == -1) {
            pq2.push(nx);
            d2[nx] = ncost;
          }
        }
   
        for (int len = 2; len <= 5; len++) {
          for (int i = 0; i <= 5-len; i++) {
            for (int j = 0; j <= 5-len; j++) {
              // flip horizontal
              int nx = v;
              for (int k = 0; k < len; k++) {
                nx &= ~hor[len][i][j][k];
              }
              for (int k = 0, l = len-1; k <= l; k++, l--) {
                nx |= (v & hor[len][i][j][k]) << (5 * (l-k));
                nx |= (v & hor[len][i][j][l]) >> (5 * (l-k));
              }
              if (d2[nx] == -1) {
                pq2.push(nx);
                d2[nx] = ncost;
              }
              // flip vertical
              nx = v;
              for (int k = 0; k < len; k++) {
                nx &= ~ver[len][i][j][k];
              }
              for (int k = 0, l = len-1; k <= l; k++, l--) {
                nx |= (v & ver[len][i][j][k]) << (l-k);
                nx |= (v & ver[len][i][j][l]) >> (l-k);
              }
              if (d2[nx] == -1) {
                pq2.push(nx);
                d2[nx] = ncost;
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