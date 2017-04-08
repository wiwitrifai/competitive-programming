// Wrong Answer
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

char s[N];
int need[N], add[N], id[N];
bool cmp(int a, int b) {
  if (need[a] == need[b])
    return add[a] > add[b];
  return need[a] < need[b];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    need[i] = 0;
    add[i] = 0;
    for (int j = 0; j < len; j++) {
      if (s[j] == '(')
        add[i]++;
      else
        add[i]--;
      need[i] = max(need[i], -add[i]);
    }
    id[i] = i;
  }
  sort(id, id+n, cmp);
  set< pair< int, int > > st;
  vector< int > ans;
  int i = 0;
  int cur = 0;
  while (i < n && need[id[i]] == cur) {
    st.insert(make_pair(-add[id[i]], id[i]));
    i++;
  }
  while (i < n) {
    while (i < n && need[id[i]] <= cur) {
      st.insert(make_pair(-add[id[i]], id[i]));
      i++;
    }
    if (st.empty()) break;
    auto it = st.begin();
    int now = it->second;
    cur -= it->first;
    st.erase(it);
    ans.push_back(now);
  }
  while (!st.empty()) {
    auto it = st.begin();
    cur -= it->first;
    int now = it->second;
    st.erase(it);
    ans.push_back(now);
  }
  if (cur != 0 || ans.size() != n) {
    puts("NO");
  }
  else {
    puts("YES");
    for (int i = 0; i < n; i++) {
      printf("%d%c", ans[i]+1, i == n-1 ? '\n' : ' ');
    }
  }
  return 0;
}