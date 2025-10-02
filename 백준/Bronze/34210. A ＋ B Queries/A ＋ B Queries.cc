#include "aplusb.h"
std::vector<int> C,D;

void initialize(std::vector<int> A, std::vector<int> B) {
  C=A;
    D=B;
  return;
}

int answer_question(int i, int j) {
  return C[i]+D[j];
}
