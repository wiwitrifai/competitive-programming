// WA on test 14 by luqman
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int ev[N], od[N];
int n;
vector<int> el[N];

int even(int x) {
  return 2 * x;
}

int odd(int x) {
  return 2 * x + 1;
}

void answer() {
  printf("!");
  for (int i = 1; i <= n / 2; i++) printf(" %d", ev[i]);
  for (int i = 1; i <= n / 2 + n % 2; i++) printf(" %d", od[i]);
  printf("\n");
  fflush(stdout);
  exit(0);
}

int main() {
  scanf("%d", &n);
  if (n == 1) {
    od[1] = 1;
    answer();
  }
  for (int i = 1; i <= n / 2 + n % 2; i++) {
    el[0].push_back(i);
  }
  set<pair<int, int>> s;
  s.insert(make_pair(0, 0));

  int pt = 1;
  for (int i = 1; i <= n / 2; i++) {
    int l = 1, r = n / 2;
    while (l < r) {
      int mid = (l + r) >> 1;
      auto p = s.lower_bound(make_pair(mid + 1, -1));
      p--;
      int start = p->first;
      int id = p->second;
      int b = 0, k = 0;
      vector<int> vb, vk;
      for (auto it : el[id]) {
        printf("? %d %d\n", i, it);
        fflush(stdout);
        char c;
        scanf(" %c", &c);
        if (c == '>') {
          b++;
          vb.push_back(it);
        } else {
          k++;
          vk.push_back(it);
        }
      }
      if (b == el[id].size()) {
        l = start + el[id].size();
      } else if (k == el[id].size()) {
        r = start;
      } else {
        l = r = start + b;
        s.erase(p);

        el[pt] = vb;
        s.insert(make_pair(start, pt));
        pt++;

        el[pt] = vk;
        s.insert(make_pair(start + b, pt));
        pt++;
        break;
      }
    } 
    ev[i] = l * 2;
  }
  int now = 1;
  for (auto it : s) {
    for (auto j : el[it.second]) {
      od[j] = now;
      now += 2;
    }
  }
  answer();
  return 0;
}