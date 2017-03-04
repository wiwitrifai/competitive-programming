#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;

int a[N], b[N];
int val[N];
bool used[N];
int dfs(int u, int lv = 0) {
  int ret = 0;
  if (u > 0) {
    ret = dfs(a[u], lv+1);
    ret = max(ret, dfs(b[u], lv+1));
  }
  else
    val[lv] = max(val[lv], -u), ret = lv;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  memset(used, 0, sizeof used);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", a+i, b+i);
    if (a[i] > 0)
      used[a[i]] = 1;
    if (b[i] > 0)
      used[b[i]] = 1;
  }
  int root = 1;
  while (used[root]) root++;
  memset(val, 0, sizeof val);
  int lv = dfs(root);
  int ans = 0;
  for (int i = 0; i <= lv; i++) {
    int now = val[i];
    int cnt = lv-i;
    while (cnt-- > 0 && now > 1) {
      now = (now + 1)/2;
    }
    ans = max(ans, now);
  }
  if (ans == 0) {
    puts("0");
    return 0;
  }
  stack< int > st;
  while (ans > 0) {
    st.push(ans & 1);
    ans >>= 1;
  }
  while (!st.empty()) {
    printf("%d", st.top());
    st.pop();
  }
  for (int i = 0; i < lv; i++)
    printf("0");
  printf("\n");
  return 0;
}