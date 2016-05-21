#include <bits/stdc++.h>

using namespace std;

int n;
string s[20];
int x[20];

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    cin >> s[i] >> x[i];
  int ans = 0;
  for(int a = 1; a<=100; a++) {
    int now = a;
    bool mess = false;
    for(int i = 0; i<n; i++) {
      if(s[i][0] == 'S') {
        now -= x[i];
        if(now < 0) {
          mess = true;
        }
      } else if(s[i][0] == 'M')
        now *= x[i];
      else if(s[i][0] == 'A')
        now += x[i];
      else {
        if(now % x[i])
          mess = true;
        now /= x[i];
      }
    }
    if(mess)
      ans++;
  }
  cout << ans << endl;
  return 0;
}