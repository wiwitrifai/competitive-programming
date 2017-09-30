/*

Apa salahku
Kau buat begini
Kau tarik ulur hatiku
Hingga sakit yang ku rasa

Apa memang ini yang kamu inginkan
Tak ada sedikitpun niat ‘tuk serius kepadaku

Katakan yang sebenarnya
Jangan mau tak mau seperti ini

Akhirnya kini aku mengerti
Apa yang ada di pikiranmu selama ini
Kau hanya ingin permainkan perasaanku
Tak ada hati tak ada cinta

Apa memang ini yang kamu inginkan
Tak ada sedikitpun niat ‘tuk serius kepadaku
Katakan yang sebenarnya
Jangan mau tak mau seperti ini

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    tot += n * a[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
    tot += n * a[i];
  }
  cout << tot << endl;
  return 0;
}