#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const double inf = 1e18;
const double eps = 1e-13;

double dist[N];
vector<pair<int, double>> edge[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      edge[i].clear();
    }
    
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
      int from, to; double c;
      scanf("%d %d %lf", &to, &from, &c);
      edge[from].emplace_back(to, c);
    }
    for(int i = 1; i <= n; i++) {
      dist[i] = inf;
      edge[0].emplace_back(i, 0);
    }
    dist[0] = 0;
    for(int iter = 0; iter < n; iter++) {
      for(int i = 0; i <= n; i++) {
        for(auto it : edge[i]) {
          dist[it.first] = min(dist[it.first], dist[i] + it.second);
        }
      }
    }
    bool has = 0;
    for(int iter = 0; iter < n; iter++) {
      for(int i = 0; i <= n; i++) {
        for(auto it : edge[i]) {
          int to; double c;
          tie(to, c) = it;
          if(dist[to] - eps > dist[i] + c) {
            //printf("sampah %d %d\n", i, to);
            has = 1;
          }
        }
      }
    }
    if(has) {
      puts("NO SOLUTION");
      continue;
    }
    double mini = inf;
    for(int i = 1; i <= n; i++) {
      mini = min(mini, dist[i]);
      if(i > 1) printf(" ");
      printf("%.15lf", dist[i]);
    }
    printf("\n%.15lf\n", -mini);
  }
  
  return 0;
}