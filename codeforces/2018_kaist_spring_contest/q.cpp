#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

char s[N], p[N];
int rig[N];
int ans[N];

bitset<N> bs[N];
bitset<N> occ[26];

int main() {
  int q;
  scanf("%d", &q);
  scanf("%s", s);
  int len = 0;
  ans[0] = 0;
  for (int i = 0; i < q; ++i) {
    if (s[i] == '-') {
      --len;
      occ[p[len]-'a'][len] = 0;
    }
    else {
      p[len] = s[i];
      occ[p[len]-'a'][len] = 1;
      ++len;
      bs[len] = bs[len-1];
      bs[len][len-1] = 1;
      bs[len][len] = 1;
      bs[len] = (bs[len] >> 1) & occ[p[len-1]-'a'];
      ans[len] = ans[len-1] + bs[len].count();
    }
    printf("%d%c", ans[len], i == q-1 ? '\n' : ' ');
  }
  return 0;
}
