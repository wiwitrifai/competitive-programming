#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, w, h;
// 0 : down, 1 : right, 2 : up, 3 : left
int getPos(int x, int y) {
  if (y == 0) return 0;
  if (x == w) return 1;
  if (y == h) return 2;
  if (x == 0) return 3;
  assert(false);
}

bool used[N];

int main() {
  scanf("%d %d %d", &n, &w, &h);
  vector<pair<int, int> > up, down, right, left;
  for (int i = 0; i < n; ++i) {
    int xa, ya, xb, yb;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    int pa = getPos(xa, ya);
    if (pa == 0) {
      down.emplace_back(xa, i);
    }
    else if (pa == 1) {
      right.emplace_back(ya, i);
    }
    else if (pa == 2) {
      up.emplace_back(xa, i);
    }
    else {
      left.emplace_back(ya, i);
    }
    int pb = getPos(xb, yb);
    if (pb == 0) {
      down.emplace_back(xb, i);
    }
    else if (pb == 1) {
      right.emplace_back(yb, i);
    }
    else if (pb == 2) {
      up.emplace_back(xb, i);
    }
    else {
      left.emplace_back(yb, i);
    }
  }
  sort(down.begin(), down.end());
  sort(right.begin(), right.end());
  sort(up.begin(), up.end());
  reverse(up.begin(), up.end());
  sort(left.begin(), left.end());
  reverse(left.begin(), left.end());
  vector<tuple<int, int, int>> all;
  for (auto it : down)
    all.push_back(make_tuple(it.second, it.first, 0));
  for (auto it : right)
    all.push_back(make_tuple(it.second, w, it.first));
  for (auto it : up)
    all.push_back(make_tuple(it.second, it.first, h));
  for (auto it : left)
    all.push_back(make_tuple(it.second, 0, it.first));
  int cnt = 0;
  for (int i = 0, j = 0; i < all.size(); ++i) {
    while (!used[get<0>(all[j])]) {
      used[get<0>(all[j])] = 1;
      ++cnt;
      ++j;
      if (j >= all.size()) j = 0;
    }
    if (cnt == n) {
      puts("1");
      int ixa, ixb, iya, iyb;
      tie(ignore, ixa, iya) = all[i];
      tie(ignore, ixb, iyb) = all[j];
      double xa = ixa, ya = iya, xb = ixb, yb = iyb;
      int pa = getPos(xa, ya);
      if (pa == 0) {
        printf("%.10lf %.10lf ", xa-0.5, ya);
      }
      else if (pa == 1) {
        printf("%.10lf %.10lf ", xa, ya-0.5);
      }
      else if (pa == 2) {
        printf("%.10lf %.10lf ", xa+0.5, ya);
      }
      else
        printf("%.10lf %.10lf ", xa, ya+0.5);
      int pb = getPos(xb, yb);
      if (pb == 0) {
        printf("%.10lf %.10lf\n", xb-0.5, yb);
      }
      else if (pb == 1) {
        printf("%.10lf %.10lf\n", xb, yb-0.5);
      }
      else if (pb == 2) {
        printf("%.10lf %.10lf\n", xb+0.5, yb);
      }
      else
        printf("%.10lf %.10lf\n", xb, yb+0.5);
      return 0;
    }
    --cnt;
    used[get<0>(all[i])] = 0;
  }
  puts("2");
  printf("%.10lf %.10lf %.10lf %.10lf\n", (double)0, (double)0.5, (double)w, (double)h - 0.5);
  printf("%.10lf %.10lf %.10lf %.10lf\n", (double)0, (double)h-0.5, (double)w, (double)0.5);
  return 0;
}

