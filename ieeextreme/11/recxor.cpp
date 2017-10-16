#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pll;
#define fi first
#define se second
#define mp make_pair

LL XOR(LL a, LL b){
  LL ans = 0;
  if(b - a <= 8){
    for(LL i = a; i <= b; ++i) ans ^= i;
  }
  else{
    for(LL i = a; (i & 3) > 0; ++i){
      ans ^= i;
    }
    for(LL i = b - (b & 3); i <= b; ++i) ans ^= i;
  } 
  return ans;
}
pll conv_to_pair(LL idx, int l){
  return mp(1LL * idx / l, 1LL * idx % l);
}
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int l, h, n;
    LL d1, d2;
    scanf("%d%d%d%lld%lld", &l, &h, &n, &d1, &d2);
    LL awal = n, akhir = n + 1LL * l * h - 1; 
    LL xorbesar = XOR(awal, akhir);
    pll satu = conv_to_pair(d1 - n, l);
    pll dua = conv_to_pair(d2 - n, l);
    pll kiri = mp(min(satu.fi, dua.fi), min(satu.se, dua.se));
    pll kanan = mp(max(satu.fi, dua.fi), max(satu.se, dua.se));
    LL le = kiri.fi * l + kiri.se + n;
    LL ri = le + kanan.se - kiri.se;
    for(LL i = kiri.fi; i <= kanan.fi; ++i){
      xorbesar ^= XOR(le, ri);
      le += l;
      ri += l;
    } 
    printf("%lld\n", xorbesar);
  }
  return 0;
}