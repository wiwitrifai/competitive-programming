#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
pair<int, int > point[N];
int cntr[N], cntl[N];


vector< int > vy;
int id(int y) {
  return lower_bound(vy.begin(), vy.end(), y)-vy.begin();
}

int main() {
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);
  scanf("%d", &n);
  vy.clear();
  for(int i = 0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    point[i] = make_pair(x, y);
    vy.push_back(y);
  }
  int ans = n;
  sort(point, point+n);
  sort(vy.begin(), vy.end());
  vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
  memset(cntl, 0, sizeof cntl);
  memset(cntr, 0, sizeof cntr);
  for(int i = 0; i<n; i++) {
    cntr[id(point[i].second)]++;
  }
  int x = -1, y = 0, region[5];
  memset(region, 0, sizeof region);
  region[3] = n;
  for(int i = 0; i<n; i++) {
    if(x != point[i].first) {
      assert(x < point[i].first);
      while((y < (int)vy.size()) && (max(region[0], max(region[1], max(region[2], region[3]))) >= max(region[0] + cntl[y], max(region[1] -cntl[y], max(region[2] + cntr[y], region[3]-cntr[y]))))) {
        region[0] += cntl[y];
        region[1] -= cntl[y];
        region[2] += cntr[y];
        region[3] -= cntr[y];
        y++;
      }
      while((y > 0) && (max(region[0], max(region[1], max(region[2], region[3]))) >= max(region[0] - cntl[y-1], max(region[1] + cntl[y-1], max(region[2] - cntr[y-1], region[3] + cntr[y-1]))))) {
        y--;
        region[0] -= cntl[y];
        region[1] += cntl[y];
        region[2] -= cntr[y];
        region[3] += cntr[y];
      }
      ans = min(ans, max(region[0], max(region[1], max(region[2], region[3]))));
      x = point[i].first;
    }
    int idy = id(point[i].second);
    cntr[idy]--;
    cntl[idy]++;
    if(idy < y)
      region[0]++, region[2]--;
    else
      region[1]++, region[3]--;
  }
  while((y < (int)vy.size()) && (max(region[0], max(region[1], max(region[2], region[3]))) >= max(region[0] + cntl[y], max(region[1] -cntl[y], max(region[2] + cntr[y], region[3]-cntr[y]))))) {
    region[0] += cntl[y];
    region[1] -= cntl[y];
    region[2] += cntr[y];
    region[3] -= cntr[y];
    y++;
  }
  while((y > 0) && (max(region[0], max(region[1], max(region[2], region[3]))) >= max(region[0] - cntl[y-1], max(region[1] + cntl[y-1], max(region[2] - cntr[y-1], region[3] + cntr[y-1]))))) {
    y--;
    region[0] -= cntl[y];
    region[1] += cntl[y];
    region[2] -= cntr[y];
    region[3] += cntr[y];
  }
  ans = min(ans, max(region[0], max(region[1], max(region[2], region[3]))));
  assert(region[0]+region[1]+region[2]+region[3] == n);
  printf("%d\n", ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}