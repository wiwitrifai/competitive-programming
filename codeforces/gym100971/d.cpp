#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

pair<int, int> a[N];
int n, id[N], p[N];
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x, pop;
    scanf("%d%d", &x, &pop);
    a[i] = make_pair(x, pop);
    id[i] = i;
  }
  sort(id, id+n, [](int x, int y) {
    return a[x] < a[y];
  });
  stack< int > st;
  for(int i = 0; i<n; i++) {
    int now = id[i];
    while(!st.empty() && a[st.top()].second < a[now].second)
      st.pop();
    p[now] = st.empty() ? -1 : st.top();
    st.push(now);
  }
  while(!st.empty()) st.pop();
  for(int i = n-1; i>=0; i--) {
    int now = id[i];
    while(!st.empty() && a[st.top()].second < a[now].second)
      st.pop();
    if(!st.empty()) {
      if(p[now] == -1)
        p[now] = st.top();
      else {
        int d1 = a[st.top()].first -a[now].first, d2 = a[now].first - a[p[now]].first;
        if(d1 < d2 || (d1 == d2 && a[st.top()].second > a[p[now]].second))
          p[now] = st.top();
      }
    }
    st.push(now);
  }
  for(int i = 0; i<n; i++)
    printf("%d ", (p[i] > -1) + p[i]);
  printf("\n");
  return 0;
}