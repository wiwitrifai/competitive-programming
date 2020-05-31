#include <bits/stdc++.h>

using namespace std;

int ask(vector<int> & indices) {
  printf("? %d\n", (int)indices.size());
  for (int i = 0; i < (int)indices.size(); ++i) {
    printf("%d%c", indices[i], i+1 == (int)indices.size() ? '\n' : ' ');
  }
  fflush(stdout);
  int x;
  scanf("%d", &x);
  if (x == -1) {
    exit(0);
  }
  return x;
}

int ask(int l, int r) {
  vector<int> id(r-l+1);
  iota(id.begin(), id.end(), l);
  int res = ask(id);
  return res;
}

char buffer[1000];

void answer(vector<int> & ans) {
  printf("!");
  for (int x : ans)
    printf(" %d", x);
  printf("\n");
  fflush(stdout);
  scanf("%s", buffer);
  if (buffer[0] == 'I')
    exit(0);
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<vector<int>> s(k);
    for (int i = 0; i < k; ++i) {
      int c;
      scanf("%d", &c);
      s[i].resize(c);
      for (int j = 0; j < c; ++j)
        scanf("%d", &s[i][j]);
    }
    int lo = 1, hi = n;
    int biggest = ask(lo, hi);
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      int res = ask(lo, mid);
      if (res == biggest)
        hi = mid;
      else
        lo = mid + 1;
    }
    vector<int> ans(k);
    int pos = -1;
    for (int i = 0; i < k; ++i) {
      bool found = false;
      for (int x : s[i]) {
        if (x == lo)
          found = true;
      }
      if (found)
        pos = i;
      else
        ans[i] = biggest;
    }
    if (pos != -1) {
      set<int> st;
      for (int x : s[pos])
        st.insert(x);
      vector<int> id;
      for (int i = 1; i <= n; ++i) {
        if (st.count(i)) continue;
        id.push_back(i);
      }
      ans[pos] = ask(id);
    }
    answer(ans);
  }
  return 0;
}
