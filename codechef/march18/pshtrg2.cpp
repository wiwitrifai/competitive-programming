#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 50;

multiset<long long> seg[N << 2];
int a[N], n;

void build(int id = 1, int l = 0, int r = n) {
  for (int i = l; i < r; ++i)
    seg[id].insert(a[i]);
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}

long long calc(long long A, long long B, long long C) {
  long long sum = A + B + C;
  if (sum <= 2LL * max(A, max(B, C))) return 0;
  return sum;
}

void update(int x, int y, int id = 1, int l = 0, int r = n) {
  auto it = seg[id].find(a[x]);
  seg[id].erase(it);
  seg[id].insert(y);
  if (r-l < 2)
    return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    update(x, y, il, l, mid);
  else
    update(x, y, ir, mid, r);
}

priority_queue<int> pq;
void get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    auto it = seg[id].rbegin();
    for (int i = 0; i < M && it != seg[id].rend(); ++i, ++it) {
      if (pq.size() >= M && -pq.top() >= *it) break;
      pq.push(-*it);
      while (pq.size() > M) pq.pop();
    }
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  get(x, y, il, l, mid);
  get(x, y, ir, mid, r);
}

long long solve(int l, int r) {
  while (!pq.empty())
    pq.pop();
  long long A, B, C;
  get(l, r);
  if (pq.empty()) return 0;
  B = -pq.top(); pq.pop();
  if (pq.empty()) return 0;
  C = -pq.top(); pq.pop();
  long long ans = 0;
  while (!pq.empty()) {
    A = B, B = C, C = -pq.top();
    pq.pop();
    ans = max(ans, calc(A, B, C));
  }
  return ans;
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  build();
  while (q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y); --x;
    if (t == 1)
      update(x, y), a[x] = y;
    else
      printf("%lld\n", solve(x, y));
  }
  return 0;
}