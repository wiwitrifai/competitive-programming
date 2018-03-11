// by wiwit
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], s[N];

long long st[N], en[N];
vector<int> ev[N];

int m, k;
int x = 0;
multiset<long long> ending;
void update(int i, int pos) {
  en[i] = (1LL * (s[i] + 1) * x - 1LL * a[i] * k + a[i] - 1) / a[i];
  st[i] = (1LL * (s[i] ) * x - 1LL * a[i] * k) / a[i] + 1;
  ending.insert(en[i]);
  if (st[i] < pos) st[i] = pos;
  if (st[i] < N)
    ev[st[i]].push_back(i);
}

int main() {
  scanf("%d %d", &m, &k);
  for (int i = 0; i < m; ++i) {
    scanf("%d", a+i);
    x += a[i];
  }
  for (int i = 0; i < k; ++i) {
    int z;
    scanf("%d", &z);
    --z;
    ++s[z];
  }
  for (int i = 0; i < m; ++i) {
    update(i, 1);
  }
  priority_queue<pair<long long, int> > pq;
  int ans = 0;
  long long done = (x - k) % x;
  while (done < x) done += x;
  for (int i = 1; i <= done; ++i) {
    for (int id : ev[i]) {
      pq.push(make_pair(-en[id], id));
    }
    if (pq.empty()) break;
    auto it = pq.top();
    long long mati = -it.first;
    int id = it.second;
    pq.pop();
    if (mati < i) {
      break;
    }
    auto it2 = ending.find(en[id]);
    ending.erase(it2);
    if (!ending.empty()) {
      if (*ending.begin() <= i) break;
    }
    ++ans;
    ++s[id];
    update(id, i+1);
  }
  if (ans >= done)
    puts("forever");
  else
    printf("%d\n", ans);
  return 0;
}