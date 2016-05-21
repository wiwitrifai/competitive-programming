#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct node {
  int id;
  node * to[26];
  node(int _id) : id(_id) {
    memset(to, 0, sizeof to);
  }
};

int idx(char c) {
  if(c >= 'A' && c <= 'Z')
    return c - 'A';
  return c - 'a';
}

string ct;
vector< string > vs;
int ans[10005];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int n, m;
  cin >> n >> ct >> m;
  node * root = new node(-1);
  for(int i = 0; i<m; i++) {
    string s;
    cin >> s;
    vs.push_back(s);
    node * now = root;
    for(int j = (int)s.size()-1; j>=0; j--) {
      int d = idx(s[j]);
      if(now->to[d] == NULL) {
        now->to[d] = new node(j ? -1 : i);
      }
      now = now->to[d];
    }
  }
  memset(ans, -1, sizeof ans);
  ans[0] = m;
  for(int i = 0; i<n; i++) if(ans[i] != -1) {
    node * now = root;
    for(int j = i; j<n; j++) {
      int d = idx(ct[j]);
      if(now->to[d])
        now = now->to[d];
      else
        break;
      if(now->id>=0) {
        ans[j+1] = now->id;
        if(j+1 == n)
          break;
      }
    }
  }
  int d = n;
  stack<int> hore;
  while(d) {
    hore.push(ans[d]);
    d -= vs[ans[d]].size();
  }
  assert(!hore.empty());
  cout << vs[hore.top()];
  hore.pop();
  while(!hore.empty()) {
    cout << " " << vs[hore.top()];
    hore.pop();
  }
  cout << "\n";
  return 0;
}