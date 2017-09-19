#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int cnt[N], last[N], id[N], n, k, m, a, atas[N];

bool cek1(int i) {
  if (cnt[i] == 0) return false;
  int kalah = atas[i], sisa = m;
  for (int j = atas[i] + 2; j <= n; j++) {
    int need = cnt[i] + 1 - cnt[id[j]];
    if (need > sisa)
      break;
    kalah++;
    sisa -= need;
  }
  return kalah < k;
}

bool cek2(int i) {
  if (cnt[i] + m == 0) return false;
  if (atas[i] < k) return true;
  return (cnt[id[k]] < cnt[i] + m);
}

int main() {
  scanf("%d %d %d %d", &n, &k, &m, &a);
  for (int i = 0; i < a; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
    last[x] = i;
  }
  for (int i = 1; i <= n; i++)
    id[i] = i;
  sort(id+1, id+n+1, [](int le, int ri) {
    if (cnt[le] != cnt[ri])
      return cnt[le] > cnt[ri];
    return last[le] < last[ri];
  });
  int z = 0;
  for (int i = 1; i <= n; i++) {
    atas[id[i]] = z;
    z += cnt[id[i]] > 0;
  }
  m -= a;
  for (int i = 1; i <= n; i++) {
    if (i > 1)
      printf(" ");
    if (cek1(i))
      printf("1");
    else if (cek2(i))
      printf("2");
    else
      printf("3");
  }
  printf("\n");
  return 0;
}