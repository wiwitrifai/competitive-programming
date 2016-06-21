#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 5;

int bit[M];
pair< pair<int, int>, pair<int, int> > que[M<<2];
string s[M];
int pos[M], ans[M];

int mp[256], n, m;
vector< int > cal;
void add(int v) {
  for(; v<=n; v += v & (-v))
    bit[v]++;
}
int get(int v) {
  int ret = 0;
  for(; v; v -= v & (-v))
    ret += bit[v];
  return ret;
}
struct node {
  int l, r;
  vector< int > point;
  node * to[4];
  node(int v) {
    l = r = v;
    for(int i= 0; i<4; i++)
      to[i] = NULL;
  }
  void insert(string str, int v) {
    node * it = this;
    for(int i= 0; i<str.size(); i++) {
      it->l = min(it->l, v);
      it->r = max(it->r, v);
      int nx = mp[str[i]];
      if(it->to[nx] == NULL)
        it->to[nx] = new node(v);
      it = it->to[nx];
    }
    it->point.push_back(v);
  }
  pair<int, int> get(string str) {
    node * it = this;
    for(int i = 0; i<str.size(); i++) {
      int nx = mp[str[i]];
      if(!it->to[nx])
        return make_pair(-1, -1);
      it = it->to[nx];
    }
    return make_pair(it->l, it->r);
  }
  void calibrate() {
    l = cal.size();
    for(int i = 0; i<point.size(); i++)
      cal.push_back(point[i]);
    for(int i = 0; i<4; i++) if(to[i])
      to[i]->calibrate();
    r = cal.size();
  }
};

int main() {
  scanf("%d%d", &n, &m);
  mp['A'] = 0;
  mp['C'] = 1;
  mp['G'] = 2;
  mp['U'] = 3;
  node * root, * toor;
  toor = new node(-1);
  root = new node(-1);
  for(int i = 0; i<n; i++) {
    cin >> s[i];
    root->insert(s[i], i);
  }
  root->calibrate();
  assert(cal.size() == n);
  for(int i = 0; i<n; i++) {
    pos[cal[i]] = i;
    // cerr  << i << " front " << cal[i] << endl; 
  }
  for(int i = 0; i<n; i++) {
    reverse(s[i].begin(), s[i].end());
    toor->insert(s[i], pos[i]);
  }
  cal.clear();
  toor->calibrate();
  // for(int i = 0; i<n; i++)
    // cerr << i << " back " << cal[i] << " " << pos[cal[i]] << endl;
  for(int i = 0; i<m; i++) {
    string pre, post;
    cin >> pre >> post;
    reverse(post.begin(), post.end());
    pair<int, int> res = root->get(pre), ser = toor->get(post);
    // cerr << res.first << " " << res.second << ' ' << ser.first << ' ' << ser.second << endl;
    que[i<<1] = make_pair(make_pair(ser.first, -(i+1)), res);
    que[(i<<1) + 1] = make_pair(make_pair(ser.second, i+1), res);
  }
  sort(que, que+2*m);
  int now = 0;
  memset(ans, 0, sizeof ans);
  memset(bit, 0, sizeof bit);
  for(int i = 0; i<n; i++) {
    while(now < m*2 && que[now].first.first <= i)
      now++;
    add(cal[i]+1);
    // cerr << "add " << cal[i] + 1 << endl;
    while(now < m*2 && que[now].first.first == i+1) {
      int res = 0; 
      if(que[now].second.second > 0)
        res += get(que[now].second.second);
      // cerr << now << " " << res << "=" << que[now].second.second;
      if(que[now].second.first > 0)
        res -= get(que[now].second.first);
      // cerr << res << "=" << que[now].second.first <<" : ";
      int idx = que[now].first.second;
      // cerr << idx << endl;
      if(idx < 0)
        ans[-idx-1] -= res;
      else
        ans[idx-1] += res;
      now++;
    }
  }
  for(int i = 0; i<m; i++)
    printf("%d\n", ans[i]);
  return 0;
}