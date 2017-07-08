#include <bits/stdc++.h>

using namespace std;

const int N = 55;

vector< int > g[N];

int n, mark[N], match[N], matched[N];
string get(string ss, int len) {
	int n = ss.size();
	string ans = ss.substr(0, len);
	for (int i = 0; i + len <= n; i++) {
		string cur = ss.substr(i, len);
		if (cur > ans)
			ans = cur;
	}
	return ans;
}

bool can(string ss, string s) {
	return ss.find(s) != string::npos;
}

bool dfs(int v){
  if(mark[v])
    return false;
  mark[v] = true;
  for(auto &u : g[v])
    if(match[u] == -1 or dfs(match[u]))
      return matched[v] = u, match[u] = v, true;
  return false;
}

int mbcm() {
	memset(matched, -1, sizeof matched);
	memset(match, -1, sizeof match);
	while(true){
    memset(mark, false, sizeof mark);
    bool fnd = false;
    for(int i = 0;i < n;i ++) if(matched[i] == -1 && !mark[i])
      fnd |= dfs(i);
    if(!fnd)
      break;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  	ans += matched[i] != -1;
  return ans;
}


class DengklekGaneshAndChains {
public:
	string getBestChains(vector <string> chains, vector <int> lengths) {
		::n = lengths.size();
		int n = chains.size(), m = lengths.size();
		string ans = "";
		for (int i = 0; i < n; i++)
			chains[i] = chains[i] + chains[i];
		vector<bool> used(n, false);
		for (int i = 0; i < m; i++) {
			vector< string > vs;
			for (int j = 0; j < n; j++) {
				vs.push_back(get(chains[j], lengths[i]));
			}
			sort(vs.begin(), vs.end());
			reverse(vs.begin(), vs.end());
			for (string s : vs) {
				g[i].clear();
				for (int j = 0; j < n; j++) {
					if (can(chains[j], s))
						g[i].push_back(j);
				}
				if (mbcm() == i+1) {
					ans += s;
					break;
				}
			}
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing DengklekGaneshAndChains (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499529621;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DengklekGaneshAndChains _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chains[] = {"topc", "oder", "open", "twob"};
				int lengths[] = {2, 1, 3};
				_expected = "wotrod";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 1:
			{
				string chains[] = {"ssh", "she", "see", "sea"};
				int lengths[] = {2, 3, 2, 3};
				_expected = "ssshesesee";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 2:
			{
				string chains[] = {"wri", "ter", "who", "are", "you"};
				int lengths[] = {3};
				_expected = "you";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 3:
			{
				string chains[] = {"harus", "imfyo"};
				int lengths[] = {5, 5};
				_expected = "yoimfushar";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			/*case 4:
			{
				string chains[] = ;
				int lengths[] = ;
				_expected = ;
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				string chains[] = ;
				int lengths[] = ;
				_expected = ;
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string chains[] = ;
				int lengths[] = ;
				_expected = ;
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
