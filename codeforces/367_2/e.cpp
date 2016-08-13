#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

struct node {
  node * up, * down, *left, *right;
  int val;
  node(node * up = NULL, node * down = NULL, node * left = NULL, node * right = NULL) : up(up), down(down), left(left), right(right) {
  }
};

int a[N][N];
node * x[N][N];

node * get(int n, int m) {
  node * now = x[0][0];
  while (n--) {
    now = now->down;
  }
  while (m--) {
    now = now->right;
  }
  return now;
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i <= n+1; i++) {
    for (int j = 0; j <= m+1; j++) {
      x[i][j] = new node();
      if (i) {
        x[i][j]->up = x[i-1][j];
        x[i-1][j]->down = x[i][j];
      }
      if (j) {
        x[i][j]->left = x[i][j-1];
        x[i][j-1]->right = x[i][j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", a[i]+j);
      x[i][j]->val = a[i][j];
    }
  }
  while (q--) {
    int a, b, c, d, h, w;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &h, &w);
    node * nowl = get(a, b);
    node * nowr = nowl;
    node * curl = get(c, d);
    node * curr = curl;
    for (int i = 1; i < w; i++)  {
      nowr = nowr->right;
      curr = curr->right;
    }
    for (int i = 0; i < h; i++) {
      swap(nowl->left->right, curl->left->right);
      swap(nowl->left, curl->left);
      swap(nowr->right->left, curr->right->left);
      swap(nowr->right, curr->right);
      nowl = nowl->down;
      nowr = nowr->down;
      curl = curl->down;
      curr = curr->down;
    }
    nowl = get(a, b);
    nowr = nowl;
    curl = get(c, d);
    curr = curl;
    for (int i = 1; i < h; i++)  {
      nowr = nowr->down;
      curr = curr->down;
    }
    for (int i = 0; i < w; i++) {
      swap(nowl->up->down, curl->up->down);
      swap(nowl->up, curl->up);
      swap(nowr->down->up, curr->down->up);
      swap(nowr->down, curr->down);
      nowl = nowl->right;
      nowr = nowr->right;
      curl = curl->right;
      curr = curr->right;
    }
  }
  for (int i = 1; i <= n; i++) {
    node * now = x[i][0];
    for (int j = 1; j <= m; j++) {
      // cerr << i << ' ' << j << endl;
      now = now->right;
      printf("%d ", now->val);
    }
    printf("\n");
  }
  return 0;
}