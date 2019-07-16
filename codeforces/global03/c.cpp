#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int p[N], pos[N];
vector<pair<int, int>> ans;
int n, n2;

void swap_pos(int a, int b) {
  assert(abs(a-b) >= n2);
  ans.emplace_back(a, b);
  swap(p[a], p[b]);
  swap(pos[p[a]], pos[p[b]]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", p+i), pos[p[i]] = i;;
  n2 = n/2;
  for (int i = 0; i < n2; ++i) {
    int left = n2-i, right = n2 + i + 1;
    if (pos[left] != left) {
      if (abs(pos[left] - left) >= n2) {
        swap_pos(left, pos[left]);
      }
      else {
        if (abs(pos[left] - n) < n2)
          swap_pos(pos[left], 1);
        swap_pos(pos[left], n);
        swap_pos(left, pos[left]);
      }
    }
    if (pos[right] != right) {
      if (abs(pos[right] - right) >= n2) {
        swap_pos(right, pos[right]);
      }
      else {
        if (abs(pos[right] - 1) < n2)
          swap_pos(pos[right], n);
        swap_pos(pos[right], 1);
        swap_pos(right, pos[right]);
      }
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto it : ans)
    printf("%d %d\n", it.first, it.second);
  return 0;
}
