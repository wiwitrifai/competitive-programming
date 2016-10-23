/**
  IEEExtreme Programming Contest 10
  Problem : Full Adder
  Solver  : Wiwit Rifa'i
  Status  : Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int b;
char c[70];
int to[256];
const int N = 1e7 + 6;
char tmp[N], ans[N];

int main() {
  scanf("%d", &b);
  scanf("%s%*c", c);
  for (int i = 0; i < b; i++)
    to[c[i]] = i;
  string s, t, tmp;
  getline(cin, s);
  getline(cin, t);
  getline(cin, tmp);
  printf("%d %s\n", b, c);
  int os = 0, ot = 0;
  while (os < s.size() && (s[os] == '+' || s[os] == ' ')) os++;
  while (ot < t.size() && (t[ot] == '+' || t[ot] == ' ')) ot++;
  cout << s << "\n";
  cout << t << "\n";
  cout << tmp << "\n";
  int i = (int)s.size()-1, j = (int)t.size()-1, k = N-1;
  ans[k--] = '\0';
  int cur = 0;
  while (i >= os || j >= ot) {
    if (i >= os) {
      cur += to[s[i]];
      i--;
    }
    if (j >= ot) {
      cur += to[t[j]];
      j--;
    }
    ans[k--] = c[cur % b];
    cur /= b;
  }
  while (cur) {
    ans[k--] = c[cur % b];
    cur /= b;
  }
  k++;
  int len = strlen(ans+k);
  for (int i = 0; i+len<t.size(); i++)
    printf(" ");
  printf("%s\n", ans+k);
  return 0;
}