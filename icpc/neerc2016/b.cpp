// by wiwit
#include <bits/stdc++.h>

using namespace std;
const string filename = "binary"; 

const int N = 2e6 + 5, M = N * 3;

struct trie {
  int l, r;
  trie(int l = 0, int r = 0) : l(l), r(r) {} 
} node[M];
int ct;

int get(int root, const string & s) {
  int now = root;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1')
      now = node[now].r;
    else
      now = node[now].l;
  }
  return now;
}

int add(int root, const string & s) {
  int now = root;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      if (!node[now].r) node[now].r = ++ct;
      now = node[now].r;
    }
    else {
      if (!node[now].l) node[now].l = ++ct;
      now = node[now].l;
    }
  }
  return now;
}


int n;
string s[N];
int pos[N];
vector<int> g[M];

void addToChild(int v, int r) {
  if (node[r].l)
    g[v].push_back(node[r].l);
  if (node[r].r)
    g[v].push_back(node[r].r);
}
vector<int> processedNode;
int inv(int v) {
  return v + (v >= n ? -n : +n);
}

void addBatch(int l, int r) {
  if (r-l < 2) return;
  int now = processedNode[0];
  for (int i = l+1; i < r; ++i) {
    int v = processedNode[i];
    g[now].push_back(inv(v));
    if (i == r-1) break;
    int nx = ++ct;
    g[now].push_back(nx);
    g[v].push_back(nx);
    now = nx;
  }
  now = processedNode[r-1];
  for (int i = r-2; i >= l; --i) {
    int v = processedNode[i];
    g[now].push_back(inv(v));
    if (i == l) break;
    int nx = ++ct;
    g[now].push_back(nx);
    g[v].push_back(nx);
    now = nx;
  }
}

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis, cc;
vector<vector<int> > elem;
int cntr, numCC;

void dfs(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : g[v]) {
    if(num[u] == -1)
      dfs(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    elem.push_back(vector<int>());
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      elem.back().push_back(u);
      cc[u] = numCC;
      if(u == v)
        break;
    }
    ++numCC;
  }
}

vector<vector<int> > dag;
bool isTrue[N];

void die() {
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout); 
#endif
  exit(0);
}

int main() {
#ifndef LOCAL
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
#endif
  cin >> n;
  ct = 2 * n;
  int root = 2 * n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    pos[i] = -1;
    for (int j = 0; j < s[i].size(); ++j)
      if (s[i][j] == '?') {
        pos[i] = j;
        break;
      }
    if (pos[i] == -1) {
      int r = add(root, s[i]);
      g[r].push_back(i);
      g[r].push_back(i+n);
    }
    else {
      s[i][pos[i]] = '0';
      int r = add(root, s[i]);
      g[r].push_back(i+n);
      
      s[i][pos[i]] = '1';
      r = add(root, s[i]);
      g[r].push_back(i);
    }
  }
  int cntTrie = ct - root + 1;
  for (int i = 0; i < n; ++i) {
    if (pos[i] == -1) {
      int r = get(root, s[i]);
      addToChild(i, r);
      addToChild(i+n, r);
      g[r+cntTrie].push_back(i);
      g[r+cntTrie].push_back(i+n);
      string now = s[i];
      now.pop_back();
      r = get(root, now);
      g[i].push_back(r+cntTrie);
      g[i+n].push_back(r+cntTrie);
    }
    else {
      s[i][pos[i]] = '0';
      int r = get(root, s[i]);
      addToChild(i, r);
      g[r+cntTrie].push_back(i+n);
      string now = s[i];
      now.pop_back();
      r = get(root, now);
      g[i].push_back(r+cntTrie);
      
      s[i][pos[i]] = '1';
      r = get(root, s[i]);
      addToChild(i+n, r);
      g[r+cntTrie].push_back(i);
      now = s[i];
      now.pop_back();
      r = get(root, now);
      g[i+n].push_back(r+cntTrie);
    }
  }
  ct += cntTrie;
  for (int i = root; i < root + cntTrie; ++i) {
    if (g[i].empty()) continue;
    processedNode.clear();
    processedNode = g[i];
    for (int & v : processedNode) {
      if (v >= n) v -= n;
      else v += n;
    }
    addBatch(0, processedNode.size());
  }
  for (int i = root; i < root + cntTrie; ++i) {
    addToChild(i, i);
    if (node[i].l)
      g[node[i].l + cntTrie].push_back(i + cntTrie);
    if (node[i].r)
      g[node[i].r + cntTrie].push_back(i + cntTrie);
  }
  num.assign(ct+1, -1);
  low.assign(ct+1, -1);
  vis.assign(ct+1, 0);
  cc.assign(ct+1, 0);
  cntr = numCC = 0;
  for (int i = 0; i <= ct; ++i) {
    if (num[i] != -1) continue;
    dfs(i);
  }
  for (int i = 0; i < n; ++i) {
    if (cc[i] == cc[i+n]) {
      cout << "NO\n";
      die();
    }
  }
  vector<int> din(numCC+1, 0);
  dag.resize(numCC);
  for (int i = 0; i <= ct; ++i) {
    for (int u : g[i]) {
      if (cc[u] != cc[i]) {
        dag[cc[i]].push_back(cc[u]);
        ++din[cc[u]];
      }
    }
  }
  vector<int> topo;
  stack<int> st;
  for (int i = 0; i < numCC; ++i) if (din[i]== 0) {
    st.push(i);
  }
  while (!st.empty()) {
    int v = st.top(); st.pop();
    topo.push_back(v);
    for (int u : dag[v]) {
      --din[u];
      if (din[u] == 0)
        st.push(u);
    }
  }
  vector<bool> ok(numCC, 0);
  for (int v : topo) {
    if (!ok[v]) {
      for (int e : elem[v])
        if (e < 2 * n) {
          if (e >= n) e -= n;
          else e += n;
          ok[cc[e]] = 1;
        }
    }
    for (int e : elem[v])
      if (e < 2 * n)
        isTrue[e] = ok[v];
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    assert(isTrue[i] != isTrue[i+n]);
    if (pos[i] != -1) {
      s[i][pos[i]] = isTrue[i] ? '0' : '1';
    }
    cout << s[i] << "\n";
  }
  die();
  return 0;
}