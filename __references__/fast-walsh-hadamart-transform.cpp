// Walsh-Hadamart Matrix:
// xor : 1/sqrt(2) * {{1, 1}, {1, -1}}, inverse : 1/sqrt(2) * {{1, 1}, {1, -1}}
// and : {{0, 1}, {1, 1}}, inverse : {{-1, 1}, {1, 0}}
// or : {{1, 1}, {1, 0}}, inverse : ?
poly FWHT(poly P, bool inverse) { // example: xor
  for (len = 1; 2 * len <= degree(P); len <<= 1) {
    for (i = 0; i < degree(P); i += 2 * len) {
      for (j = 0; j < len; j++) {
        u = P[i + j];
        v = P[i + len + j];
        if (!inverse) {
          P[i + j] = u + v; // xor's matrix
          P[i + len + j] = u - v;  // xor's matrix
        }
        else {
          P[i + j] = u + v; // use inverse matrix here
          P[i + len + j] = u - v;  // use inverse matrix here
        }
      }
    }
  }
  if (inverse) { 
    for (i = 0; i < degree(P); i++)
      P[i] = P[i] / degree(P); // this for xor only
  }
  return P;
}