#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;
const int D = 10;

int n;
bool graph[N][N], pairs[N][N];
vector<int> up[N];

bool local[D][D];
int matching[1 << D];
int lowbit[1 << D];

int dfs(int u, int f) {
  int result = 0;
  vector<int> sons;
  for (int v = 0; v < n; ++v) {
    if (graph[u][v] && v != f) {
      result += dfs(v, u);
      sons.push_back(v);
    }
  }
  
  for (int i = 0; i < sons.size(); ++i) {
    for (int a : up[sons[i]]) {
      if (pairs[u][a]) {
        result++;
        up[sons[i]].clear();
        break;
      }
    }
  }

  for (int i = 0; i < sons.size(); ++i) {
    for (int j = i + 1; j < sons.size(); ++j) {
      local[i][j] = false;
      for (int a : up[sons[i]])
        for (int b : up[sons[j]])
          if (pairs[a][b])
            local[i][j] = true;
    }
  }

  matching[0] = 0;
  for (int m = 1; m < (1 << sons.size()); ++m) {
    int a = lowbit[m];
    matching[m] = matching[m - (1 << a)];
    for (int b = a + 1; b < sons.size(); ++b) {
      if (((m >> b) & 1) && local[a][b])
        matching[m] = max(matching[m], 1 + matching[m - (1 << a) - (1 << b)]);
    }
  }
  result += matching[(1 << sons.size()) - 1];
  up[u] = vector<int>(1, u);
  for (int i = 0; i < sons.size(); ++i)
    if (matching[(1 << sons.size()) - 1] == 
        matching[(1 << sons.size()) - 1 - (1 << i)])
      for (int x : up[sons[i]])
        up[u].push_back(x);
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);

  for (int i = 1; i < (1 << D); ++i)
    lowbit[i] = (i & 1) ? 0 : (1 + lowbit[i >> 1]);

  int Z;
  cin >> Z;
  while (Z--) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        graph[i][j] = pairs[i][j] = false;
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      graph[a][b] = graph[b][a] = true;
    }
    int m;
    cin >> m;
    while (m--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      pairs[a][b] = pairs[b][a] = true;
    }
    cout << dfs(0, -1) << endl;
  }
}
