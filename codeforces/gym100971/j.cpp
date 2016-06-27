#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
vector< string > s;
vector<vector<pair<int, int> > > p;
vector<vector<int> > cnt;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  // cerr << n  << " " << m << endl;
  p.assign(n, vector<pair<int, int> >(m, make_pair(-1, -1)));
  cnt.assign(n, vector<int>(m, 0));
  // cerr << p.size() << " " << cnt.size() << endl;
  s.resize(n);
  for(int i = 0; i<n; i++) {
    // cerr << p[i].size() << " sx " << cnt[i].size() << endl; 
    cin >> s[i];
  }
  int x[2], y[2];
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<m; j++)
      if(s[i][j] == '1')
        x[0] = i, y[0] = j;
      else if(s[i][j] == '2')
        x[1] = i, y[1] = j;
  }
  // cerr << x[0] << " n " << y[0] << endl;
  queue< pair<int, int> > q;
  q.push(make_pair(x[0], y[0]));
  cnt[x[0]][y[0]] = 1;
  p[x[0]][y[0]] = make_pair(x[0], y[0]);
  bool finding = true, done = false;
  bool ok = false;
  while(!q.empty()) {
    pair<int, int> a = q.front();
    q.pop();
    int ccnt = 0;
    for(int i = 0; i<4; i++) {
      pair<int, int> b = make_pair(a.first + dx[i], a.second + dy[i]);
      if(b.first < n && b.first >=0 && b.second < m && b.second >= 0 && s[b.first][b.second ] != '#') {
        ccnt++;
        if(p[b.first][b.second].first == -1) {
          p[b.first][b.second] = a;
          if(b.first == x[1] && b.second == y[1])
            finding = false;
          else
            q.push(b);
        }
        if(p[a.first][a.second] != b) {
          cnt[b.first][b.second] += cnt[a.first][a.second];
        }
      }
    }
    if(ccnt > 2)
      ok = true;
    if(!done && q.empty() && !finding) {
      q.push(make_pair(x[1], y[1]));
      done = true;
    }
  }
  if(cnt[x[0]][y[0]]>1 || cnt[x[1]][y[1]] > 1)
    ok = true;
  puts(!finding && ok ? "YES" : "NO");
  return 0;
}