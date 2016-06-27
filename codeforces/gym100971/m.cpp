#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int ans[N];
int cnt[26], k, cnt2[26];
char s[N];
int main() {
  scanf("%d%s", &k, s);
  int n = strlen(s);
  int last = 0, now = 0, now2 = 0, last2 = 0;
  set< pair<int, int> > st;
  for(int i = 0; i<n; i++) {
    int x = s[i]-'a';
    if(cnt[x] == 0)
      now++;
    cnt[x]++;
    if(cnt2[x] == 0)
      now2++;
    cnt2[x]++;
    while(now > k) {
      if(last > 0)
        st.erase(make_pair(ans[last-1], last-1));
      x = s[last]-'a';
      cnt[x]--;
      if(cnt[x] == 0)
        now--;
      last++;
    }
    while(now2 >= k) {
      if(last2 > 0 && ans[last2-1] > -1)
        st.insert(make_pair(ans[last2-1], last2-1));
      x = s[last2]-'a';
      cnt2[x]--;
      if(cnt2[x] == 0)
        now2--;
      last2++;
    }
    // cerr << i << " " << last << ' ' << last2 << endl;
    if(now != k)
      ans[i] = -1;
    else {
      if(st.empty())
        ans[i] = -1;
      else
        ans[i] = st.begin()->first+1;
      if(last == 0)
        ans[i] = 1;
    }
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}