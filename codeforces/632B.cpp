#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

char s[N];
int p[N];


int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", p+i);
  scanf("%s", s);
  long long ans = 0, sa, sb;
  sa = sb = 0;
  for(int i = 0; i<n; i++) {
    if(s[i] == 'A')
      sa += p[i];
    else
      sb += p[i];
  }
  long long na, nb;
  na = nb = 0;
  ans = max(sb, sa);
  for(int i = 0; i<n; i++) {
    if(s[i] == 'A') {
      na += p[i];
      sa -= p[i];
    }
    else {
      nb += p[i];
      sb -= p[i];
    }
    ans = max(ans, max(nb + sa, na+sb));
  }
  cout << ans << endl;

  return 0;
}