/**
  IEEExtreme Programming Contest 10
  Problem : Memory Management
  Solver  : Wiwit Rifa'i
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int p, s, n;
    scanf("%d %d %d", &p, &s, &n);
    set <pair<int, int > > st;
    map < int, int > mp;
    set < int > inque;
    queue< int > q;
    int nq, ns;
    nq = ns = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      x /= s;
      if (!inque.count(x)) {
        q.push(x);
        inque.insert(x);
        if (q.size() > p) {
          nq++;
          inque.erase(q.front());
          q.pop();
        }
      }
      if (mp.count(x)) {
        st.erase({mp[x], x});
        st.insert({i, x});
      } 
      else {
        st.insert({i, x});
        if (st.size() > p) {
          auto it = st.begin();
          mp.erase(it->second);
          st.erase(it);
          ns++;
        }
      }
      mp[x] = i;
    }
    printf("%s %d %d\n", nq > ns ? "yes" : "no", nq, ns);
  }

  return 0;
}