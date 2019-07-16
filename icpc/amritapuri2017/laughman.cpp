#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int l[N], j[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", j+i);
    int m = 0;
    for (int i = 0; i < n; ++i) {
      if (j[i] == 1)
        scanf("%d", l+m), ++m;
      else
        scanf("%*d");
    }
    if (m <= 1) {
      puts("#laughing_arjun");
      continue;
    }
    int le = 0, ri = m-1;
    while (le+1 < m && l[le+1] > l[le]) ++le;
    while (ri-1 >= 0 && l[ri-1] < l[ri]) --ri;
    if (ri <= le) {
      puts("#laughing_arjun");
      continue;
    }
    else if (ri-le == 1) {
      if (le == 0 || ri == m-1 || l[le-1] < l[ri] || l[le] < l[ri+1])
        puts("#laughing_arjun");
      else
        puts("#itsnot_arjun");
    }
    else if (ri-le == 2) {
      if (l[le] < l[ri])
        puts("#laughing_arjun");
      else
        puts("#itsnot_arjun");  
    }
    else
      puts("#itsnot_arjun");
  }
  return 0;
}