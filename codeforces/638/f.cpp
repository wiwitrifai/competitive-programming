#include <bits/stdc++.h>

using namespace std;

void print_ans(const vector<int> & p) {
  vector<int> ans(p.size());
  for (int i = 0; i < (int)p.size(); ++i)
    ans[p[i]] = i;
  for (int i = 0; i < (int)ans.size(); ++i)
    printf("%d%c", ans[i]+1, i+1 == (int)ans.size() ? '\n' : ' ');
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  vector<pair<int, int>> events;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i], &b[i]);
    --a[i], --b[i];
    events.emplace_back(a[i], i);
  }
  sort(events.begin(), events.end());
  vector<int> p;
  priority_queue<pair<int, int>> pq;
  for (int i = 0, e = 0; i < n; ++i) {
    while (e < (int)events.size() && events[e].first <= i) {
      int v = events[e].second;
      pq.emplace(-b[v], v);
      ++e;
    }
    int v = pq.top().second;
    pq.pop();
    p.emplace_back(v);
  }
  int lef = -1, rig = -1;
  stack<int> vrig;
  for (int i = n-1; i >= 0; --i) {
    int v = p[i];
    while (!vrig.empty() && a[p[vrig.top()]] > i) vrig.pop();
    if (!vrig.empty() && vrig.top() <= b[v]) {
      lef = i, rig = vrig.top();
      break;
    }
    while (!vrig.empty() && a[p[vrig.top()]] >= a[v]) vrig.pop();
    vrig.push(i);
  }
  if (lef == -1) {
    puts("YES");
  }
  else {
    puts("NO");
    print_ans(p);
    swap(p[lef], p[rig]);
  }
  print_ans(p);
  return 0;
}
