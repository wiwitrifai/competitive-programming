#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}

void answer(vector<int> ans) {
  printf("! %d", (int)ans.size());
  sort(ans.begin(), ans.end());
  for (int x : ans)
    printf(" %d", x);
  printf("\n");
  fflush(stdout);
  exit(0);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> single(n+1, 1);
  int last = ask(1, n);
  int all = last;
  for (int i = n-1; i >= 1; --i) {
    int cur = ask(1, i);
    if (cur >= last) {
      single[i+1] = 0;
    }
    last = cur;
  }
  last = all;
  for (int i = 2; i <= n; ++i) {
    int cur = ask(i, n);
    if (cur >= last) {
      single[i-1] = 0;
    }
    last = cur;
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i)
    if (single[i])
      ans.push_back(i);
  answer(ans);
  return 0;
}
