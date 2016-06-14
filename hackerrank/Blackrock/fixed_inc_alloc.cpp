#include <bits/stdc++.h>

using namespace std;

int t;
long long m, inc, a;
pair< long long, string > p[1024];

int main() {
  scanf("%d", &t);
  cin >> m >> inc >> a;
  long long tot = 0;
  for(int i = 0; i<t; i++) {
    cin >> p[i].second >> p[i].first;
    tot += p[i].first;
  } 
  if(tot > a) {
    sort(p, p+t);
    for(int i = 0; i<t; i++) {
      long long alloc = 0;
      double prop = (double)p[i].first * a / tot; 
      if(prop < m) {
        if(prop * 2 > m && m <= a && (((p[i].first-2*m) % inc) == 0) && (p[i].first == m || p[i].first >= 2*m))
          alloc = m;
      }
      else {
        if(prop >= p[i].first)
          alloc = p[i].first;
        else {
          long long now = (long long)prop;
          if((p[i].first - 2*m) % inc)
            alloc = 0;
          else {
            alloc = m + ((now-m) / inc) * inc;
            while(alloc <= prop) alloc += inc;
            while(alloc > prop) alloc -= inc;
            while((p[i].first - alloc) < m) alloc -= inc;
            if(alloc < m)
              alloc = 0;
          }
        }
      }
      tot -= p[i].first;
      p[i].first = alloc;
      a -= alloc;
    }
  }
  sort(p, p+t, [](pair< long long, string > x, pair< long long, string > y) {
    return x.second < y.second;
  });
  for(int i = 0; i<t; i++)
    cout << p[i].second << " " << p[i].first << "\n";
  return 0;
}