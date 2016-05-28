#include <bits/stdc++.h>

using namespace std;

const int N = 8;
set< int > st[N];

int main() {
  int d, b;
  scanf("%d%d", &b, &d);
  for(int i = 1; i<b; i++)
    st[1].insert(i);
  for(int i = 2; i<d; i++) {
    for(auto it = st[i-1].begin(); it != st[i-1].end(); it++) 
      for(int k = 0; k<b; k++) {
        int now = *it * b + k;
        if(now % i == 0)
          st[i].insert(now);
      }
    cerr << i << " " << st[i].size() << endl;
  }

  return 0;
}