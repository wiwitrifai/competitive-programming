#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5, MAGIC = 500;

int n, u[N], v[N], c[N];
int q, t[N], x[N], y[N];
int pp[N], p[N], nodes;
bool used[N];
map<int, int> to[N];

int get(int node, int col) {
  auto it = to[node].find(col);
  if (it != to[node].end())
    return it->second;
  return to[node][col] = nodes++;
}

long long calc(int m) {
  return 1LL * m * (m-1) /2;
}

int find(int * dsu, int id) {
  return dsu[id] < 0 ? id : dsu[id] = find(dsu, dsu[id]);
}

long long merge(int * dsu, int a, int b) {
  if ((a = find(dsu, a)) == (b = find(dsu, b))) return 0;
  if (dsu[a] > dsu[b])
    swap(a, b);
  long long ret = calc(-dsu[a] - dsu[b]) - calc(-dsu[a]) - calc(-dsu[b]);
  dsu[a] += dsu[b];
  dsu[b] = a;
  return ret;
}
long long sum[N];

int main() {
  scanf("%d", &n);
  nodes = 0;
  for (int i = 0; i+1 < n; i++) {
    scanf("%d %d %d", u+i, v+i, c+i); 
    u[i]--; v[i]--;
    get(u[i], c[i]);
    get(v[i], c[i]);
  }
  int ma = 0;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", t+i, x+i);
    x[i]--;
    if (t[i] != 3)
      scanf("%d", y+i);
    if (t[i] == 1) {
      u[n+i] = get(u[x[i]], y[i]);
      v[n+i] = get(v[x[i]], y[i]);
      c[n+i] = y[i];
    }
    else if (t[i] == 2)
      ma = max(ma, y[i]+1);
  }
  for (int i = 0; i+1 < n; i++) {
    u[i] = get(u[i], c[i]);
    v[i] = get(v[i], c[i]);
  }
  fill(used, used+n, true);
  for (int is = 0; is < q; is += MAGIC) {
    int m = min(q, is+MAGIC);
    fill(p, p+nodes, -1);
    set<int> e;
    for (int j = is; j < m; j++)
      if (t[j] == 1)
        used[x[j]] = 0, e.insert(x[j]);
    fill(sum, sum + ma, 0);
    for (int j = 0; j+1 < n; j++) if (used[j])
      sum[c[j]] += merge(p, u[j], v[j]);
    for (int pe : e)
      used[pe] = 1;
    for (int j = 1; j < ma; j++)
      sum[j] += sum[j-1];
    for (int j = is; j < m; j++) {
      if (t[j] == 1) {      
        int pe = x[j];
        u[pe] = u[j+n];
        v[pe] = v[j+n];
        c[pe] = c[j+n];
      }
      else {
        for (int pe : e) {
          int uu = u[pe], vv = v[pe];
          uu = find(p, uu);
          vv = find(p, vv);
          pp[uu] = p[uu];
          pp[vv] = p[vv];
        }
        if (t[j] == 2) {
          long long ans = sum[y[j]] - sum[x[j]];
          for (int pe : e)
            if (x[j] < c[pe] && c[pe] <= y[j]) {
              ans += merge(pp, find(p, u[pe]), find(p, v[pe]));
            }
          printf("%lld\n", ans);
        }
        else {
          int now = find(p, u[x[j]]);
          pp[now] = p[now];
          long long ans = calc(-p[now]);
          for (int pe : e)
            if (c[x[j]] == c[pe])
              merge(pp, find(p, u[pe]), find(p, v[pe]));
          now = find(pp, now);
          ans = calc(-pp[now]);
          printf("%lld\n", ans);
        }
      }
    }
  }
  return 0;
}