#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 9;

double dpmax[N], dpmin[N];
bool visx[N], visn[N];
int deco(int mask) {
  int ret = 0;
  for (int i = 0; i < 9; ++i) {
    if (mask & (1 << i)) {
      ret = ret * 10 + i + 1;
    }
  }
  return ret;
}

int enco(int val) {
  int mask = 0;
  while (val) {
    int r = val % 10;
    val /= 10;
    mask |= 1 << (r - 1);
  }
  return mask;
}

vector<int> tra[37];
int to_val[N];
double p[37];

double solve_max(int mask);
pair<double, int> select_max(int mask, int sum) {
  int used = -1;
  double best = -1;
  for (int t : tra[sum]) {
    if ((mask & t) != t) continue;
    int cur = mask ^ t;
    double res = solve_max(cur);
    if (used == -1 || res >= best) {
      used = deco(t);
      best = res;
    }
  }
  if (used == -1)
    best = deco(mask);
  return make_pair(best, used);
}

double solve_max(int mask) {
  if (mask == 0)
    return 0;
  if (visx[mask])
    return dpmax[mask];
  visx[mask] = 1;
  dpmax[mask] = 0;
  for (int sum = 2; sum <= 12; ++sum) {
    auto res = select_max(mask, sum);
    dpmax[mask] += p[sum] * res.first;
  }
  return dpmax[mask];
}

double solve_min(int mask);
pair<double, int> select_min(int mask, int sum) {
  int used = -1;
  double best = -1;
  for (int t : tra[sum]) {
    if ((mask & t) != t) continue;
    int cur = mask ^ t;
    double res = solve_min(cur);
    if (used == -1 || res <= best) {
      used = deco(t);
      best = res;
    }
  }
  if (used == -1)
    best = deco(mask);
  return make_pair(best, used);
}

double solve_min(int mask) {
  if (mask == 0)
    return 0;
  if (visn[mask])
    return dpmin[mask];
  visn[mask] = 1;
  dpmin[mask] = 0;
  for (int sum = 2; sum <= 12; ++sum) {
    auto res = select_min(mask, sum);
    dpmin[mask] += p[sum] * res.first;
  }
  return dpmin[mask];
}


int main() {
  for (int i = 0; i < N; ++i) {
    int sum = 0;
    for (int j = 0; j < 9; ++j) {
      if (i & (1 << j)) {
        sum += j+1;
      }
    }
    if (sum <= 12)
      tra[sum].push_back(i);
  }
  for (int i = 0; i <= 12; ++i)
    p[i] = 0;
  for (int i = 1; i <= 6; ++i)
    for (int j = 1; j <= 6; ++j) {
      p[i+j] += 1;
    }
  for (int i = 0; i <= 12; ++i) {
    p[i] /= 36;
  }
  int val, a, b;
  scanf("%d %d %d", &val, &a, &b);
  int mask = enco(val);
  auto ansmin = select_min(mask, a+b);
  auto ansmax = select_max(mask, a+b);
  printf("%d %.5lf\n", ansmin.second, ansmin.first);
  printf("%d %.5lf\n", ansmax.second, ansmax.first);
  return 0;
}
