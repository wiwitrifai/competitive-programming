#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

set< pair< int, int > > st;

int main() {
  int n = 1000  ;
  srand(time(0));
  int x = rand() % n;
  st.insert(make_pair(1, x));
  queue< pair< int, int > > que;
  que.push(make_pair(1, x));
  while (!que.empty()) {
    cerr << st.size() << endl;  
    pair< int, int > now = que.front();
    que.pop();
    int move = now.first, pos = now.second;
    if (pos + move >= n && pos - 2 * move -1 < 0) {
      continue;
    }
    if (pos - move < 0 && pos + 2 * move  + 1 >= n) {
      continue;
    }
    if (pos + move < n && !st.count(make_pair(move+1, pos+move))) {
      pair<int, int > nxt = make_pair(move+1, pos+move);
      st.insert(nxt);
      que.push(nxt);
    }
    if (pos - move >= 0 && !st.count(make_pair(move+1, pos-move))) {
      pair<int, int > nxt = make_pair(move+1, pos-move);
      st.insert(nxt);
      que.push(nxt);
    }
  }
  cout << st.size() << endl;
  return 0;
}