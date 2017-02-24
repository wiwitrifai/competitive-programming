#include <bits/stdc++.h>

using namespace std;

bool check(char s, char p) {
	switch (s) {
		case 'a':
			return p == '0' || p == '1';
		case 'A':
			return p == '2' || p == '3';
		case 'b':
			return p == '0' || p == '2';
		case 'B':
			return p == '1' || p == '3';
	}
}
int dp[N][6];

class Softmatch {
public:
	int count(string S, vector <string> patterns) {
		int n = S.size(), m = patterns.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i + patterns[j].size() > n)
					continue;
				int cnt = 0;
				for (int k = 0; k < m; k++) {
					if (patterns[k].size() > patterns[j].size()) continue;
					bool ok = 1;
					for (int z = 0; z < patterns[k].size(); z++)
						if (check(S[i+z], patterns[j][z]) != check(S[i+z], patterns[k][z])) {
							ok = 0;
							break;
						}
					cnt += ok;
				}
				for (int x = 0; x < i; ++) {
					for (int y = 0; y < m; y++) {
						bool ok = 1;
						for (int z = 0; z < patterns[k].size(); z++)
								if (x+z >= i && ) {
									ok = 0;
									break;
								}
									
					}
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
		cout << "Testing Softmatch (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487701001;
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
			/*case 6:
			{
				string S = ;
				string patterns[] = ;
				_expected = ;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string S = ;
				string patterns[] = ;
				_expected = ;
				_received = _obj.count(S, vector <string>(patterns, patterns+sizeof(patterns)/sizeof(string))); break;
			}*/
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
