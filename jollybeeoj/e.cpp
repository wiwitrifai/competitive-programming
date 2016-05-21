#include <bits/stdc++.h>

#define H first.first
#define num first.second
#define val second

using namespace std;

const int Q = 1e4 + 5;

pair<pair<int, int>, long long > node[Q];

int main() {
  int n, q, m = 0;
  scanf("%d%d", &n, &q);
  while(q--) {
    int que, h;
    scanf("%d%d", &que, &h);
    if(que == 1) {
      node[m].H = h;
      scanf("%d%lld", &node[m].num, &node[m].val);
      node[m].num--;
      long long add = 0;
      for(int i = 0; i<m; i++) {
        if(node[i].H <= h) {
          if((node[m].num >> (h-node[i].H)) == node[i].num)
            add += node[i].val;
        }
        if(node[i].H >= h) {
          if((node[i].num >> (node[i].H-h)) == node[m].num)
            node[i].val += node[m].val;
        }
      }
      node[m].val += add;
      m++;
    }
    else {
      long long ans = 0;
      for(int i = 0; i<m; i++) {
        if(node[i].H >= h && (node[i].num >> (node[i].H-h)) == 0)
          ans = max(ans, node[i].val);
      }
      printf("%lld\n", ans);
    }
  }
  

  return 0;
}