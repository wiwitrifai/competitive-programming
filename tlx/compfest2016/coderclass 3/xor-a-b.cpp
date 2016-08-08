#include <bits/stdc++.h>

using namespace std;

unsigned long long get(unsigned long long a) {
  unsigned long long r = a & 3ULL;
  if(r == 0)
    return a;
  else if(r == 1)
    return 1;
  else if(r == 2)
    return a+1;
  else
    return 0;
}
unsigned long long get2(unsigned long long a) {
  unsigned long long ret = 0;
  for(unsigned long long i = 1; i<= a; i++)
    ret ^= i;
  return ret;
}
 
int main() {
  // unsigned long long ret = 0;
  // for(unsigned long long i = 1; i<= 50; i++) {
  //   ret ^= i;
  //   cerr << i << " " << ret << endl;
  // }
  unsigned long long a, b;
  cin >> a >> b;
  unsigned long long ans = get(b) ^ get(a) ^ a, mask = 1;
  // cerr << get2(a) << "  " << get2(b) << endl;
  bool ok = false;
  mask <<= 63;
  for(int i = 63; i>=0; i--) {
    bool on = (ans & mask);
    if(on)
      ok = true;
    if(ok)
      printf("%d", on);
    mask >>= 1;
  }
  if(!ok)
    printf("0");
  printf("\n");
  return 0;
}