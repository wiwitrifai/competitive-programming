#include <bits/stdc++.h>
using namespace std;

const int N = 135130.73;
int n, q;
long long a[N];
int l[N], r[N];
pair<int, int> que[N];
long long ans[N];

int main() {
  scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++) 
    scanf("%lld", a+i);
  stack<long long> dq;
  for(int i = 0; i<n; i++) {
    while(!dq.empty()) {
      int id = dq.top();
      if(a[i] > a[id])
        dq.pop();
      else
        break;
    }
    l[i] = dq.empty() ? -1 : dq.top();
    dq.push(i);
  }
  while(!dq.empty()) dq.pop();
  for(int i = n-1; i>=0; i--) {
    while(!dq.empty()) {
      int id = dq.top();
      if(a[i] >= a[id])
        dq.pop();
      else
        break;
    }
    r[i] = dq.empty() ? n : dq.top();
    dq.push(i);
  }

  for(int i = 0; i<q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    que[i] = make_pair(x, y);
  }
  int G = sqrt(n)+1;
  int ix[q];
  for(int i = 0; i<q; i++)
    ix[i] = i;
  sort(ix, ix+q, [](int a, int b) {
    return (que[a].first/G == que[b].first/G) ? que[a].second < que[b].second : que[a].first/G < que[b].first/G);
  });
  int last = -1, z = 0;
  deque< pair<int,int> > inc, dec;
  long long sum = 0, add = 0;
  for(int iq = 0; iq<q; ++iq) {
    int x = que[ix[iq]].first, y = que[ix[iq]].second;
    int now = x/G;
    if(now != last) {
      inc.clear();
      dec.clear();
      sum = 0;
      add = 0;
      z = (now+1) * G;
    }
    if(now == y/G) {
      long long &tmp = ans[ix[iq]];
      tmp = 0;
      for(int i = x; i<=y; i++) {
        tmp += a[i] * (i - max(l[i], x-1)) * (min(r[i], y+1) - i);
      }
    }
    else {
      for(; z <= y; z++) {
        while(!inc.)
      }
    }
  }
  return 0;
}
