#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.);
const double eps = 1e-7;
const int N = 55;

#define point pair<int, int>
#define x first
#define y second

int sq_dist(point A, point B) {
  return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

double dist(point A, point B) {
  return sqrt(sq_dist(A, B));
}

double radToDeg(double a) {
  return a * 180 / PI;
}

bool tajam(point A, point B, point C) {
  point BA(A.x - B.x, A.y - B.y), BC(C.x - B.x, C.y - B.y);
  long long dot = 1LL * BA.x * BC.x + 1LL * BA.y * BC.y;
  if (dot >= 0) return 1;
  dot *= dot * 2;
  long long dba = 1LL * BA.x * BA.x + 1LL * BA.y * BA.y;
  long long dbc = 1LL * BC.x * BC.x + 1LL * BC.y * BC.y;
  return (dot < dba * dbc);
}

point a[N];
int n;

bool tajam() {
  for (int i = 1; i + 1 < n; i++) {
    if (tajam(a[i-1], a[i], a[i+1])) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].x, &a[i].y);
    if (!tajam()) {
      puts("yes yes");
    } else {
      bool can = 0;
      for (int i = 0; i < n; i++) {
        point tmp = a[i];
        for (int x = 0; x <= 50; x++) {
          for (int y = 0; y <= 50; y++) {
            a[i] = {x, y};
            bool same = 0;
            for (int j = 0; j < n; j++) {
              if (j == i) continue;
              if (a[i] == a[j]) {
                same = 1;
                break;
              }
            }
            if (same) continue;
            if (!tajam()) {
              can = 1;
              goto hell;
            }
          }
        }
        a[i] = tmp;
      }
      hell:;
      puts(can? "no yes" : "no no");
    }
  }

  return 0;
}
