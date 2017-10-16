#include <bits/stdc++.h>

using namespace std;

const int N = 25;
const long long inf = 1e18;

long long dp[1 << 20];
vector<int> cover[105];
int val[105], got[105];

map<string, int> id;
int n, pt;

int get_id(string s) {
  if (id.count(s)) return id[s];
  id[s] = pt++;
  return id[s];
}

long long dfs(int mask) {
  if (mask + 1 == (1 << pt)) return 0;
  if (dp[mask] != -1) return dp[mask];
  long long ret = inf;
  for (int i = 0; i < n; i++) {
    if ((mask | got[i]) != mask) {
      ret = min(ret, val[i] + dfs(mask | got[i]));
    }
  }
  return dp[mask] = ret;
}

int main() {
  string str;
  while (getline(cin, str)) {
    stringstream ss(str);
    string num, buf;
    ss >> num;
    val[n] = atoi(num.c_str());
    while (ss >> buf) {
      int v = get_id(buf);
      cover[n].push_back(v);
      got[n] |= (1 << v);
    }
    n++;
  }
  //for (int i = 0; i < n; i++) printf("%d %d\n", val[i], got[i]);
  memset(dp, -1, sizeof(dp));
  printf("%lld\n", dfs(0));
  return 0;
}
