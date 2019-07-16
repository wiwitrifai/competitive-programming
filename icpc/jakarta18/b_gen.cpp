#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 10000, q = n;
  srand(time(0));
  printf("%d\n", n);
  for (int i = 2; i <= n; ++i){
    int u = (rand() % (i-1)) + 1;
    printf("%d %d\n", i, u);
  }
  vector<int> ada, tidak;
  for (int i = 1; i <= n; ++i)
    ada.push_back(i);
  printf("%d\n", q);
  while (q--) {
    int t = (rand() % 3) + 1;
    while (1) {
      if ((t == 1 || t == 3) && ada.size() > 0)
        break;
      if (t == 2 && tidak.size() > 0)
        break;
      t = (rand() % 2) + 1;
    }
    if (t == 1) {
      int id = rand() % ada.size();
      swap(ada[id], ada.back());
      printf("1 %d\n", ada.back());
      tidak.push_back(ada.back());
      ada.pop_back();
    }
    else if (t == 2) {
      int id = rand() % tidak.size();
      swap(tidak[id], tidak.back());
      printf("2 %d\n", tidak.back());
      ada.push_back(tidak.back());
      tidak.pop_back();
    }
    else {
      int id = rand() % ada.size();
      printf("3 %d %d\n", ada[id], rand() % 360);
    }
  }
  return 0;
}