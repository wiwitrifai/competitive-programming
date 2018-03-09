#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

char s[N];
int pre[N];

void die() {
  puts("-1");
  exit(0);
}

int main() {
  set<int> nol, satu;
  scanf("%s", s);
  int n = strlen(s);
  memset(pre, -1, sizeof pre);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (!satu.empty()) {
        auto it = satu.begin();
        pre[i] = *it;
        satu.erase(it);
      }
      nol.insert(i);
    }
    else {
      if (nol.empty()) die();
      auto it = nol.begin();
      pre[i] = *it;
      nol.erase(it);
      satu.insert(i);
    }
  }
  if (!satu.empty()) die();
  printf("%d\n", nol.size());
  for (int x : nol) {
    vector<int> ans;
    int now = x;
    while (now >= 0) {
      ans.push_back(now);
      now = pre[now];
    }
    reverse(ans.begin(), ans.end());
    printf("%d", ans.size());
    for (int v : ans)
      printf(" %d", v+1);
    printf("\n");
  }
  return 0;
}