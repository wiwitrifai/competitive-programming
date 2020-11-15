// WA

#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int dp[N][N][N];
int n, k;

int solve(int id, int a, int b) {
  int & ret = dp[id][a][b];
  cerr << " solve " << id << " " << a << " " << b << endl;
  if (ret != -1)
    return ret;
  if (id == n)
    return ret = ((a == 0) && (b == 0));
  int sisa = n - id;
  if (a >= sisa || b >= sisa)
    return ret = 0;
  ret = 0;
  if (solve(id+1, a, b)) {
    cerr << id << " " << a << " " << b << " = " << 1 << endl;
    return ret = 1;
  }
  if (a > 0 && solve(id+1, a-1, b)) {
    cerr << id << " " << a << " " << b << " = " << 1 << endl;
    return ret = 1;
  }
  if (b > 0 && solve(id+1, a, b-1)) {
    cerr << id << " " << a << " " << b << " = " << 1 << endl;
    return ret = 1;
  }
  if (a > 0 && b > 0 && a < sisa-1 && b < sisa-1 && solve(id+1, a-1, b-1)) {
    cerr << id << " " << a << " " << b << " = " << 1 << endl;
    return ret = 1;
  }
  cerr << id << " " << a << " " << b << " = " << ret << endl;
  return ret;
}

vector<pair<int, int>> ans[2];
vector<int> last[2];

void backtrack(int id, int a, int b) {
  cerr << " backtrack " << id << " " << a << " " << b << endl;
  if (a == 0 && b == 0) {
    for (int i = id; i < n; ++i) {
      last[0][i] = last[1][i] = i;
    }
    return;
  }
  int sisa = n - id;
  assert(solve(id, a, b));
  if (id == n)
    return;
  if (solve(id+1, a, b)) {
    backtrack(id+1, a, b);
    for (int i = 0; i < 2; ++i)
      last[i][id] = id;
    return;
  }
  if (a > 0 && solve(id+1, a-1, b)) {
    backtrack(id+1, a-1, b);
    last[0][id] = id;
    last[1][id] = id;
    for (int i = id+1; i < n; ++i)
      if (last[0][i] == id+1) {
        last[0][i] = id;
      }
    ans[0].emplace_back(id, id+1);
    return;
  }
  if (b > 0 && solve(id+1, a, b-1)) {
    backtrack(id+1, a, b-1);
    last[0][id] = id;
    last[1][id] = id;
    for (int i = id+1; i < n; ++i)
      if (last[1][i] == id+1) {
        last[1][i] = id;
      }
    ans[1].emplace_back(id, id+1);
    return;
  }
  if (a > 0 && b > 0 && a < sisa-1 && b < sisa-1 && solve(id+1, a-1, b-1)) {
    backtrack(id+1, a-1, b-1);
    vector<vector<bool>> can(n, vector<bool>(n, true));
    int selecta = -1, selectb = -1;
    for (int i = id+1; i < n; ++i) {
      can[last[0][i]][last[1][i]] = false;
    }
    for (int i = id+1; i < n; ++i) {
      if (last[0][i] != i) continue;
      for (int j = id+1; j < n; ++j) {
        if (last[1][j] != j) continue;
        if (!can[i][j]) continue;
        selecta = i;
        selectb = j;
      }
    }
    assert(selecta != -1 && selectb != -1);
    last[0][id] = last[1][id] = id;
    for (int i = id+1; i < n; ++i) {
      if (last[0][i] == selecta) {
        last[0][i] = id;
      }
      if (last[1][i] == selectb) {
        last[1][i] = id;
      }
    }
    cerr << selecta << " ? " << selectb << endl;
    ans[0].emplace_back(id, selecta);
    ans[1].emplace_back(id, selectb);
    return;
  }
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d %d", &n, &k);
  if (!solve(0, k, k)) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < 2; ++i)
    last[i].resize(n);
  backtrack(0, k, k);
  for (int i = 0; i < 2; ++i) {
    for (auto & e : ans[i]) {
      printf("%d %d\n", e.first + 1, e.second + 1);
    }
  }
  return 0;
}
