#include <bits/stdc++.h>

using namespace std;

const int N = 2505;

struct quad_tree {
  vector<quad_tree * > child;
  int col;
  int l, r, u, d;
  quad_tree(int l, int r, int d, int u) : l(l), r(r), d(d), u(u) {
  }
  void change(int s, int l, int r, int d, int u) {
    if (l <= this->l && this->r <= r && d <= this->d && this->u <= u) {
      col = s;
      return;
    }
    if (l >= this->r && this->l >= r && d >= this->u && this->d >= u)
      return;
    for (quad_tree * ch : child) {
      if (col) {
        ch->col = col;
      }
      ch->add(s, l, r, d, u);
    }
    ch->col = 0;
  }
  void rem(int s, int l, int r, int d, int u) {
    if (l <= this->l && this->r <= r && d <= this->d && this->u <= u) {
      barrier.erase(s);
      return;
    }
    if (l >= this->r && this->l >= r && d >= this->u && this->d >= u)
      return;
    for (quad_tree * ch : child)
      ch->rem(s, l, r, d, u);
  }
  int get(int x, int y) {
    if (x < l || x >= r || y < d || y >= u) return 0; 
    int ret = col;
    if (col)
      return ret;
    for (quad_tree * ch : child) {
      ret = ch->get(x, y);
      if (ret)
        return ret;
    }
    return ret;
  }
};

quad_tree * build(int l, int r, int d, int u) {
  if (l >= r || d >= u) return 0;
  quad_tree * now = new quad_tree(l, r, d, u);
  int m1 = (l + r) / 2, m2 = (d + u) / 2;
  if (r-l < 2 && u-d < 2)
    return now;
  if (r-l < 2) {
    now->child.push_back(build(l, r, d, m2));
    now->child.push_back(build(l, r, m2, u));
    return now;
  }
  if (u-d < 2) {
    now->child.push_back(build(l, m1, d, u));
    now->child.push_back(build(m1, r, d, u));
    return now;
  }
  now->child.push_back(build(l, m1, d, m2));
  now->child.push_back(build(l, m1, m2, u));
  now->child.push_back(build(m1, r, d, m2));
  now->child.push_back(build(m1, r, m2, u));
  return now;
}


int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  quad_tree * root = build(0, n, 0, m);
  for (int i = 0; i < q; i++) {
    int a, b, c, d, t;
    scanf("%d %d %d %d %d", &t, &a, &b, &c, &d);
    a--; b--;
    if (t == 1) {
      root->add(a * m + b + 1, a, c, b, d);
    }
    else if (t == 2) {
      root->rem(a * m + b + 1, a, c, b, d);
    }
    else {
      c--; d--;
      int le = root->get(a, b), ri = root->get(c, d);
      puts(le == ri ? "Yes" : "No");
    }
  }
  return 0;
}