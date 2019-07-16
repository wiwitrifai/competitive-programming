#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int grund[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  // // for (int k = 1; k <= 100; ++k) 
  // {
  //   grund[0] = 0;
  //   for (int i = 1; i <= n; ++i) {
  //     grund[i] = 0;
  //     set<int> st;
  //     for (int j = 0; j < i; ++j) {
  //       for (int z = j; z < i; ++z) {
  //         if (j+z < i-k) continue;
  //         if (j+z >= i) continue;
  //         st.insert(grund[j]^grund[z]);
  //         // cerr << j << " " << z << " " << (grund[j]^grund[z]) << endl;
  //       }
  //     }
  //     for (int x : st)
  //       grund[i] += grund[i] == x;
  //     if (grund[i] == 0)
  //       printf("%d %d\n", i, grund[i]);
  //   }

  // }
  if (n == 0)
    puts("Austin");
  else if (k == 1)
    puts((n & 1) ? "Adrien" : "Austin");
  else
    puts("Adrien");
  return 0;
}