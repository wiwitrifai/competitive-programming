#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e17;
const int N = 2e5 + 5;

typedef struct item * pitem;
struct item
{
  long long  prior, key, value, lazy;
  pitem l, r;
  item() {}
  item(long long key, long long prior, long long value) : key(key), prior(prior), value(value), lazy(0), l(NULL), r(NULL) {}
};
string s[N];
char from[N];
int to[N][26];
vector< long long > off[N];
long long sz[N];
char ans[N];
pitem state[N];

void add(pitem &t, long long v) {
  if (t) {
    t->key += v;
    t->lazy += v;
  }
}

void push(pitem &t) {
  if (t && t->lazy) {
    add (t->l, t->lazy);
    add (t->r, t->lazy);
    t->lazy = 0;
  }
}

void split(pitem t, long long key, pitem & l, pitem & r) {
  if (!t) {
    l = r = NULL;
    return;
  }
  push(t);
  if (t->key < key)
    split(t->r, key, t->r, r), l = t;
  else
    split(t->l, key, l, t->l), r = t;
}
void merge(pitem &t, pitem l, pitem r) {
  push(l);
  push(r);
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;  
}
void insert(pitem & t, pitem  it) {
  if (!t) {
    t = it;
    return;
  }
  push(t);
  if (it->prior > t->prior)
    split(t, it->key, it->l, it->r), t = it;
  else
    insert(t->key > it->key ? it->l : it->r, it);
}
void erase(pitem &t, int key) {
  if (!t)
    return;
  push(t);
  if (t->key == key)
    merge(t, t->l, t->r);
  else
    erase(key < t->key ? t->l : t->r, key);
}

pitem unite(pitem l, pitem r) {
  push(l); push(r);
  if (!l || !r)
    return l ? l : r;
  if (l->prior < r->prior)
    swap(l, r);
  pitem t1, t2;
  split(r, l->key, t1, t2);
  l->l = unite(l->l, t1);
  l->r = unite(l->r, t2); 
  return l;
}
long long getleft(pitem t) {
  push(t);
  if (t->l)
    return getleft(t->l);
  else
    return t->key;
}

void answer(pitem t, char c) {
  if (!t)
    return;
  ans[t->value] = c;
  answer(t->l, c);
  answer(t->r, c);
}

void debug(pitem t) {
  if (!t)
    return;
  push(t);
  debug(t->l);
  cerr << "(" <<t->key << "," << t->value <<") ";
  debug(t->r); 
}


int main() {
  srand(time(0));
  int n, p, q;
  cin >> n >> p >> q;
  cin >> s[0];
  from[0] = s[0][0];
  for (int i = 1; i <= p; i++) {
    string c;
    cin >> c >> s[i];
    from[i] = c[0];
  }
  int go[26];
  memset(go, -1, sizeof go);
  for (int i = p; i >= 0; i--) {
    off[i].resize(s[i].size());
    long long now = 0;
    for (int j = 0; j < s[i].size(); j++) {
      off[i][j] = now;
      int g = go[s[i][j]-'a'];
      now += g < 0 ? 1 : sz[g];
      if (now > inf)
        now = inf;
    }
    sz[i] = now;
    for (int j = 0; j< 26; j++)
      to[i][j] = go[j];
    go[from[i]-'a'] = i;
  }
  for (int i = 0; i < q; i++) {
    long long a;
    cin >> a;
    if (sz[0] < a) {
      ans[i] = 0;
      continue;
    }
    a--;
    state[0] = unite(state[0], new item(a, rand(), i));
  }
  for (int i = 0; i <= p; i++) {
    while (1) {
      if (!state[i])
        break;
      long long key = getleft(state[i]);
      int j = upper_bound(off[i].begin(), off[i].end(), key) - off[i].begin() - 1;
      pitem cur;
      if (j+1 < s[i].size())
        split(state[i], off[i][j+1], cur, state[i]);
      else {
        cur = state[i];
        state[i] = NULL;
      }
      int c = to[i][s[i][j]-'a'];
      if (c < 0) {
        answer(cur, s[i][j]);
      }
      else {
        add(cur, -off[i][j]);
        state[c] = unite(state[c], cur);
      }
    }
  }
  for (int i = 0; i < q; i++) {
    if (ans[i] <= 'z' && ans[i] >= 'a')
      printf("%c\n", ans[i]);
    else
      puts("none");
  }
  return 0;
}