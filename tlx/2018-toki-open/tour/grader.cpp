#include "tour.h"

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int N;
  scanf("%d", &N);
  
  std::vector<std::string> S(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> S[i];
  }

  printf("%d\n", getShortestTour(N, S));
  return 0;
}
