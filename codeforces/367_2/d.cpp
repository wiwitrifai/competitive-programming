#include <bits/stdc++.h>

using namespace std;

struct node {
  node * l, * r;
  int cnt;
  node(int cnt = 0, node * l = NULL, node * r = NULL) : cnt(cnt), l(l), r(r) {
  }
  void add(int x, int v) {
    node * now = this;
    now->cnt += v;
    for(int mask = 1<<30; mask; mask >>= 1) {
      if(mask & x) {
        if(!now->r)
          now->r = new node();
        now = now->r;
      }
      else {
        if(!now->l)
          now->l = new node();
        now = now->l;
      }
      now->cnt += v;
    }
  }
  int get(int x) {
    node * now = this;
    int ret = 0;
    for(int mask = 1<<30; mask; mask >>= 1) {
      if(mask & x) {
        if(now->l && now->l->cnt) {
          ret |= mask;
          now = now->l;
        }
        else
          now = now->r;
      }
      else {
        if(now->r && now->r->cnt) {
          ret |= mask;
          now = now->r;
        }
        else
          now = now->l;
      }
    }
    return ret;
  }
};

int main() {
  node * root = new node();
  root->add(0, +1);
  int q;
  scanf("%d", &q);
  while(q--) {
    char s[5];
    int x;
    scanf("%s%d", s, &x);
    if(s[0] == '+')
      root->add(x, +1);
    else
      if(s[0] == '-')
        root->add(x, -1);
      else
        printf("%d\n", root->get(x));
  }

  return 0;
}