#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6, G = sqrt(1e5 + 6), Q = 3e5 + 6, inf = 1e9+7;

int a[N], n;
pair< pair<int, int >, int > que[Q];
int ans[N], cnt[N];
vector< int > val;
set< int > st;

bool cmp(pair< pair<int, int >, int > lhs, pair< pair<int, int >, int > rhs) {
  int gl = lhs.first.first/G, gr = rhs.first.first/G;
  if (gl != gr)
    return gl < gr;
  gl = lhs.first.second, gr = rhs.first.second;
  if (gl != gr)
    return gl < gr;
}

int cur;
void reset() {
  for (int v : st)
    cnt[v] = 0;
  cur = inf;
  st.clear();
}
void add(int v) {
  if (cnt[v] == 0) {
    auto it = st.lower_bound(v);
    if (it != st.end()) {
      cur = min(cur, abs(val[*it] - val[v]));
    }
    if (it != st.begin()) {
      it--;
      cur = min(cur, abs(val[v] - val[*it]));
    }
    st.insert(v);
  }
  else
    cur = 0;
  cnt[v]++;
}
void rem(int v) {
  cnt[v]--;
  if (cnt[v] == 0) {
    st.erase(v);
  }
}

int main() {
  time_t startt = clock();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    val.push_back(a[i]);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    que[i] = {{l, r}, i};
  }
  sort(que, que+q,cmp);
  int ng = -1, rr = 0;
  reset();
  for (int i = 0; i < q; i++) {
    int l = que[i].first.first, r = que[i].first.second, id = que[i].second;
    int gl = l/G;
    if (gl != ng) {
      ng = gl;
      rr = (ng + 1) * G;
      reset();
    }
    while (rr < r) {
      add(a[rr++]);
    }
    int tmp = cur, mi = min(r, (ng + 1) * G);
    for (int j = l; j < mi; j++)
      add(a[j]);
    ans[id] = cur;
    for (int j = l; j < mi; j++)
      rem(a[j]);
    cur = tmp;
    // cerr << "query #" << i << " time :" << (double)(clock() - startt) * 1000.0/CLOCKS_PER_SEC << " ms" << endl;
  }
  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);
    // cerr << "done!  time :" << (double)(clock() - startt) * 1000.0/CLOCKS_PER_SEC << " ms" << endl;
  return 0;
}