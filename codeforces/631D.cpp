#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m, b[N];
pair<char, long long> s[N], t[N];

int main() {
  scanf("%d%d", &n, &m);
  int last = 0;
  for(int i = 0; i<n; i++) {
    int occ;
    char c;
    scanf("%d-%c", &occ, &c);
    if(i == 0)
      t[i] = {c, occ}, last = 0;
    else {
      if(t[last].first == c)
        t[last].second += occ;
      else
        t[++last] = {c, occ};
    }
  }
  n = last+1;
  for(int i = 0; i<m; i++) {
    int occ;
    char c;
    scanf("%d-%c", &occ, &c);
    if(i == 0)
      s[i] = {c, occ}, last = 0;
    else {
      if(s[last].first == c)
        s[last].second += occ;
      else {
        s[++last] = {c, occ};
      }
    }
  }
  m = last+1;
  if(m == 1) {
    long long ans = 0;
    for(int i = 0; i<n; i++) {
      if(s[0].first == t[i].first)
        ans += max(t[i].second+1-s[0].second, 0LL);
    }
    cout << ans << endl;
  }
  else if(m == 2) {
    int ans = 0;
    for(int i = 1; i<n; i++) {
      if(s[0].first == t[i-1].first && s[1].first == t[i].first && s[0].second <= t[i-1].second && s[1].second <= t[i].second)
        ans++;
    }
    cout << ans << endl;
  }
  else {
    int ans = 0;
    m--;
    int i, j;
    i = 1; j = 0; b[i] = j;
    while(i < m) {
      while(j > 0 && (s[i].first != s[j].first || s[i].second != s[j].second)) j = b[j];
      i++; j++;
      b[i] = j;
    }

    i = 1; j = 1;
    n--;
    while(i < n) {
      while(j > 0 && (t[i].first != s[j].first || t[i].second != s[j].second)) j = b[j];
      i++; j++;
      if(j == m) {
        if(t[i-m].first == s[0].first && t[i].first == s[m].first && t[i-m].second >= s[0].second && t[i].second >= s[m].second)
          ans++;
        j = b[j];
      }  
    }
    cout << ans << endl;
  }
  return 0;
}