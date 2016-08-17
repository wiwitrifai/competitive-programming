#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  printf("%d\n", n);
  srand(0);
  for (int i = 0; i < n; i++)
    printf("%d ", rand() % (1<<14));

  printf("\n");
  return 0;
}