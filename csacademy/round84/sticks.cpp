#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int main() {
  int n;
  scanf("%d", &n);
  priority_queue<int> pq;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    sum += x;
    pq.push(-x);
  }
  if (sum & 1) {
    puts("-1");
    return 0;
  }
  vector<pair<int, int> > ans;
  while (pq.size() > 1) {
    int a = -pq.top(); pq.pop();
    int b = -pq.top(); pq.pop();
    if (a != b) {
      assert(b > a);
      ans.emplace_back(b, a);
      pq.push(-(b-a));
    }
  }
  if (!pq.empty()) {
    ans.emplace_back(-pq.top(), -pq.top()/2);
  }
  printf("%d\n", (int)ans.size());
  for (auto it : ans)
    printf("%d %d\n", it.first, it.second);
  return 0;
}