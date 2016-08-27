#include <bits/stdc++.h>

using namespace std;

const int N = 1024, M = 1e5 + 5;

vector< pair<int, bitset< N > > > val[N];
vector< pair<int, int > > rev;
bitset< N > nul, ful;
int ans[M];

bool cmp(pair<int, bitset< N > > a, pair<int, bitset< N > > b) {
  return a.first < b.first;
}

bitset< N > getVal(int ver, int x) {
  auto it = --val[x].end();
  while (ver > it->first) {
    // if (rev[id].first > )
    //cerr << "ver " << ver << endl;
    it = lower_bound(val[x].begin(), ++it, make_pair(ver+1, nul), cmp);
    if (it == val[x].begin()) {
      return nul;
    }
    it--;
    int id = lower_bound(rev.begin(), rev.end(), make_pair(ver+1, -1))-rev.begin()-1;
    if (id < 0)
      break;
    ver = rev[id].second;
  }
  //cerr << it->first << " x " << val[x].size() <<endl;
  return it->second;
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  swap(n, m);
  nul.reset();
  ful.reset();
  for (int i = 0; i < n; i++)
    ful[i] = 1;
  for (int i = 0; i < m; i++) {
    val[i].push_back(make_pair(0, nul));
  }
  for (int t = 1; t <= q; t++) {
    int tc, x, y;
    scanf("%d %d", &tc, &x);
    x--;
    if (tc == 1) {
      scanf("%d", &y);
      y--;
      bitset< N > now = getVal(t, x);
      //cerr << now.count() << " ";
      ans[t] = ans[t-1] + !(now[y]);
      now[y] = 1;
      //cerr << now.count() << endl;
      val[x].push_back(make_pair(t, now));
    }
    else if (tc == 2) {
      scanf("%d", &y);
      y--;
      bitset< N > now = getVal(t, x);
      ans[t] = ans[t-1] - now[y];
      now[y] = 0;
      // //cerr << val[x].size() << " hah" << " " << now.count()<< endl;
      val[x].push_back(make_pair(t, now));      
    }
    else if (tc == 3) {
      bitset< N > now = getVal(t, x);
      int cnt = now.count();
      ans[t] = ans[t-1] + n - 2 * cnt;
      now = (~now) & ful;
      val[x].push_back(make_pair(t, now));
    }
    else {
      x++;  
      ans[t] = ans[x];
      rev.push_back(make_pair(t, x));
    }
    printf("%d\n", ans[t]);
  }

  return 0;
}