#include <bits/stdc++.h>

using namespace std;
int n, m;
string s;
const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  cin >> s;
  int mod = 0;
  int tot = 0;
  for(int i = 0;i < n; ++i){
    mod *= 10;
    mod += s[i] - '0';
    mod %= m;
    if(mod == 0){
      tot++;
    }
  }
  if(mod != 0){
    cout << 0 << endl;
    return 0; 
  }
  else{
    int now = 1;
    for(int i = 1;i < tot; ++i){
      now *= 2;
      now %= MOD;
    }
    cout << now << endl;
  }

  return 0;
}