#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int cur[N];
int n;

int ask() {
  for (int i = 0; i < n; ++i)
    printf("%d", cur[i]);
  printf("\n");
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == n)
    exit(0);
  return res;
}

int main() {
  srand(time(0));
  scanf("%d", &n);
  do {
    for (int i = 0; i < n; ++i)
      cur[i] = rand() & 1;
  } while (!ask());
  vector<int> sama, beda;
  sama.push_back(0);
  cur[0] ^= 1;
  for (int i = 1; i < n; ++i) {
    cur[i] ^= 1;
    if (ask())
      beda.push_back(i);
    else
      sama.push_back(i);
    cur[i] ^= 1;
  }
  cur[0] ^= 1;
  for (int x : sama)
    cur[x] ^= 1;
  ask();
  for (int i = 0; i < n; ++i)
    cur[i] ^= 1;
  ask();
  return 0;
}