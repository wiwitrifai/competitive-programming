#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    set< int > st;
    while(n--) {
      int x;
      scanf("%d", &x);
      st.insert(x);
    }
    while(q--) {
      int x;
      scanf("%d", &x);
      puts(st.count(x) ? "YES" : "NO");
      st.insert(x);
    }
  }
  return 0;
}