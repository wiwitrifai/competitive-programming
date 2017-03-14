#include <bits/stdc++.h>

using namespace std;

bool cek(char a, char b) {
	if (a == 'a')
		return b == '0' || b == '1';
	if (a == 'A')
		return b == '2' || b == '3';
	if (a == 'b')
		return b == '0' || b == '2';
	if (a == 'B')
		return b == '1' || b == '3';
}
bool cek(string a, int l, int r, string b) {
	int n = b.size();
	for (int i = 0; i < n; i++) {
		if (i + l >= r) return 1;
		if (!cek(a[i+l], b[i]))
			return 0;
	}
	return 1;
}
char to[256];
int dp[55][7], all[55];
void mark(string &s, int id, string p) {
	for (int i = 0; i < p.size(); i++) {
		if (id + i >= s.size())
			return;
		if (!cek(s[id+i], p[i]))
			s[id+i] = to[s[id+i]];
	}
}

class Softmatch {
public:
	int count(string s, vector <string> patterns) {
		to['A'] = 'a';
		to['a'] = 'A';
		to['B'] = 'b';
		to['b'] = 'B';
		memset(dp, 0, sizeof dp);
		memset(all, 0, sizeof all);
		int len = s.size(), n = patterns.size(), ans = 0;
		for (int i = len-1; i >= 0; i--) {
			all[i] = all[i+1];
			for (int j = 0; j < n; j++) {
				int r = i + patterns[j].size();
				if (r > len) continue;
				mark(s, i, patterns[j]);
				dp[i][j] = all[r];
				for (int k = 0; k < n; k++) {
					for (int z = i; z < r; z++)
						if (z + patterns[k].size() <= r) {
							if (cek(s, z, r, patterns[k]))
								dp[i][j]++;
						}
						else
							break;
				}
				for (int p = i; p < r; p++) {
					for (int q = 0; q < n; q++) {
						int r2 = p + patterns[q].size();
						if (r2 <= r || r2 > len) continue;
						if (!cek(s, p, r, patterns[q])) continue;
						mark(s, p, patterns[q]);
						int cur = dp[p][q];
						for (int k = 0; k < n; k++) {
							for (int z = i; z < p; z++)
								if (z + patterns[k].size() <= r2) {
									if (cek(s, z, r2, patterns[k]))
										cur++;
								}
						}
						dp[i][j] = max(dp[i][j], cur);
					}
				}
				ans = max(ans, dp[i][j]);
				all[i] = max(all[i], dp[i][j]);
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
		cout << "Testing Softmatch (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1489464796;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Softmatch _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "aaa";
				string patterns[] = {"03","21"};
				_expected = 2;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 1:
			{
				string S = "aba";
				string patterns[] = {"03","11"};
				_expected = 3;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 2:
			{
				string S = "bba";
				string patterns[] = {"00","00"};
				_expected = 4;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 3:
			{
				string S = "bbbbbb";
				string patterns[] = {"1110","011","100"};
				_expected = 3;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 4:
			{
				string S = "abbaa";
				string patterns[] = {"123"};
				_expected = 2;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 5:
			{
				string S = "aababbaab";
				string patterns[] = {"012","332","101", "0313"};
				_expected = 7;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 6:
			{
				string S = "bbababababbbaaaaaaaabbababbaaababab";
				string patterns[] = {"3230"};
				_expected = 13;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			case 7:
			{
				string S = "bbbbabbbabbbbbaabaabbbbbbbababaaababbbababaaaa";
				string patterns[] = {"2", "0021002"};
				_expected = 46;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}
			/*case 8:
			{
				string S = ;
				string patterns[] = ;
				_expected = ;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
