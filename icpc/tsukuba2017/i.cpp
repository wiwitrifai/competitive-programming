#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

int bit[N];
int get(int x) {
  int r = 0;
  for (; x < N; x += x&-x)
    r += bit[x];
  return r;
}

void upd(int x, int d) {
  for (; x; x -= x&-x)
    bit[x] += d;
}

int add[N], n;
vector<int> que[N];
vector<int> ins[N];

int main() {
  scanf("%d", &n);
  vector<pair<int, int> > p;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    add[a]++;
    add[b]--;
    que[b].push_back(a);
    ins[a].push_back(b);
  }
  int now = 0, ans1 = 1;
  for (int i = 0; i < N; ++i) {
    now += add[i];
    ans1 = max(ans1, now);
  }
  int ans2 = 1;
  for (int i = 0; i < N; ++i) {
    for (int x : que[i]) {
      ans2 = max(ans2, get(x+1));
    }
    for (int x : ins[i])
      upd(x, +1);
  }
  printf("%d %d\n", ans2, ans1);
  return 0;
}