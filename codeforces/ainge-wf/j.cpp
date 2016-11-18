#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 1e5 + 5;

vector<pair<int, int>> edge[N];
int lef[N], rig[N];
vector<int> st;

void dfs()

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int u, v, c;
    scanf("%d %d", &u, &v, &c);
    edge[u].emplace_back(v, c);
    edge[v].emplace_back(u, c);
    ans = c;
  }
  if (n == 1) {
    printf("0 0\n");
    return 0;
  } else if (n == 2) {
    printf("%d %d\n", ans, ans);
    return 0;
  }
  

  
  return 0;
}