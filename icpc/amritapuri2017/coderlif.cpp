#include <bits/stdc++.h>

using namespace std;

int a[55];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int sum = 0;
    bool bored = 0;
    for (int i = 0; i < 30; ++i) {
      scanf("%d", a+i);
      sum += a[i];
      if (i >= 6) sum -= a[i-6];
      if (sum >= 6)
        bored = 1;
    }
    puts(bored ? "#coderlifematters" : "#allcodersarefun");
  }
  return 0;
}