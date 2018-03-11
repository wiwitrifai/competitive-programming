// by wiwit
#include <bits/stdc++.h>

using namespace std;

int n, k;
const long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int p1 = 7, p2 = 23;
map< pair< int, int >, int > mp;
long long powmod(long long base, long long pw, long long mod) {
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}
struct node {
  long long val;
  node * l, * r;
  node(long long val) : val(val) {
    l = r = NULL;
  }
  void insert(int x) {
    if(x < val) {
      if(l == NULL)
        l = new node(x);
      else
        l->insert(x);
    }
    else {
      if(r == NULL)
        r = new node(x);
      else
        r->insert(x);
    }
  }
  bool cmp(node* nod) {
    if(nod == NULL)
      return false;
    if(l != NULL && r != NULL)
      return (l->cmp(nod->l) && r->cmp(nod->r));
    else if(l != NULL)
      return (nod->r == NULL && l->cmp(nod->l));
    else if(r != NULL)
      return (nod->l == NULL && r->cmp(nod->r));
    else
      return (nod->l == NULL) && (nod->r == NULL);
  }
};

int main() {
  scanf("%d%d", &n, &k);
  node * root[55];
  for(int j = 0; j<n; j++) {
    int x;
    scanf("%d", &x);
    root[j] = new node(x);
    for(int i = 1; i<k; i++) {
      scanf("%d", &x);
      root[j]->insert(x);
    }
  }
  int ans = n;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<i; j++)
      if(root[i]->cmp(root[j])) {
        ans--;
        break;
      }
  }
  printf("%d\n", ans);
  return 0;
}