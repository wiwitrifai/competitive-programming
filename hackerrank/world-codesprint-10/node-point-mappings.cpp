#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
typedef pair< long long, long long > point;
#define x first
#define y second
long long cross(point a, point b, point c) {
  return (b.x-a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
point p[N];
vector< int > g[N];
int ans[N], sz[N];
int n;
point pivot;
bool cmp(int l, int r) {
  return cross(pivot, p[l], p[r]) < 0;
}
vector< pair< point, point > > pp;
void dfs(int v, vector< int > cand, int par = -1) {
  if (par == -1) {
    ans[v] = -1;
    for (int i : cand) {
      if (ans[v] == -1 || p[i] > p[ans[v]])
        ans[v] = i;
    }
    assert(ans[v] >= 0);
  }
  else {
    ans[v] = -1;
    int sp = ans[par];
    for (int i : cand) {
      if (ans[v] == -1 || cross(p[sp], p[ans[v]], p[i]) < 0)
        ans[v] = i;
    }
    assert(ans[v] >= 0);
    pp.push_back(make_pair(p[ans[v]], p[sp]));
  }
  vector < int > res;
  for (int i : cand) if (i != ans[v])
    res.push_back(i);
  pivot = p[ans[v]];
  sort(res.begin(), res.end(), cmp);
  int now = 0;
  for (int u : g[v]) if (u != par)
    dfs(u, vector<int>(res.begin()+now, res.begin()+now+sz[u]), v), now += sz[u];
}
void pre(int v, int par = -1) {
  sz[v] = 1;
  for (int u : g[v]) if (u != par)
    pre(u, v), sz[v] += sz[u];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  std::vector<int> cand;
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &p[i].x, &p[i].y);
    cand.push_back(i);
  }
  memset(ans, -1, sizeof ans);
  pre(0);
  dfs(0, cand);
  for (int i = 0; i < n; i++)
    printf("%d ", ans[i]);
  for (int i = 0; i < pp.size(); i++) {
    for (int j = i+1; j < pp.size(); j++) {
      if (cross(pp[i].x, pp[i].y, pp[j].x) * cross(pp[i].x, pp[i].y, pp[j].y) >= 0) continue;
      if (cross(pp[j].x, pp[j].y, pp[i].x) * cross(pp[j].x, pp[j].y, pp[i].y) >= 0) continue;
      cerr << pp[i].x.x << " " << pp[i].x.y << " " << pp[i].y.x << " " << pp[i].y.y << " "
           << pp[j].x.x << " " << pp[j].x.y << " " << pp[j].y.x << " " << pp[j].y.y << endl;
      assert(false);
    }
  }
  return 0;
}