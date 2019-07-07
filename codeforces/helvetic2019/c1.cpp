#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n;
int x[N], y[N];
bool check(int id) {
  int xmin = N, xmax = -N;
  int ymin = N, ymax = -N;
  for (int i = 0; i < 4 * n + 1; ++i) {
    if (i == id) continue;
    xmin = min(xmin, x[i]);
    xmax = max(xmax, x[i]);
    ymin = min(ymin, y[i]);
    ymax = max(ymax, y[i]);
  }
  for (int i = 0; i < 4 * n + 1; ++i) {
    if (i == id) continue;
    if (x[i] < xmin || x[i] > xmax || y[i] < ymin || y[i] > ymax) return false;
    if (x[i] == xmin || x[i] == xmax || y[i] == ymin || y[i] == ymax) continue;
    return false;
  }
  int cxmin = 0, cxmax = 0, cymin = 0, cymax = 0;
  for (int i = 0; i < 4 * n + 1; ++i) {
    if (i == id) continue;
    cxmin += x[i] == xmin;
    cxmax += x[i] == xmax;
    cymin += y[i] == ymin;
    cymax += y[i] == ymax;
  }
  if (cxmax < n || cxmin < n || cymax < n || cymin < n)
    return false;
  if ((x[id] == xmin || x[id] == xmax) && ymin <= y[id] && y[id] <= ymax) return false;
  if ((y[id] == ymin || y[id] == ymax) && xmin <= x[id] && x[id] <= xmax) return false;
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < 4 * n + 1; ++i) {
    scanf("%d %d", x+i, y+i);
  }
  for (int i = 0; i < 4 * n + 1; ++i) {
    if (!check(i)) continue;
    printf("%d %d\n", x[i], y[i]);
    return 0;
  }
  return 0;
}
