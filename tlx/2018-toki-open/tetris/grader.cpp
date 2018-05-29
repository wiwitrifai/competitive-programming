#include "tetris.h"

#include <stdio.h>
#include <iostream>
#include <string>

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);
  std::string S;
  std::cin >> S;
  
  std::vector<int> ans = arrangeTetrominoes(N, S, Q);
  for (int i = 0; i < ans.size(); i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
