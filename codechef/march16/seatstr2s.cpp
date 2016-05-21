#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

long long powmod(long long base, int pw) {
  if(pw < 0)
    return 0;
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}
long long fac[N], ifac[N];
int cnt[26];
char s[N];

int main() {
  fac[0] = 1;
  ifac[0] = 1;
  for(int i = 1; i< N; i++) {
    fac[i] = (fac[i-1] * i) % mod;
    ifac[i] = powmod(fac[i], mod-2);
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i<n; i++)
      cnt[s[i]-'a']++;
    long long permut = fac[n];
    for(int i = 0; i<26; i++) {
      permut *= ifac[cnt[i]];
      permut %= mod;
    }
    string str(s);
    set< string > st;
    map<string, int> haha;
    int pp = 0;
    for(int i = 0; i<n; i++)
      for(int j = i; j<n; j++) {
        swap(s[i],s[j]);
        for(int k = 0; k<n; k++)
          for(int l = k; l<n; l++) {
            swap(s[k],s[l]);
            st.insert(s);
            int cnt = 0;
            for(int ip = 0; ip<n; ip++)
              cnt += s[ip] != str[ip];
            pp += cnt == 4;
            if(cnt == 4)
              haha[s]++;
            swap(s[k], s[l]);
          }
        swap(s[i],s[j]);
      }
      int p[6];
      memset(p, 0, sizeof p);
      for(auto it = st.begin(); it!= st.end(); it++) {
        int cnt = 0;
        for(int i = 0; i<n; i++)
          cnt += s[i] != (*it)[i];
        p[cnt]++;
        // if(cnt == 4)
        //   cout << *it << endl;
      }
      for(auto it = haha.begin(); it != haha.end(); it++)
        cout<< it->first << " " << it->second << endl;
      cout << permut << " " << st.size() << " " << p[2] << " " << p[3] << " " << p[4] << " " << pp << endl;
    long long ans = permut * (permut - (int)st.size()) % mod;
    ans %= mod;
    if(ans < 0)
      ans += mod;
    printf("%lld\n", ans);
  }
  return 0;
}