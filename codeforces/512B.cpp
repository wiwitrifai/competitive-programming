#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef pair< int, int > ii;

int n, l[305], c[305];

int gcd(int a, int b) {
  return (a ? gcd(b % a, a) : b);
}

set< ii > s;

int main() {
#ifdef DEBUG
  time_t startt = clock();
#endif
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", l+i);
  for(int i = 0; i<n; i++)
    scanf("%d", c+i);
  s.insert(ii(0, 0));
  for(int i = 0; i<n; i++) {
    vector< ii > ins;
    auto itend = s.end();
    for(auto it = s.begin(); it != s.end(); it++) {
      ins.push_back(ii(gcd(it->X, l[i]), (it->Y) + c[i]));
    }
    for(int j = 0; j<ins.size(); j++) {
      auto it = s.lower_bound(ii(ins[j].X, -1));
      if(it != s.end()) {
        if(it->X == ins[j].X) {
          if(it->Y > ins[j].Y)
            s.erase(it);
          else
            continue;
        }
      }
      s.insert(ins[j]);
    }
  }
  auto it = s.lower_bound(ii(1, -1));
  if(it == s.end() || it->X != 1)
    puts("-1");
  else
    printf("%d\n", it->Y);
#ifdef DEBUG
  cerr << "Running time  : " << (double)(clock()-startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  int T = time(NULL)-1491365493;
  cerr << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
#endif
  return 0;
}
