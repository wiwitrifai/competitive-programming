#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, G = sqrt(N);

int a[N], cnt[N], ans[N], cur = 0;
pair< pair<int, int >, int > vq[N];

bool cmp(pair< pair<int, int >, int > lhs, pair< pair<int, int >, int > rhs) {
  int gl = lhs.first.first/G, gr = rhs.first.first/G;
  if (gl != gr)
    return gl < gr;
  return lhs.first.second < rhs.first.second;
}
void upd(int id, int v) {
  if (cnt[id] == 2)
    cur--;
  cnt[id] += v;
  if (cnt[id] == 2)
    cur++;
}

int main() {
  // time_t startt = clock();
  int n, q;
  scanf("%d %d", &n, &q);
  vector< int > va;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    va.push_back(a[i]);
  }
  sort(va.begin(), va.end());
  va.erase(unique(va.begin(), va.end()), va.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(va.begin(), va.end(), a[i]) - va.begin();
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    vq[i] = make_pair(make_pair(l, r), i);
  }
  sort(vq, vq + q, cmp);
  int l = 0, r = 0;
  memset(cnt, 0, sizeof cnt);
  cur = 0;
  for (int i = 0; i < q; i++) {
    int nowl = vq[i].first.first, nowr = vq[i].first.second, id = vq[i].second;
    while (r < nowr) upd(a[r++], +1);
    while (r > nowr) upd(a[--r], -1);
    while (l < nowl) upd(a[l++], -1);
    while (l > nowl) upd(a[--l], +1);
    ans[id] = cur;
  }
  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);
  // cerr << (double)(clock() - startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  return 0;
}