#include "assistant.h"
#include "magician.h"

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

bool isClueGood(int N, int clue, const std::vector<int> &cards) {
  for (int i = 0; i < cards.size(); ++i) {
    if (cards[i] == clue) {
      return false;
    }
  }
  if (clue < 1 || clue > N) {
    return false;
  }
  return true;
}

int main() {
  const int SEED = 20172017; // this value might be
  // different with the grader in the grading server.
  srand(SEED);
  int N, K, Q;
  scanf("%d %d %d", &N, &K, &Q);
  std::vector<std::vector<int> > cards(Q);
  for (int i = 0; i < Q; ++i) {
    cards[i].resize(K);
    for (int j = 0; j < K; ++j) {
      scanf("%d", &cards[i][j]);
    }
  }
  std::vector<int> order(Q);
  for (int i = 0; i < Q; ++i) {
    order[i] = i;
  }
  random_shuffle(order.begin(), order.end());

  initMagician(N, K);
  initAssistant(N, K);
  for (int i = 0; i < Q; ++i) {
    int clue = giveClue(cards[order[i]]);
    if (!isClueGood(N, clue, cards[order[i]])) {
      printf("WA\n");
      return 0;
    }
    cards[order[i]].push_back(clue);
    sort(cards[order[i]].begin(), cards[order[i]].end());
  }
  for (int i = 0; i < Q; ++i) {
    std::vector<int> ans = findOriginalCards(cards[i]);
    for (int j = 0; j < ans.size(); ++j) {
      printf("%d", ans[j]);
      if (j < ans.size() - 1) {
        printf(" ");
      } else {
        printf("\n");
      }
    }
  }
  return 0;
}
