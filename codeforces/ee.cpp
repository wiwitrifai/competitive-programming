#include <bits/stdc++.h>

using namespace std;

struct node {
  node * a, * b;
  int id;
  node(int _id) : id(_id) {
    a = b = NULL;
  }
};

int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    int n, q;
    scanf("%d%d", &n, &q);
    node * root = new node(0);
    for(int i = 1; i<=n; i++) {
      int v;
      scanf("%d", &v);
      node * now = root;
      for(int u = 1<<30; u; u >>= 1) {
        if(u & v) {
          if(now->b == NULL)
            now->b = new node(i);
          now = now->b;
        }
        else {
          if(now->a == NULL)
            now->a = new node(i);
          now = now->a;
        }
      }
    }
    while(q--) {
      int x;
      scanf("%d", &x);
      node * now = root;
      for(int u = 1<<30; u; u>>=1) {
        if(u & x) {
          if(now->a)
            now = now->a;
          else
            now = now->b;
        }
        else {
          if(now->b)
            now = now->b;
          else
            now = now->a;
        }
      }
      printf("%d\n", now->id);
    }
    printf("\n");
  } 
  return 0;
}