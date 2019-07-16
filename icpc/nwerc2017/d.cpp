#include <bits/stdc++.h>

using namespace std;

string ss[100004];
int n, m;

map<string, vector<tuple<string, bool> > > d;
vector<string> translation;

int main(int argc, char const *argv[])
{
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> ss[i];
  }

  cin >> m;

  for (int i = 0; i < m; ++i)
  {
    string a, b, c;
    cin >> a >> b >> c;
    d[a].push_back(make_tuple(b, c == "correct"));
  }

  long long all = 1, correct = 1;
  bool one = true;
  for (int i = 0; i < n; ++i)
  {
    int locCorr = 0;
    int locAll = 0;
    string s = ss[i];

    for(auto possible: d[s])
    {
      string eng;
      bool corr;

      tie(eng, corr) = possible;
      one &= corr;

      if (d[s].size() == 1)
        translation.push_back(eng);

      locCorr += corr;
      locAll++;
    }
    all *= locAll;
    correct *= locCorr;
  }
  if (all < 2) {
    for (string s: translation)
    {
      cout << s << " ";
    }
    cout << (one ? "\ncorrect" : "\nincorrect");
  } else {
    cout << correct << " correct\n";
    cout << all - correct << " incorrect\n";
  }
  return 0;
}