#include <bits/stdc++.h>

using namespace std;

int cnt, n;
char s[50], tmp[50];
long long base[11];
set< long long > st;

void solve(int lv, int id, long long val) {
  if(cnt && st.count(val) == 0) {
    printf("%s", s);
    for(int i = 2; i<=10; i++)
      printf(" %lld", base[i]);
    printf("\n");
    st.insert(val);
    cnt--;
  }
  if(cnt == 0)
    return;
  for(int i = id; i<=n-i*2; i++) {
    for(int j = 0; j<lv; j++) {
      s[i+j] = tmp[j];
      if(tmp[j] == '1')
        val |= (1LL<< (i+j));
    }
    solve(lv, i+lv, val);
    for(int j = 0; j<lv; j++) {
      s[i+j] = '0';
      val &= ~(1LL<<(i+j));
    }
    if(cnt == 0)
      return;
  }
}
void gen(int id) {
  if(id+id > n)
    return;
  tmp[id-1] = '0';
  gen(id+1);
  tmp[id-1] = '1';
  for(int i  = 0; i<=10; ++i) base[i] = 0;
  for(int i = 0; i<id; i++) {
    for(int j = 2; j<=10; j++) {
      base[j] *= j;
      base[j] += tmp[i] - '0';
    }
  }
  long long val = 0;
  for(int i = 0; i<id; i++) {
    s[i] = tmp[i];
    if(tmp[i] == '1')
      val |= 1LL << i;
  }
  for(int i = 0; i<id; i++) {
    s[n-id+i] = tmp[i];
    if(tmp[i] == '1')
      val |= 1LL << (n-id+i);
  }
  solve(id, id, val);
  gen(id+1);
  tmp[id-1] = '0';
  s[id-1] = '0';
  s[n-id] = '0';
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    st.clear();
    printf("Case #%d:\n", tc);
    scanf("%d%d", &n, &cnt);
    s[n] = '\0';
    for(int i = 1; i<n; i++)
      s[i] = '0';
    tmp[0] = '1';
    gen(2);
  }
  return 0;
}