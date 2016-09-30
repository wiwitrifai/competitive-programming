#include <bits/stdc++.h>

using namespace std;

const string s[][4] = {
  "cs", "Kamen", "Nuzky", "Papir",
  "en", "Rock", "Scissors", "Paper",
  "fr", "Pierre", "Ciseaux", "Feuille",
  "de", "Stein", "Schere", "Papier",
  "hu", "Ko", "Ollo", "Papir",
  "it", "Sasso", "Forbice", "Carta",
  "jp", "Guu", "Choki", "Paa",
  "pl", "Kamien", "Nozyce", "Papier",
  "es", "Piedra", "Tijera", "Papel"
};
map< string, map< string, int > > mp;

int match[4][4];

int main() {  
  for (int i = 0; i < 9; i++) {
    for (int j = 1; j < 4; j++)
      mp[s[i][0]][s[i][j]] = j;
  }
  mp["hu"]["Koe"] = 1;
  mp["hu"]["Olloo"] = 2;
  mp["it"]["Roccia"] = 1;
  mp["it"]["Rete"] = 3;
  // for (auto it : mp) {
  //   cerr << it.first << endl;
  //   for (auto it2 : it.second) {
  //     cerr << " " <<  it2.first << " " << it2.second << endl;
  //   }
  // }
  for (int i = 1; i < 4; i++) {
    match[i][i] = 0;
    int nx = (i % 3) + 1;
    match[i][nx] = -1;
    int bef = (i - 1);
    if (bef == 0)
      bef = 3;
    match[i][bef] = 1;
  }
  string st = "-";
  int nogame = 1;
  while (st[0] != '.') {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int p1, p2;
    p1 = p2 = 0;
    cin >> st;
    while (st[0] != '-' && st[0] != '.') {
      int v1 = mp[a][st];
      cin >> st;
      int v2 = mp[c][st];
      if (match[v1][v2] < 0)
        p1++;
      else if (match[v1][v2] > 0)
        p2++;
      cin >> st;
    }
    cout << "Game #" << nogame << ":\n";
    if (p1 == 1)
      cout << b << ": " << p1 << " point\n";
    else
      cout << b << ": " << p1 << " points\n";
    if (p2 == 1)
      cout << d << ": " << p2 << " point\n";
    else
      cout << d << ": " << p2 << " points\n";

    if (p1 > p2)
      cout << "WINNER: " << b << endl;
    else if (p1 < p2)
      cout << "WINNER: " << d << endl;
    else
      cout << "TIED GAME" << endl;
    cout << endl;
    nogame++;
  }
  return 0;
}