#include <bits/stdc++.h>

using namespace std;

const int N = 25000 + 5;
int a[N], cnt[10];
bool used[N][10];
int ans = 0;

bool back(int id = 1) {
  if (id > ans) {
    printf("%d\n", ans = id);
  }
  memset(used[id], false, sizeof used[id]);
  for (int i = 1, k = id-1; i <= k; i++, k--)
    if (a[i] == a[k])
      used[id][a[i]] = true;
  int ok = -1;
  int all = 0;
  for (int i = 0; i < 10; i++)
    if (!used[id][i])
      all++;
  while(all) {
    int sel = rand() % all;
    for (int i = 0; i < 10; i++) if (!used[id][i]) {
      if (sel == 0) {
        ok = i;
        break;
      }
      sel--;
    }
    all--;
    a[id] = ok;
    cnt[ok]++;
    used[id][ok] = true;
    if (back(id+1))
      return true;
    cnt[ok]--;
  }
  return false;
}

int main() {
  srand(0);
  assert(back());
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    printf("%d", a[i]);
  printf("\n");
  return 0;
}