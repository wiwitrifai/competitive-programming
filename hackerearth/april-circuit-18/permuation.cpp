#include <bits/stdc++.h>

using namespace std;

int n;
int a[10];

void dec(int * r, int v) {
  for (int i = 0; i < n; ++i) {
    r[i] = v & 7;
    v >>= 3;
  }
}
int enc(int * r) {
  int v = 0;
  for (int i = n-1; i >= 0; --i) {
    v <<= 3;
    v |= r[i];
  }
  return v;
}

set<int> st;

int main() {
  int ans = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), --a[i];
  int s = enc(a);
  for (int i = 0; i < n; ++i)
    a[i] = i;
  int t = enc(a);
  queue<pair<int, int> > q;
  if (t == s) {
    puts("0");
    return 0;
  }
  q.push(make_pair(s, 0));
  while (!q.empty()) {
    int v = q.front().first, now = q.front().second; q.pop();
    dec(a, v);
    for (int i = 0; i < n; ++i) {
      reverse(a, a+i+1);
      int w = enc(a);
      if (w == t) {
        printf("%d\n", now + 1);
        return 0;
      }
      if (!st.count(w))
        st.insert(w), q.push(make_pair(w, now+1));
      reverse(a, a+i+1);
    }
  }
  return 0;
}