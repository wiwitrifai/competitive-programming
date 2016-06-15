long long x, y, d; // ax + by = d
void extendedEuclidean(long long a, long long b) {
  if(b == 0) { x = 1; y = 0; d = a; return; } 
  extendedEuclidean(b, a % b); 
  long long xx, yy;
  xx = y;
  yy = x - (a/b)*y;
  x = xx; y = yy;
}