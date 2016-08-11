#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

struct node {
  node * l, * r;
  int cnt;
  node(int cnt = 0, node * l = NULL, node * r = NULL) : cnt(cnt), l(l), r(r) {
  }
  void process(int x) {
    node * now = this;
    this->cnt++;
    for(int mask = (1<<30); mask; mask >>= 1) {
      if(x & mask) {
        if(now->r == NULL)
          now->r = new node();
        now = now->r;
      }
      else {
        if(now->l == NULL)
          now->l = new node();
        now = now->l;
      }
      now->cnt++;
    }
  }

  int get(int x, int k) {
    node * now = this;
    int ret = 0;
    for(int mask = (1<<30); mask; mask >>=1) {
      if(k & mask) {
        if(mask & x) {
          now = now->l;
          if(!now)
            break;
        }
        else {
          now = now->r;
          if(!now)
            break;
        }
      }
      else {
        if(mask & x) {
          if(now->l) {
            ret += now->l->cnt;
          }
          now = now->r;
          if(!now)
            break;
        }
        else {
          if(now->r)
            ret += now->r->cnt;
          now = now->l;
          if(!now)
            break;
        }
      }
    }
    if(now)
      ret += now->cnt;
    return ret;
  }
};

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  node * trie = new node();
  trie->process(0);
  int now = 0;
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    int a;
    scanf("%d", &a);
    now ^= a;
    ans += trie->get(now, k);
    trie->process(now);
  }
  printf("%I64d\n", ans);
  return 0;
}